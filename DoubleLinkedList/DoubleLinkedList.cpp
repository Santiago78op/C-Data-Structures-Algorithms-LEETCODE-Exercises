//
// Created by 72358 on 6/02/2025.
//

#include <iostream>
#include "DoubleLinkedList.h"

using namespace std; // Para evitar escribir std::cout, std::cin, std::endl

/**
 * Constructor que inicializa el nodo con un valor dado.
 * @param value Valor del nodo a almacenar
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se crea un nodo con el valor dado
 * @exception Ninguna
 * @test_cases
 * Node* node = new Node(5);
 */
Node::Node(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

/**
 * Constructor que inicializa la lista con un valor dado.
 * @param value Valor del nodo inicial
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se crea una lista con un nodo inicial
 * @exception Ninguna
 * @test_cases
 * DoubleLinkedList myDoubleLinkedList = *new DoubleLinkedList(4);
 */
DoubleLinkedList::DoubleLinkedList(int value) {
    Node *newNode = new Node(value);

    head = newNode;
    tail = newNode;
    length = 1;
}

/**
 * Destructor que libera la memoria de los nodos de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se liberan los nodos de la lista
 * @exception Ninguna
 * @test_cases
 * delete myDoubleLinkedList;
 */
DoubleLinkedList::~DoubleLinkedList() {
    Node *temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

Node *DoubleLinkedList::getHead() const {
    return head;
}

void DoubleLinkedList::setHead(Node *head) {
    DoubleLinkedList::head = head;
}

Node *DoubleLinkedList::getTail() const {
    return tail;
}

void DoubleLinkedList::setTail(Node *tail) {
    DoubleLinkedList::tail = tail;
}

int DoubleLinkedList::getLength() const {
    return length;
}

void DoubleLinkedList::setLength(int length) {
    DoubleLinkedList::length = length;
}

void DoubleLinkedList::printList() {
    Node *temp = head;

    if (temp == nullptr) {
        cout << "Empty";
    } else {
        while (temp) {
            cout << " Valor: " << temp->value;
            temp = temp->next;
        }
    }
}

/**
 * Método que imprime los valores de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.printAll();
 */
void DoubleLinkedList::makeEmpty() {
    Node *temp = head;

    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }

    tail = nullptr;
    length = 0;

    cout << endl << "Lista Limpia!!" << endl;
}

/**
 * Método que agrega un valor al final de la lista.
 * @param value Valor a agregar
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se agrega un valor al final de la lista
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.append(5);
 */
void DoubleLinkedList::append(int value) {
    Node *newNode = new Node(value);

    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    length++;
}

/**
 * Método que elimina el último nodo de la lista.
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se elimina el último nodo de la lista
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.deleteLast();
 */
void DoubleLinkedList::deleteLast() {
    if (length == 0) return;

    Node *temp = tail;

    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    length--;
}

void DoubleLinkedList::prepend(int value) {
    Node* newNode = new Node(value);

    if(length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    length++;
}
