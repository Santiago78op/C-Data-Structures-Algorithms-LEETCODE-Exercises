//
// Created by 72358 on 13/02/2025.
//

#ifndef DATA_ESTRUCTURE_C_QUEUE_H
#define DATA_ESTRUCTURE_C_QUEUE_H

class Node {
    public:
        int value;
        Node* next;

        explicit Node(int value);
};

class Queue {
    private:
        Node* first;
        Node* last;
        int length;

    public:

        /*
         * Constructor que inicializa la cola con un valor dado.
         * @param value Valor del nodo inicial
         */
        explicit Queue(int value);

        /**
         * Destructor que libera la memoria de los nodos de la cola.
         */
        virtual ~Queue();

        /**
         * Método que añade un nodo al final de la cola.
         * @param value Valor del nodo a añadir
         */
        Node *getFirst() const;

        /**
         * Método que añade un nodo al final de la cola.
         * @param value Valor del nodo a añadir
         */
        void setFirst(Node *first);

        /**
         * Método que añade un nodo al final de la cola.
         * @param value Valor del nodo a añadir
         */
        Node *getLast() const;

        /**
         * Método que añade un nodo al final de la cola.
         * @param value Valor del nodo a añadir
         */
        void setLast(Node *last);

        /**
         * Método que añade un nodo al final de la cola.
         * @param value Valor del nodo a añadir
         */
        int getLength();
        
        /**
         * Método que añade un nodo al final de la cola.
         * @param value Valor del nodo a añadir
         */
        void setLength(int length);

        /**
         * Método que añade un nodo al final de la cola.
         * @param value Valor del nodo a añadir
         */
        void enqueue(int value);

        /**
         * Método que elimina el primer nodo de la cola.
         * @param value Valor del nodo a añadir
         */
        int dequeue();

        /**
         * Método que elimina todos los nodos de la cola.
         */
        void makeEmpty();

        /**
         * Método que imprime todos los valores de la cola.
         */
        void printQueue();

        /**
         * Método que retorna si la cola está vacía.
         * @return Verdadero si la cola está vacía, falso en caso contrario
         */
        bool isEmpty();
};


#endif //DATA_ESTRUCTURE_C_QUEUE_H
