//
// Created by myself on 4/15/20.
//

#include <stack>
#include <iostream>
#include "Analyzer.h"
#include "../lexer/Text/Lexem.h"
#include "../lexer/Text/Constant.h"

TreeNode* Analyzer::analyze(std::stack<Lexem *> lexems) {
    TreeNode* root = new TreeNode(new Constant("ROOT", LexemTypes::KEYWORD, ConstantPosition(0, 0, 0, 0)));

    while (!lexems.empty()) {
        std::cout << lexems.top()->toString() << '\n' ;
        lexems.pop();
    }


    return nullptr;
}

Analyzer::Analyzer() {

}

/*
Analyzer::Analyzer() {
    predicateProcedures.insert(PredicateFunPair(
            FunPredicate([](Lexem* lexem) -> bool {return lexem->getType() == LexemTypes::KEYWORD && lexem->name == "program";} ),
            LexFunction([](std::stack<Lexem*> stack) -> TreeNode* {
                TreeNode* result = new TreeNode(stack.pop());


            }
})));
 */

TreeNode* process(Lexem* lexem) {

}
