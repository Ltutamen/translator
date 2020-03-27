//
// Created by myself on 2/16/20.
//

#ifndef TRANSLATOR_CONSTANT_H
#define TRANSLATOR_CONSTANT_H


#include <utility>
#include <tuple>
#include <cstring>

#include "../Lexer.h"
#include "Lexem.h"

//   start_line, start_pos, end_line, end_pos
typedef std::tuple<size_t, size_t, size_t, size_t> ConstantPosition;
//  todo refactor
#define constant_start_line(position) (std::get<0>(position))
#define constant_start_pos(position) (std::get<1>(position))
#define constant_end_line(position) (std::get<2>(position))
#define constant_end_pos(position) (std::get<3>(position))

class Constant : public Lexem {
public:
    Constant( std::string basicString, LexemTypes param, ConstantPosition position)
    : Lexem(std::move(basicString)), constantPosition(std::move(position)) {
        this->type = param;
    }

    Constant(std::string basicString, ConstantPosition position, std::set<Lexem*> constants) : Lexem(std::move(basicString)), constantPosition(std::move(position)) {
        for(auto it : constants) {
            if(basicString == name) {
                type = it->getType();
            }
        }
    }

    std::string* toString() override;
    const ConstantPosition &getConstantPosition() const;
    static std::string constantPositionToString(ConstantPosition position);

    LexemTypes getType();

private:
    LexemTypes type;
    ConstantPosition constantPosition;

};


#endif //TRANSLATOR_CONSTANT_H
