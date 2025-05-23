//
// Created by 72358 on 13/02/2025.
//

#include <iostream>
#include "Stack.h"
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
 * Constructor que inicializa la Pila
 * @param value Valor del nodo inicial
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se crea una pila con un nodo inicial
 * @exception Ninguna
 * @test_cases
 * Stack myStack = *new Stack(4);
 */
Stack::Stack(int value) {
    Node *newNode = new Node(value);

    top = newNode;
    height = 1;
}

/**
 * Destructor que libera la memoria de los nodos de la pila.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * delete myStack;
 */
Stack::~Stack() {
    Node *temp = top;
    while (top) {
        top = top->next;
        delete temp;
        temp = top;
    }
}

/**
 * Método que retorna el nodo inicial de la pila.
 * @return Puntero al primer nodo de la pila
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * Node* top = myStack.getTop();
 */
Node *Stack::getTop() const {
    return top;
}

/**
 * Método que establece el nodo inicial de la pila.
 * @param top Puntero al primer nodo de la pila
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se establece el nodo inicial de la pila
 * @exception Ninguna
 * @test_cases
 * myStack.setTop(new Node(5));
 */
void Stack::setTop(Node *top) {
    Stack::top = top;
}

/**
 * Método que establece la altura de la pila.
 * @param height Altura de la pila
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se establece la altura de la pila
 * @exception Ninguna
 * @test_cases
 * myStack.setHeight(5);
 */
void Stack::setHeight(int height) {
    Stack::height = height;
}

/**
 * Método que añade un nodo al inicio de la pila.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al inicio de la pila
 * @exception Ninguna
 * @test_cases
 * myStack.push(5);
 */
void Stack::push(int value) {
    Node *newNode = new Node(value);

    newNode->next = top;
    top = newNode;
    height++;
}

/**
 * Método que elimina el nodo del inicio de la pila.
 * @return Valor del nodo eliminado
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se elimina el nodo del inicio de la pila
 * @exception Ninguna
 * @test_cases
 * int value = myStack.pop();
 */
int Stack::pop() {
    if (height == 0) return INT_MIN;

    Node *temp = top;
    int value = top->value;

    top = top->next;
    delete temp;
    height--;

    return value;
}

/**
 * Método que retorna el valor del nodo del inicio de la pila.
 * @return Valor del nodo del inicio de la pila
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * int value = myStack.peek();
 */
int Stack::peek() {
    if (height == 0) return -1;

    return top->value;
}

/**
 * Método que retorna si la pila está vacía.
 * @return Verdadero si la pila está vacía, falso en caso contrario
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * bool isEmpty = myStack.isEmpty();
 */
bool Stack::isEmpty() {
    return height == 0;
}

/**
 * Método que retorna la altura de la pila.
 * @return Altura de la pila
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * int height = myStack.getHeight();
 */
int Stack::getHeight() {
    return height;
}

/**
 * Método que imprime los valores de la pila.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myStack.printStack();
 */
void Stack::printStack() {
    Node *temp = top;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

/**
 * Método que elimina todos los nodos de la pila.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se eliminan todos los nodos de la pila
 * @exception Ninguna
 * @test_cases
 * myStack.makeEmpty();
 */
void Stack::makeEmpty() {
    Node *temp = top;
    while (top) {
        top = top->next;
        delete temp;
        temp = top;
    }
    height = 0;
}
