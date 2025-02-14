//
// Created by 72358 on 14/02/2025.
//

#ifndef DATA_ESTRUCTURE_C_RINGLIST_H
#define DATA_ESTRUCTURE_C_RINGLIST_H

class NodeRing {
public:
    int value;
    NodeRing *next;

    explicit NodeRing(int value);
};

class RingList {
    private:
        NodeRing *head;
        NodeRing *tail;
        int length;
    public:
        /**
         * Constructor que inicializa la lista con un valor dado.
         */
        explicit RingList();

        /**
         * Destructor que libera la memoria de los nodos de la lista.
         */
        virtual ~RingList();

        NodeRing *getHead() const;

        void setHead(NodeRing *head);

        NodeRing *getTail() const;

        void setTail(NodeRing *tail);

        int getLength() const;

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
         * Método que añade un nodo al final de la lista.
         */
        void append(int value);

        /**
         * Método que añade un nodo al inicio de la lista.
         */
        void prepend(int value);

        /**
         * Método que elimina el último nodo de la lista.
         */
        void deleteLast();

        /**
         * Método que elimina el primer nodo de la lista.
         */
        void deleteFirst();

        /**
        void printAll();

        NodeRing *getNode(int index);

        void deleteNode(int index);

        void reverse();

        NodeRing *middleNode();

        bool hasCycle();

        NodeRing *findKthFromEnd(int k);

        void partitionList(int x);

        void removeDuplicates();

        int binaryToDecimal();

        void reverseBetween(int m, int n);
     */
};


#endif //DATA_ESTRUCTURE_C_RINGLIST_H
