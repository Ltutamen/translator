//
// Created by myself on 4/15/20.
//

#ifndef TRANSLATOR_TREENODE_H
#define TRANSLATOR_TREENODE_H

#include <list>
#include "../../lexer/Text/Lexem.h"

class TreeNode {
public:
    std::list<TreeNode*> getKids();
    Lexem* getValue();
    void addKid(TreeNode* node);

    TreeNode(Lexem *value);

private:
    Lexem* value;
    std::list<TreeNode*> kids;
};


#endif //TRANSLATOR_TREENODE_H
