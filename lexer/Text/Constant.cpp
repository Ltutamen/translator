//
// Created by myself on 2/16/20.
//

#include "Constant.h"

#include <utility>

std::string* Constant::toString() {
    std::string* result = new std::string();
    result->append("CONS:");
    result->append(LexemType::names.find(type)->second);
    result->append("<");
    result->append(this->name);
    result->append(">");
    result->append(constantPositionToString(this->constantPosition));

    return result;
}

LexemTypes Constant::getType() {
    return this->type;
}

const ConstantPosition &Constant::getConstantPosition() const {
    return constantPosition;
}

std::string Constant::constantPositionToString(ConstantPosition position) {
    std::string result;
    result.append("from ");
    result.append(std::to_string(constant_start_line(position)));
    result.append(":");
    result.append(std::to_string(constant_start_pos(position)));
    result.append(" ");
    result.append(std::to_string(constant_end_line(position)));
    result.append(":");
    result.append(std::to_string(constant_end_pos(position)));
    return std::string();
}

