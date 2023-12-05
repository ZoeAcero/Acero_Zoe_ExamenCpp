#include <map>
#include <string>
#include <any>
#include <iostream>
#include <variant>
#include <stdexcept>

class Environment {
public:
    // Constructor
    Environment() {}

    //insertar simbolo en el entorno
    void insert(const std::string& name, const std::variant<int, double, std::string>& value) {
        auto result = symbols.emplace(name, value);
        if (!result.second) {
            throw std::invalid_argument("Símbolo duplicado: " + name);
        }
    }

    //buscar simbolo en el entorno
    std::variant<int, double, std::string> find(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            throw std::invalid_argument("Símbolo no encontrado: " + name);
        }
    }


//verificar si el simbolo existe en el entorno
bool exists(const std::string& name) const {
    return symbols.find(name) != symbols.end();
}

//eliminar un simbolo del entorno
void remove(const std::string& name) {
    symbols.erase(name);
}

//imprimir el entorno
void print() const {
    for (const auto& [name, value] : symbols) {
        std::cout << name << " = " << value << '\n';
    }
}

private:
    std::map<std::string, std::variant<int, double, std::string>> symbols;
};

int main() {
    try {
        //crear instancia en clase Environment
        Environment env;

        //insertar simbolos con el metodo insert
        env.insert("score", 100);
        env.insert("name", "Ruben");
        env.insert("pi", 3.1416);

       //imprimir simbolos en la tabla
        env.print();

        //buscar simbolo en la tabla
        std::cout << "score = " << env.find("score") << '\n';
        std::cout << "name = " << env.find("name") << '\n';
        std::cout << "pi = " << env.find("pi") << '\n';

        //eliminar simbolo de la tabla
        env.remove("score");
        env.print();

        //verificar si el simbolo existe en la tabla
        std::cout << "score = " << env.exists("score") << '\n';
        std::cout << "name = " << env.exists("name") << '\n';
        std::cout << "pi = " << env.exists("pi") << '\n';
    }

    catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}



