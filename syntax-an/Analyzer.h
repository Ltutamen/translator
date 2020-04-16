//
// Created by myself on 4/15/20.
//

#ifndef TRANSLATOR_ANALYZER_H
#define TRANSLATOR_ANALYZER_H


#include "tree/TreeNode.h"
#include "../lexer/Text/Lexem.h"
#include "horrors/Horrible.h"

class Analyzer {
public:
    Analyzer();

    TreeNode* analyze(std::stack<Lexem*> lexems);

private:
    std::set<PredicateFunPair> predicateProcedures;

};


#endif //TRANSLATOR_ANALYZER_H
