//
// Created by myself on 3/24/20.
//

#ifndef TRANSLATOR_SINGLEELM_H
#define TRANSLATOR_SINGLEELM_H

#include "Lexem.h"

class SingleElm : public Lexem {
public:
    typedef enum {
        EQUAL,
        COMA,
        DOT_COMA,
        BACK_SLASH,
        MULT,
        MORE,
        LESS
    } SingleElmType;

    static SingleElm* getSingleElm(std::string text);

    SingleElm(SingleElmType, std::string);

    static std::map<std::string, SingleElm*> singleElmPool;

    std::string *toString() override;

    LexemTypes getType() override;

private:

    SingleElmType type;
};

#endif //TRANSLATOR_SINGLEELM_H
