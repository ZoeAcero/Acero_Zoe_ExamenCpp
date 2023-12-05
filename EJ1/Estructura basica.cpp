#include <map>
#include <string>
#include <any>
#include <iostream>

class Environment {
public:
    // Constructor
    Environment() {}

    void insert(const std::string& name, const std::variant<int, double, std::string>& value) {
        auto result = symbols.emplace(name, value);
        if (!result.second) {
            throw std::invalid_argument("Símbolo duplicado: " + name);
        }
    }





