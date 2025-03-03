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
    BinarySearchTree() { root = nullptr; }

    // ---------------------------------------------------
    //  Below is a helper function used by the destructor
    //  Deletes all nodes in BST
    //  Similar to DFS PostOrder in Tree Traversal section
    // ---------------------------------------------------
    void destroy(Node* currentNode) {
        if (currentNode == nullptr) return;
        if (currentNode->left) destroy(currentNode->left);
        if (currentNode->right) destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    Node* getRoot() {
        return root;
    }

    bool insert(int value);

    bool contains(int value);
};


#endif //DATA_ESTRUCTURE_C_BINARYSEARCHTREE_H
