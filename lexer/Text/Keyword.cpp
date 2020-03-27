//
// Created by myself on 3/27/20.
//

#include "Keyword.h"

#include <utility>

std::string *Keyword::toString() {
    auto* result = new std::string();
    result->append("KVRD:");
    result->append(name);
    return result;
}

LexemTypes Keyword::getType() {
    return KEYWORD;
}

Keyword::Keyword(const std::string &name) : Lexem(name) {}
