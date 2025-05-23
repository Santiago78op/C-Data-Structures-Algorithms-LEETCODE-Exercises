//
// Created by 72358 on 13/02/2025.
//

#include <iostream>
#include "Queue.h"

using namespace std; // Para evitar escribir std::cout, std::cin, std::endl

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
Node::Node(int value) {
    this->value = value;
    next = nullptr;
}

/**
 * Constructor que inicializa la Cola
 * @param value Valor del nodo inicial
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se crea una cola con un nodo inicial
 * @exception Ninguna
 * @test_cases
 * Queue myQueue = *new Queue(4);
 */
Queue::Queue(int value) {
    Node *newNode = new Node(value);

    first = newNode;
    last = newNode;
    length = 1;
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
Queue::~Queue() {
    Node *temp = first;
    while (first) {
        first = first->next;
        delete temp;
        temp = first;
    }
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
Node *Queue::getFirst() const {
    return first;
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
void Queue::setFirst(Node *first) {
    Queue::first = first;
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
Node *Queue::getLast() const {
    return last;
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
void Queue::setLast(Node *last) {
    Queue::last = last;
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
int Queue::getLength() {
    return length;
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
void Queue::setLength(int length) {
    Queue::length = length;
}

/**
 * Método que añade un nodo al final de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
void Queue::enqueue(int value) {
    Node *newNode = new Node(value);

    if (length == 0) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }

    length++;
}

/**
 * Método que elimina el primer nodo de la cola.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.enqueue(5);
 */
int Queue::dequeue() {
    if (length == 0) return INT_MIN;

    Node *temp = first;
    int value = first->value;

    if (length == 1){
        first = nullptr;
        last = nullptr;
    } else {
        first = first->next;
    }

    delete temp;
    length--;
    return value;
}

/**
 * Método que elimina todos los nodos de la cola.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se eliminan todos los nodos de la cola
 * @exception Ninguna
 * @test_cases
 * myQueue.makeEmpty();
 */
void Queue::makeEmpty() {
    Node *temp = first;
    while (first) {
        first = first->next;
        delete temp;
        temp = first;
    }
    length = 0;
}

/**
 * Método que imprime los valores de la cola.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myQueue.printQueue();
 */
void Queue::printQueue() {
    if (length == 0) {
        cout << "Empty";
        return;
    } else {
        Node *temp = first;
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
 * Método que retorna si la cola está vacía.
 * @return Verdadero si la cola está vacía, falso en caso contrario
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myQueue.isEmpty();
 */
bool Queue::isEmpty() {
    if (length == 0) return true;
    return false;
}


