//
// Created by 72358 on 13/02/2025.
//

#ifndef DATA_ESTRUCTURE_C_STACK_H
#define DATA_ESTRUCTURE_C_STACK_H
using namespace std;
/*
 *  Clase que representa un nodo de Stack
 */
class Node {
    public:
        int value;
        Node* next;

        explicit Node(int value);
};

class Stack {
    private:
        Node* top;
        int height;

    public:

        /*
         * Constructor que inicializa la Pila
         * @param value Valor del nodo inicial
         */
        explicit Stack(int value);

        /**
         * Destructor que libera la memoria de los nodos de la pila.
         */
        virtual ~Stack();

        /**
         * Método que retorna el nodo inicial de la pila.
         * @return Puntero al primer nodo de la pila
         */
        Node *getTop() const;

        /**
         * Método que establece el nodo inicial de la pila.
         * @param top Puntero al primer nodo de la pila
         */
        void setTop(Node *top);

        /**
         * Método que establece la altura de la pila.
         * @param height Altura de la pila
         */
        void setHeight(int height);

        /**
         * Método que añade un nodo al inicio de la pila.
         * @param value Valor del nodo a añadir
         */
        void push(int value);

        /**
         * Método que elimina el nodo del inicio de la pila.
         * @return Valor del nodo eliminado
         */
        int pop();

        /**
         * Método que retorna el valor del nodo del inicio de la pila.
         * @return Valor del nodo del inicio de la pila
         */
        int peek();

        /**
         * Método que retorna si la pila está vacía.
         * @return Verdadero si la pila está vacía, falso en caso contrario
         */
        bool isEmpty();

        /**
         * Método que retorna la altura de la pila.
         * @return Altura de la pila
         */
        int getHeight();

        /**
         * Método que imprime los valores de la pila.
         */
        void printStack();

        /**
         * Método que elimina todos los nodos de la pila.
         */
        void makeEmpty();
};


#endif //DATA_ESTRUCTURE_C_STACK_H
