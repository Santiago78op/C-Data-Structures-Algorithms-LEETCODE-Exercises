//
// Created by 72358 on 2/10/2024.
//

#include <iostream>
#include "LinkedList.h"

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

/*
 * Constructor que inicializa la lista con un valor dado.
 * @param value Valor del nodo inicial
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se crea una lista con un nodo inicial
 * @exception Ninguna
 * @test_cases
 * LinkedList myLinkedList = *new LinkedList(4);
 */
LinkedList::LinkedList(int value) {
    Node *newNode = new Node(value);

    head = newNode;
    tail = newNode;
    length = 1;
}

/*
 * Método que retorna el nodo final de la lista.
 * @return Puntero al último nodo de la lista
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * Node* tail = myLinkedList.getTail();
 */
Node *LinkedList::getTail() const {
    return tail;
}

/*
 * Método que establece el nodo final de la lista.
 * @param tail Puntero al nodo final de la lista
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se establece el nodo final de la lista
 * @exception Ninguna
 * @test_cases
 * myLinkedList.setTail(new Node(5));
 */
void LinkedList::setTail(Node *tail) {
    LinkedList::tail = tail;
}

/*
 * Método que retorna el nodo inicial de la lista.
 * @return Puntero al primer nodo de la lista
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * Node* head = myLinkedList.getHead();
 */
Node *LinkedList::getHead() const {
    return head;
}

/*
 * Método que establece el nodo inicial de la lista.
 * @param head Puntero al primer nodo de la lista
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se establece el nodo inicial de la lista
 * @exception Ninguna
 * @test_cases
 * myLinkedList.setHead(new Node(5));
 */
void LinkedList::setHead(Node *head) {
    LinkedList::head = head;
}

/*
 * Método que retorna la longitud de la lista.
 * @return Longitud de la lista
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * int length = myLinkedList.getLength();
 */
int LinkedList::getLength() const {
    return length;
}

/*
 * Método que establece la longitud de la lista.
 * @param length Longitud de la lista
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se establece la longitud de la lista
 * @exception Ninguna
 * @test_cases
 * myLinkedList.setLength(5);
 */
void LinkedList::setLength(int length) {
    LinkedList::length = length;
}

/*
 * Método que imprime los valores de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.printList();
 */
