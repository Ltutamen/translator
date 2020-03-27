//
// Created by myself on 3/24/20.
//

#include "SingleElm.h"
#include <map>

std::map<std::string, SingleElm*> SingleElm::singleElmPool = {
    {std::string("="), new SingleElm(EQUAL, "=")},
    {std::string(","), new SingleElm(COMA, ",")},
    {std::string(";"), new SingleElm(DOT_COMA, ";")},
    {std::string("\\"), new SingleElm(BACK_SLASH, "\\")},
    {std::string("*"), new SingleElm(MULT, "*")},
    {std::string(">"), new SingleElm(MORE, ">")},
    {std::string("<"), new SingleElm(LESS, "<")}
};

SingleElm* SingleElm::getSingleElm(std::string text) {
    return singleElmPool.find(text)->second;
}

SingleElm::SingleElm(SingleElm::SingleElmType ttype, std::string text) : Lexem(text) {
    this->type = ttype;

}

std::string *SingleElm::toString() {
    std::string* result = new std::string();
    result->append("SIND:");
    result->append("<");
    result->append(this->name);
    result->append(">");
    return result;
}

LexemTypes SingleElm::getType() {
    return DEFINED_VAR;
}

