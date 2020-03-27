//
// Created by myself on 3/27/20.
//

#ifndef TRANSLATOR_KEYWORD_H
#define TRANSLATOR_KEYWORD_H


#include "Lexem.h"

class Keyword : public Lexem {
public:
    Keyword(const std::string &name);

    std::string *toString() override;

    LexemTypes getType() override;

private:

};


#endif //TRANSLATOR_KEYWORD_H