void LinkedList::printList() {
    Node *temp = head;

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

/*
 * Método que elimina todos los nodos de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se eliminan todos los nodos de la lista
 * @exception Ninguna
 * @test_cases
 * myLinkedList.makeEmpty();
 */
void LinkedList::makeEmpty() {
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

/*
 * Método que imprime todos los valores de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.printAll();
 */
void LinkedList::printAll() {
    if (length == 0) {
        cout << "Head: null" << endl;
        cout << "Tail: null" << endl;
    } else {
        cout << "Head: " << head->value << endl;
        cout << "Tail: " << tail->value << endl;
    }

    cout << "Length: " << length << endl;
    cout << "Linked List" << endl;

    if (length == 0) {
        cout << "Empty!!!" << endl;
    } else {
        printList();
    }
}

/*
 * Destructor que libera la memoria de los nodos de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se liberan los nodos de la lista
 * @exception Ninguna
 * @test_cases
 * delete myLinkedList;
 */
LinkedList::~LinkedList() {
    Node *temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

/*
 * Método que añade un nodo al final de la lista.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se añade un nodo al final de la lista
 * @exception Ninguna
 * @test_cases
 * myLinkedList.append(5);
 */
void LinkedList::append(int value) {
    Node *newNode = new Node(value);

    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    length++;
}

/*
 * Método que elimina el último nodo de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Se elimina el último nodo de la lista
 * @exception Ninguna
 * @test_cases
 * myLinkedList.deleteLast();
 */
void LinkedList::deleteLast() {
    if (length == 0) return;

    Node *temp = head;

    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        Node *pre = head;

        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }

        tail = pre;
        tail->next = nullptr;
    }

    delete temp;
    length--;
}

/*
 * Método que elimina el primer nodo de la lista.
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Se elimina el primer nodo de la lista
 * @exception Ninguna
 * @test_cases
 * myLinkedList.deleteFirst();
 */
void LinkedList::deleteFirst() {
    if(length == 0) return;

    Node* temp = head;

    if(length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
    }

    delete temp;
    length--;
}

/*
 * Método que retorna el nodo en la posición dada.
 * @param index Posición del nodo a retornar
 * @return Puntero al nodo en la posición dada
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * Node* node = myLinkedList.get(5);
 */
Node *LinkedList::get(int index) {
    if(index < 0 || index >= length) return nullptr;

    Node* temp = head;

    for(int i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp;
}

/*
 * Método que retorna el valor del nodo en la posición dada.
 * @param index Posición del nodo a retornar
 * @return Valor del nodo en la posición dada
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * int value = myLinkedList.getValue(5);
 */
bool LinkedList::set(int index, int value) {
    Node* temp = get(index);

    if(temp == nullptr) return false;

    temp->value = value;
    return true;
}

/*
 * Método que inserta un nodo en la posición dada.
 * @param index Posición donde se insertará el nodo
 * @param value Valor del nodo a insertar
 * @return true si se inserta el nodo, false en caso contrario
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.insert(5, 10);
 */
bool LinkedList::insert(int index, int value) {
    if (index < 0 || index > length) return false;

    if(index == 0){
        prepend(value);
        return true;
    }

    if(index == length){
        append(value);
        return true;
    }

    Node* newNode = new Node(value);
    Node* temp = get(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;

    return true;
}

/*
 * Método que elimina un nodo en la posición dada.
 * @param index Posición del nodo a eliminar
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.deleteNode(5);
 */
void LinkedList::deleteNode(int index) {
    if (index < 0 || index >= length) return;
    if (index == 0) return deleteFirst();
    if (index == length - 1) return deleteLast();

    Node* prev = get(index - 1);
    Node* temp = prev->next;

    prev->next = temp->next;
    delete temp;
    length--;
}

/*
 * Método que invierte la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.reverse();
 */
void LinkedList::reverse() {
    if (length <= 1) return;

    Node* temp = head;
    head             = tail;
    tail                = temp;

    Node* after = temp->next;
    Node* before = nullptr;

    for (int i = 0; i < length; ++i) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}

/*
 * Método que añade un nodo al inicio de la lista.
 * @param value Valor del nodo a añadir
 * @return void
 * @complexity O(1)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.prepend(5);
 */
void LinkedList::prepend(int value) {
    Node* newNode = new Node(value);

    if(length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    length++;

}

/*
 * Método que retorna el nodo del medio de la lista.
 * @return Puntero al nodo del medio de la lista
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * Node* middle = myLinkedList.middleNode();
 */
Node *LinkedList::middleNode() {
    if(head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast  = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/*
 * Método que retorna el nodo del medio de la lista.
 * @return Puntero al nodo del medio de la lista
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * Node* middle = myLinkedList.middleNode();
 */
bool LinkedList::hasCycle() {
    if (head == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

/*
 * Método que retorna el nodo del medio de la lista.
 * @return Puntero al nodo del medio de la lista
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * Node* middle = myLinkedList.middleNode();
 */
Node *LinkedList::findKthFromEnd(int k) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    Node* kth = head;

    for (int i = 0; i < k; ++i) {
        if (temp == nullptr) return nullptr;
        temp = temp->next;
    }

    while (temp != nullptr) {
        temp = temp->next;
        kth = kth->next;
    }

    return kth;
}

/*
 * Método que elimina el nodo del medio de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.deleteMiddleNode();
 */
void LinkedList::partitionList(int x) {
    if (head == nullptr) return;

    Node* lessHead = nullptr;
    Node* lessTail = nullptr;
    Node* greaterHead = nullptr;
    Node* greaterTail = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = nullptr;

        if (current->value < x) {
            if (lessHead == nullptr) {
                lessHead = current;
                lessTail = lessHead;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else {
            if (greaterHead == nullptr) {
                greaterHead = current;
                greaterTail = greaterHead;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = nextNode;
    }

    if (lessHead == nullptr) {
        head = greaterHead;
    } else {
        head = lessHead;
        lessTail->next = greaterHead;
    }
}

/*
 * Método que elimina el nodo del medio de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.deleteMiddleNode();
 */
void LinkedList::removeDuplicates() {
    if (head == nullptr) return;

    Node* current = head;

    while (current != nullptr) {
        // runner es usado para comparar el nodo actual con los nodos siguientes
        Node* runner = current;

        while (runner->next != nullptr) {
            if (runner->next->value == current->value) {
                // temp es usado para eliminar el nodo duplicado
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
                length--;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

/*
 * Método que elimina el nodo del medio de la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.deleteMiddleNode();
 */
int LinkedList::binaryToDecimal() {
    if ( head == nullptr) return 0;

    int num = 0;
    Node* current = head;

    while  (current != nullptr) {
        num = num * 2 + current->value;
        current = current->next;
    };

    return num;
}

/*
 * Método que invierte la lista.
 * @return void
 * @complexity O(n)
 * @precondition Ninguna
 * @postcondition Ninguna
 * @exception Ninguna
 * @test_cases
 * myLinkedList.reverse();
 */
void LinkedList::reverseBetween(int m, int n) {
    if (head == nullptr) return;

    // Crear un nodo dummy para evitar el caso base
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;

    // Mover prev al nodo anterior al inicio de la reversión
    for (int i = 0; i < m ; ++i) {
        prev = prev->next;
    }

    // Inicializar los nodos start y then para la reversión
    Node* start = prev->next;
    Node* then = start->next;

    // Invertir los nodos m a n
    for (int i = 0; i < n - m; ++i) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    // Eliminar el nodo dummy
    head = dummy->next;
    delete dummy;
}
