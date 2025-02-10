//
// Created by 72358 on 6/02/2025.
//

#ifndef DATA_ESTRUCTURE_C_DOUBLELINKEDLIST_H
#define DATA_ESTRUCTURE_C_DOUBLELINKEDLIST_H

class Node {
    public:
        int value;  // Valor del nodo
        Node* next; // Puntero al siguiente nodo
        Node* prev; // Puntero al nodo anterior

        /**
         * Constructor que inicializa el nodo con un valor dado.
         * @param value Valor del nodo a almacenar
         */
        explicit Node(int value);
};

class DoubleLinkedList {
    private:
        Node *head; // Puntero al primer nodo de la lista
        Node *tail; // Puntero al último nodo de la lista
        int length; // Longitud de la lista

    public:
        /**
         * Constructor que inicializa la lista con un valor dado.
         * @param value Valor del nodo inicial
         */
        explicit DoubleLinkedList(int value);

        /**
         * Destructor que libera la memoria de los nodos de la lista.
         */
        virtual ~DoubleLinkedList();

        /**
         * Método que retorna el nodo inicial de la lista.
         * @return Puntero al primer nodo de la lista
         */
        Node *getHead() const;

        /**
         * Método que establece el nodo inicial de la lista.
         * @param head Puntero al primer nodo de la lista
         */
        void setHead(Node *head);

        /**
         * Método que retorna el nodo final de la lista.
         * @return Puntero al último nodo de la lista
         */
        Node *getTail() const;

        /**
         * Método que establece el nodo final de la lista.
         * @param tail Puntero al nodo final de la lista
         */
        void setTail(Node *tail);

        /**
         * Método que retorna la longitud de la lista.
         * @return Longitud de la lista
         */
        int getLength() const;

        /**
         * Método que establece la longitud de la lista.
         * @param length Longitud de la lista
         */
        void setLength(int length);

        /**
         * Método que imprime los valores de la lista.
         */
        void printList();

        /**
         * Método que elimina todos los nodos de la lista.
         */
        void makeEmpty();

        /**
         * Método que agrega un valor al final de la lista.
         * @param value Valor a agregar
         */
        void append(int value);

        /**
         * Método que elimina el último nodo de la lista.
         */
        void deleteLast();

        /**
         * Método que añade un nodo al inicio de la lista.
         * @param value Valor del nodo a añadir
         */
        void prepend(int value);

        /**
         * Método que elimina el primer nodo de la lista.
         */
        void deleteFirst();

        /**
         * Método que retorna el nodo en una posición dada.
         * @param index Posición del nodo a retornar
         * @return Puntero al nodo en la posición dada
         */
        Node* get(int index);

        /**
         * Método que establece el valor de un nodo en una posición dada.
         * @param index Posición del nodo a modificar
         * @param value Valor a establecer
         * @return Puntero al nodo modificado
         */
        bool set(int index, int value);

        /**
         * Método que inserta un nodo en una posición dada.
         * @param index Posición en la que se insertará el nodo
         * @param value Valor del nodo a insertar
         * @return Verdadero si se pudo insertar el nodo, falso en caso contrario
         */
        bool insert(int index, int value);

        /**
         * Método que elimina un nodo en una posición dada.
         * @param index Posición del nodo a eliminar
         */
        void deleteNode(int index);
};


#endif //DATA_ESTRUCTURE_C_DOUBLELINKEDLIST_H
