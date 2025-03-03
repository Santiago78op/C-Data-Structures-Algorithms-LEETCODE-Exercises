//
// Created by 72358 on 3/03/2025.
//

#ifndef DATA_ESTRUCTURE_C_BINARYSEARCHTREE_H
#define DATA_ESTRUCTURE_C_BINARYSEARCHTREE_H


#include "Node.h"

class BinarySearchTree {
private:
    Node *root;

public:
    BinarySearchTree(int value);

    bool insert(int value);

    bool contains(int value);
};


#endif //DATA_ESTRUCTURE_C_BINARYSEARCHTREE_H
