#include <map>
#include <string>
#include <any>
#include <iostream>
#include <variant>
#include <stdexcept>
#include <functional>

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
        try {
        std::cout << "score = " << env.find("score") << '\n';
        std::cout << "name = " << env.find("name") << '\n';
        std::cout << "pi = " << env.find("pi") << '\n';

        } catch (const std::exception& ex) {
            std::cerr << "Error al buscar simbolo: " << ex.what() << '\n';
        }

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

// para mejorar el codigo como se pide en el ejercicio 8, se puede incluir #include <functional> y cambiar el tipo de dato de la variable symbols a std::map<std::string, std::function<std::variant<int, double, std::string>()>> symbols;
// En el metodo insert se puede cambiar por symbols.emplace(name, value); y en el metodo find se puede cambiar por return it->second();
// En el metodo print se puede cambiar por std::cout << name << " = " << value() << '\n';
// En el metodo exists se puede cambiar por return symbols.find(name) != symbols.end();
// En el metodo remove se puede cambiar por symbols.erase(name); y en el metodo main se puede cambiar por env.insert("score", [] { return 100; }); env.insert("name", [] { return "Ruben"; }); env.insert("pi", [] { return 3.1416; });
// En el metodo main se puede cambiar por std::cout << "score = " << env.find("score") << '\n'; std::cout << "name = " << env.find("name") << '\n'; std::cout << "pi = " << env.find("pi") << '\n';
// En el metodo main se puede cambiar por std::cout << "score = " << env.exists("score") << '\n'; std::cout << "name = " << env.exists("name") << '\n'; std::cout << "pi = " << env.exists("pi") << '\n';

