//
// Created by myself on 2/16/20.
//

#ifndef TRANSLATOR_VARIABLE_H
#define TRANSLATOR_VARIABLE_H

#include <utility>
#include "Lexem.h"

class Variable : public Lexem {
public:
    Variable(std::string name) : Lexem(std::move(name)) {}

    std::string* toString() override {
        auto* result = new std::string("VARB: ");
        result->append(this -> name);
        return result;
    }

    LexemTypes getType() {
        return LexemTypes::DEFINED_VAR;
    }
};


#endif //TRANSLATOR_VARIABLE_H
