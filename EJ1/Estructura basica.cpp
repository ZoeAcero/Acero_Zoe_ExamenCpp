#include <map>
#include <string>
#include <any>
#include <iostream>

class Environment {
public:
    // Constructor
    Environment() {}

    // agregamos simbolo
    void addSymbol(const std::string& name, const std::any& value) {
        symbols[name] = value;
    }

    //verificar si esta el simbolo
bool hasSymbol(const std::string& name) const {
        return symbols.find(name) != symbols.end();
    }

    //obtenemos el valor del simbolo
    std::any getSymbol(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        } else {
            // Devolver algo por defecto si el símbolo no está presente
            return std::any();
        }
    }

    //imprimir todos los simbolos
    void printSymbols() const {
        for (const auto& pair : symbols) {
            std::cout << "Symbol: " << pair.first << ", Value: ";
            try {
                std::cout << std::any_cast<const char*>(pair.second) << std::endl;
            } catch (const std::bad_any_cast&) {
                std::cerr << "Type mismatch in symbol: " << pair.first << std::endl;
            }
        }
    }

    bool insert(const std::string& name, const std::any& value) {
        auto result = symbols.emplace(name, value);
        return result.second;  // devuelve true si se agrego correctamente
    }

private:
    std::map<std::string, std::any> symbols;
};

int main() {
    Environment env;
    env.addSymbol("x", 10);
    env.addSymbol("message", std::string("Clase de programacion"));

    bool success = env.insert("x", 100);

    env.printSymbols();

    std::cout << "x = " << std::any_cast<int>(env.getSymbol("x")) << std::endl;
    std::cout << "y = " << std::any_cast<int>(env.getSymbol("y")) << std::endl;
    std::cout << "z = " << std::any_cast<int>(env.getSymbol("z")) << std::endl;

    return 0;
}



