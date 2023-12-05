#include <map>
#include <string>
#include <any>
#include <iostream>

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
        if (it == symbols.end()) {
            throw std::invalid_argument("Símbolo no encontrado: " + name);
        }
        return it->second;
    }
    else {
        throw std::invalid_argument("Símbolo no encontrado: " + name);
    }
}





