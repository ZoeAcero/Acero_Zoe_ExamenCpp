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
        int symbols;
        symbols[name] = value;
    }

    //verificar si esta el simbolo
bool hasSymbol(const std::string& name) const {
        return symbols.find(name) != symbols.end();
    }

    //obtenemos el valor del simbolo
    


