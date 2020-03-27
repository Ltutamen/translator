//
// Created by myself on 2/16/20.
//

#ifndef TRANSLATOR_LEXEM_H
#define TRANSLATOR_LEXEM_H

#include <string>
#include <map>
#include <set>
#include <utility>

typedef enum {
    FORBIDDEN,
    LETTER,
    DIGIT,
    SINGLED_OP,
    SINGLED_DIV,
    MULTISIM_DIV,
    WHITESPACE,
    CTCount = 6
} CharacterTypes;
class CharacterType {
public:
    CharacterType() {
        names = {{FORBIDDEN, "forbidden"},
                 {LETTER, "letter"},
                 {DIGIT, "digit"},
                 {SINGLED_OP, "singleCh-div"},
                 {MULTISIM_DIV, "multiCh-div"},
                 {SINGLED_OP, "single-op"},
                 {WHITESPACE, "whitespace"} };

    }

    static std::map<CharacterTypes, std::string> names;
};


//  todo incapsulate into TableType class
typedef enum {
    CONSTANT_VAR,
    UNSIGNED,
    OPERAND,
    DEFINED_VAR,
    COMMENT,
    KEYWORD,
    LTCount = 6
} LexemTypes;
class LexemType {
public:
    static std::map<LexemTypes, std::string> names;
};

class Lexem {
public:
    std::string name;

    Lexem(std::string name) : name(std::move(name)) {}

    bool operator<(const Lexem& other) const {
        return name < other.name;
    }

    virtual std::string* toString() = 0;
    virtual LexemTypes getType() = 0;

};




#endif //TRANSLATOR_LEXEM_H
