//
// Created by myself on 4/15/20.
//

#include <vector>
#include "TreeNode.h"

std::list<TreeNode *> TreeNode::getKids() {
    return this->kids;
}

void TreeNode::addKid(TreeNode* node) {
    this->kids.push_back(node);
}

TreeNode::TreeNode(Lexem *value) : value(value) {}

Lexem *TreeNode::getValue() {
    return this->value;
}


