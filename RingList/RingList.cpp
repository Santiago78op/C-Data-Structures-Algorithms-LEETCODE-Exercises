//
// Created by 72358 on 14/02/2025.
//

#include <iostream>
#include "RingList.h"
using namespace std;

/*
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
NodeRing::NodeRing(int value) {
    this->value = value;
    next = nullptr;
}

/*
 * Constructor que inicializa la lista con un valor dado.
 * @param value Valor del nodo inicial
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se crea una lista con un nodo inicial
 * @exception Ninguna
 * @test_cases
 * RingList myRingList = *new RingList(4);
 */
RingList::RingList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

/**
 * Destructor que libera la memoria de los nodos de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se liberan los nodos de la lista
 * @exception Ninguna
 * @test_cases
 * delete myRingList;
 */
RingList::~RingList() {
    NodeRing *temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

NodeRing *RingList::getHead() const {
    return head;
}

void RingList::setHead(NodeRing *head) {
    RingList::head = head;
}

NodeRing *RingList::getTail() const {
    return tail;
}

void RingList::setTail(NodeRing *tail) {
    RingList::tail = tail;
}

int RingList::getLength() const {
    return length;
}

void RingList::setLength(int length) {
    RingList::length = length;
}

/**
 * Método que imprime los valores de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myRingList.printList();
 */
void RingList::printList() {
    NodeRing *temp = head;

    if (temp == nullptr) {
        cout << "Empty";
    } else {
        while (temp) {
            cout << " Valor: " << temp->value;
            temp = temp->next;
            if (temp != nullptr) {
                cout << "->";
            }
        }
    }

}

/**
 * Método que imprime todos los valores de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myRingList.printAll();
 */
void RingList::makeEmpty() {
    NodeRing *temp = head;

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
 * @postcondition Se agrega un nodo al final de la lista
 * @exception Ninguna
 * @test_cases
 * myRingList.append(5);
 */
void RingList::append(int value) {
    NodeRing *newNode = new NodeRing(value);

    if (length == 0) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    length++;
}

/**
 * Método que agrega un valor al inicio de la lista.
 * @param value Valor a agregar
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se agrega un nodo al inicio de la lista
 * @exception Ninguna
 * @test_cases
 * myRingList.prepend(5);
 */
void RingList::prepend(int value) {
    NodeRing *newNode = new NodeRing(value);

    if (length == 0) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    length++;
}

/**
 * Método que elimina el último nodo de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se elimina el último nodo de la lista
 * @exception Ninguna
 * @test_cases
 * myRingList.deleteLast();
 */
void RingList::deleteLast() {
    if (length == 0) return;

    if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        NodeRing *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }

    length--;
}

/**
 * Método que elimina el primer nodo de la lista.
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se elimina el primer nodo de la lista
 * @exception Ninguna
 * @test_cases
 * myRingList.deleteFirst();
 */
void RingList::deleteFirst() {
    if (length == 0) return;

    if (length == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        NodeRing *temp = head;
        head = head->next;
        delete temp;
        tail->next = head;
    }

    length--;
}


