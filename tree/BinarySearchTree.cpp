//
// Created by 72358 on 3/03/2025.
//

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(int value) {
    root = nullptr;
}

bool BinarySearchTree::insert(int value) {
    // Crear un nuevo nodo
    Node* newNode = new Node(value);
    // Validar si el arbol esta vacio
    if (root == nullptr){
        root = newNode;
        return true;
    }

    // Sino se encuentra vacio
    // Crear un nodo temporal
    Node* temp = root;
    // loop para recorrer el arbol
    while (true){
        // Validar si el valor del nuevo nodo es igual al valor del nodo temporal
        if (newNode->value == temp->value) return false;
        // Validar si el valor del nuevo nodo es menor al valor del nodo temporal
        if (newNode->value < temp->value){
            // Validar si el nodo temporal tiene un hijo izquierdo
            if (temp->left == nullptr){
                // Asignar el nuevo nodo al hijo izquierdo del nodo temporal
                temp->left = newNode;
                return true;
            }
            // Asignar el hijo izquierdo del nodo temporal al nodo temporal
            temp = temp->left;
        } else {
            // Validar si el nodo temporal tiene un hijo derecho
            if (temp->right == nullptr){
                // Asignar el nuevo nodo al hijo derecho del nodo temporal
                temp->right = newNode;
                return true;
            }
            // Asignar el hijo derecho del nodo temporal al nodo temporal
            temp = temp->right;
        }
    }
}

bool BinarySearchTree::contains(int value) {
    // Crear un nodo temporal
    Node* temp = root;
    // Recorrer el nodo temporal
    while(temp){
        // Validar si el valor es menor al valor del nodo temporal
        if (value < temp->value){
            // Asignar el hijo izquierdo del nodo temporal al nodo temporal
            temp = temp->left;
        } else if (value > temp->value){
            // Asignar el hijo derecho del nodo temporal al nodo temporal
            temp = temp->right;
        } else {
            return true;
        }
    }

    return false;
}
