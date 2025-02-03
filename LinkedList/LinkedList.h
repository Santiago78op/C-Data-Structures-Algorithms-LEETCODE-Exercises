//
// Created by 72358 on 2/10/2024.
//

#ifndef DATA_ESTRUCTURE_C_LINKEDLIST_H
#define DATA_ESTRUCTURE_C_LINKEDLIST_H

/*
 *  Clase que representa un nodo de la lista enlazada
 */
class Node {
    public:
        int value; // Valor del nodo
        Node* next; // Puntero al siguiente nodo

    /*
     * Constructor que inicializa el nodo con un valor dado.
     * @param value Valor del nodo a almacenar
     */
    explicit Node(int value);
};

/*
 * Clase que representa una lista enlazada
 */
class LinkedList {
    private:
        Node* head; // Puntero al primer nodo de la lista
        Node* tail; // Puntero al último nodo de la lista
        int length; // Longitud de la lista

    public:

        /*
         * Constructor que inicializa la lista con un valor dado.
         * @param value Valor del nodo inicial
         */
        explicit LinkedList(int value);

        /*
         * Destructor que libera la memoria de los nodos de la lista.
         */
        virtual ~LinkedList();

        /*
         * Método que retorna el nodo final de la lista.
         * @return Puntero al último nodo de la lista
         */
        Node *getTail() const;

        /*
         * Método que establece el nodo final de la lista.
         * @param tail Puntero al nodo final de la lista
         */
        void setTail(Node *tail);

        /*
         * Método que retorna el nodo inicial de la lista.
         * @return Puntero al primer nodo de la lista
         */
        Node *getHead() const;

        /*
         * Método que establece el nodo inicial de la lista.
         * @param head Puntero al primer nodo de la lista
         */
        void setHead(Node *head);

        /*
         * Método que retorna la longitud de la lista.
         * @return Longitud de la lista
         */
        int getLength() const;

        /*
         * Método que establece la longitud de la lista.
         * @param length Longitud de la lista
         */
        void setLength(int length);

        /*
         * Método que imprime los valores de la lista.
         */
        void printList();

        /*
         * Método que elimina todos los nodos de la lista.
         */
        void makeEmpty();

        /*
         * Método que imprime todos los valores de la lista.
         */
        void printAll();

        /*
         * Método que agrega un valor al final de la lista.
         * @param value Valor a agregar
         */
        void append(int value);

        /*
         * Método que agrega un valor al inicio de la lista.
         * @param value Valor a agregar
         */
        void prepend(int value);

        /*
         * Método que elimina el último nodo de la lista.
         */
        void deleteLast();

        /*
         * Método que elimina el primer nodo de la lista.
         */
        void deleteFirst();

        /*
         * Método que retorna el nodo en una posición dada.
         * @param index Posición del nodo a retornar
         * @return Puntero al nodo en la posición dada
         */
        Node* get(int index);

        /*
         * Método que establece el valor de un nodo en una posición dada.
         * @param index Posición del nodo a modificar
         * @param value Valor a establecer
         * @return Verdadero si se pudo establecer el valor, falso en caso contrario
         */
        bool  set(int index, int value);

        /*
         * Método que inserta un nodo en una posición dada.
         * @param index Posición en la que se insertará el nodo
         * @param value Valor del nodo a insertar
         * @return Verdadero si se pudo insertar el nodo, falso en caso contrario
         */
        bool  insert(int index, int value);

        /*
         * Método que elimina un nodo en una posición dada.
         * @param index Posición del nodo a eliminar
         */
        void deleteNode(int index);

        /*
         * Método que invierte la lista.
         */
        void reverse();

        /*
         * Método que retorna el nodo del medio de la lista.
         * @return Puntero al nodo del medio de la lista
         */
        Node* middleNode();

        /*
         * Método que retorna si la lista tiene un ciclo.
         * @return Verdadero si la lista tiene un ciclo, falso en caso contrario
         */
        bool hasCycle();

        /*
         * Método que retorna el nodo de inicio del ciclo de la lista.
         * @param k Posición del nodo desde el final de la lista
         * @return Puntero al nodo de inicio del ciclo de la lista
         */
        Node* findKthFromEnd(int k);

        /*
         * Método que divide la lista de manera que todos los nodos
         * con valores menores a x queden antes que los nodos con valores
         * mayores o iguales a x.
         * @param x Valor de referencia para la partición
         * @return Puntero al nodo de inicio del ciclo de la lista
         */
        void partitionList(int x);

        /*
         * Método que elimina el nodo del medio de la lista.
         * @return void
         */
        void removeDuplicates();

        /*
         * Método que convierte un número binario a decimal.
         * @return Valor decimal del número binario
         */
        int binaryToDecimal();

        void reverseBetween(int m, int n);
};


#endif //DATA_ESTRUCTURE_C_LINKEDLIST_H
