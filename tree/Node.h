//
// Created by 72358 on 3/03/2025.
//

#ifndef DATA_ESTRUCTURE_C_NODE_H
#define DATA_ESTRUCTURE_C_NODE_H


class Node {
public:
    int value;
    Node *left;
    Node *right;

    explicit Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};


#endif //DATA_ESTRUCTURE_C_NODE_H
