//
// Created by myself on 4/16/20.
//

#ifndef TRANSLATOR_HORRIBLE_H
#define TRANSLATOR_HORRIBLE_H
//  c++ is horrible language. To make simple type of predicate and some function, I have to write all this garbage!
//  in java it wold take like 15 minutes

#include <functional>
#include <stack>
#include "../../lexer/Text/Lexem.h"
#include "../tree/TreeNode.h"

class FunPredicate {
public:
    const std::function<bool(Lexem*)> func;

    FunPredicate(const std::function<bool(Lexem *)> &func) : func(func) {}
};

//  recursive fun takes stack of element and returns tree of them
class LexFunction {
public:
    const std::function<TreeNode* (std::stack<Lexem*>)> func;

    LexFunction(const std::function<TreeNode *(std::stack<Lexem *>)> &func) : func(func) {}

};

class PredicateFunPair {
public:
    const FunPredicate predicate;
    const LexFunction function;

    PredicateFunPair(const FunPredicate &predicate, const LexFunction &function)
    : predicate(predicate),
    function(function) {}
};

#endif //TRANSLATOR_HORRIBLE_H
