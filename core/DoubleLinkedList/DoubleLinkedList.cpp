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
DoubleLinkedList::DoubleLinkedList() {
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

/**
 * Método que elimina el primer nodo de la lista.
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se elimina el primer nodo de la lista
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.deleteFirst();
 */
void DoubleLinkedList::deleteFirst() {
    if (length == 0) return;

    Node *temp = head;

    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    length--;
}

/**
 * Método que inserta un nodo en una posición dada.
 * @param index Posición en la que se insertará el nodo
 * @param value Valor del nodo a insertar
 * @return Verdadero si se pudo insertar el nodo, falso en caso contrario
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se inserta un nodo en la posición dada
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.insert(2, 5);
 */
Node *DoubleLinkedList::get(int index) {
    if (index < 0 || index >= length) return nullptr;

    Node *temp = head;

    if (index < length/2){
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
    } else {
        temp = tail;
        for (int i = length - 1; i > index; --i) {
            temp = temp->prev;
        }
    }
    return temp;
}

/**
 * Método que establece el valor de un nodo en una posición dada.
 * @param index Posición del nodo a modificar
 * @param value Valor a establecer
 * @return Verdadero si se pudo modificar el nodo, falso en caso contrario
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se modifica el valor de un nodo en la posición dada
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.set(2, 5);
 */
bool DoubleLinkedList::set(int index, int value) {
    Node *temp = get(index);

    if(temp) {
        temp->value = value;
        return true;
    }
    return false;
}


/**
 * Método que inserta un nodo en una posición dada.
 * @param index Posición en la que se insertará el nodo
 * @param value Valor del nodo a insertar
 * @return Verdadero si se pudo insertar el nodo, falso en caso contrario
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se inserta un nodo en la posición dada
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.insert(2, 5);
 */
bool DoubleLinkedList::insert(int index, int value) {
    if (index < 0 || index > length) return false;

    if (index == 0){
        prepend(value);
        return true;
    }

    if (index == length){
        append(value);
        return true;
    }

    // Insertar en medio
    Node* newNode = new Node(value);
    Node* before = get(index - 1);
    Node* after = before->next;

    newNode->prev = before;
    newNode->next = after;

    before->next = newNode;
    after->prev = newNode;

    length++;
    return true;
}

/**
 * Método que elimina un nodo en una posición dada.
 * @param index Posición del nodo a eliminar
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se elimina un nodo en la posición dada
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.deleteNode(2);
 */
void DoubleLinkedList::deleteNode(int index) {
    if (index < 0 || index >= length) return;

    if (index == 0) {
        deleteFirst();
        return;
    }

    if (index == length - 1) {
        deleteLast();
        return;
    }

    Node* temp = get(index);

    if (temp == nullptr) return;

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    length--;
}

/**
 * Método que invierte la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se invierte la lista
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.reverse();
 */
void DoubleLinkedList::swapFirstAndLast() {
    if(length < 2) return;

    int temp = head->value;
    head->value = tail->value;
    tail->value = temp;
}

/**
 * Método que invierte la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se invierte la lista
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.reverse();
 */
void DoubleLinkedList::reverse() {
    if (length < 2) return;

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        // Intercambiar los punteros next y prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Moverse al siguiente nodo en la lista original
        current = current->prev;
    }

    // Intercambiar head y tail
    temp = head;
    head = tail;
    tail = temp;
}

/**
 * Método que verifica si la lista es un palíndromo.
 * @return Verdadero si la lista es un palíndromo, falso en caso contrario
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.isPalindrome();
 */
bool DoubleLinkedList::isPalindrome() {
    if (length < 2) return true;

    Node* left = head;
    Node* right = tail;

    while (left != right && left->prev != right) {
        if (left->value != right->value) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}

/**
 * Método que intercambia los nodos en pares.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se intercambian los nodos en pares
 * @exception Ninguna
 * @test_cases
 * myDoubleLinkedList.swapPairs();
 */
void DoubleLinkedList::swapPairs() {
    if (length < 2) return;

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        // Intercambiar los valores de current y current->next
        int temp = current->value;
        current->value = current->next->value;
        current->next->value = temp;

        // Moverse al siguiente par de nodos
        current = current->next->next;
    }
}
