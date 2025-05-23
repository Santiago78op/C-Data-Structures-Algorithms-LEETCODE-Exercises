//
// Created by 72358 on 23/05/2025.
//
#include <iostream>
#include <stdexcept>
#include "IDisposable.cpp"
#include "Node.cpp"

/**
 * Clase LinkedList: Implementación de una lista enlazada simple.
 * @tparam T Tipo de dato a almacenar en la lista.
 */
template<typename T>
class LinkedList : public IDisposable {
private:
   Node <T>* head; // Puntero al primer nodo
   Node<T>* tail; // Puntero al último nodo
   int length; // Número de nodos en la lista
public:

   /**
    * Constructor de la clase LinkedList.
    * @tparam T Tipo de dato a almacenar en la lista.
    * @complexity O(1)
    */
   LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    /**
     * Método para agregar un nuevo nodo al final de la lista.
     * @param value Puntero al dato a almacenar en el nuevo nodo.
     * @return void
     * @complexity O(1)
     */
   void append(T* value) {
       Node<T>* newNode = new Node<T>(value);

       if (!head) {
           head = tail = newNode;
       } else {
           tail->next = newNode;
           tail = newNode;
       }
       ++length;
   }

    /**
     * Método para remover un nodo de la lista
     * @param value Valor del nodo a eliminar
     * @return void
     * @complexity O(n)
     */
   void remove(const T& value) {
       Node<T>* current = head;
       Node<T>* previous = nullptr;

       while (current) {
           if (*current->data == value) {
               if (previous == nullptr)
                   head = current->next;
               else
                   previous->next = current->next;
               if (current == tail)
                   tail = previous;

               delete current->data;
               delete current;
               --length;
               return;
           }
           previous = current;
           current = current->next;
       }
   }

   /**
    * Método para buscar un nodo en la lista.
    * @param value Valor a buscar.
    * @return Puntero al nodo encontrado o nullptr si no se encuentra.
    * @complexity O(n)
    */
   Node<T>* search(const T& value) const {
       Node<T>* current = head;

       while (current) {
           if (*current->data == value)
               return current;
           current = current->next;
       }
       return nullptr;
   }

    /**
     * Método para modificar un nodo en la lista.
     * @param id ID del nodo a modificar.
     * @param newData Nuevo dato a almacenar en el nodo.
     * @return true si se modifica, false si no se encuentra el nodo.
     * @complexity O(n)
     */
   bool modify(int id, T* newData) {
       Node<T>* current = head;

       while (current) {
           if (current->data->Id == id) {
               delete current->data;
               current->data = newData;
               return true;
           }
           current = current->next;
       }
       return false;
   }

    /**
     * Método para obtener un nodo en una posición específica.
     * @param index Índice del nodo a obtener.
     * @return Puntero al nodo en la posición dada.
     * @complexity O(n)
     */
   Node<T>* getNode(int index) const {
       if (index < 0 || index >= length)
           throw std::out_of_range("Index out of range");
       Node<T>* current = head;
       for (int i = 0; i < index; ++i)
           current = current->next;
       return current;
   }

    /**
     * Método para imprimir todos los nodos de la lista.
     * @return void
     * @complexity O(n)
     */
   void printList() const {
       Node<T>* current = head;
       if (!current) {
           std::cout << "La lista está vacía\n";
           return;
       }
       while (current) {
           std::cout << "Dato: " << current->data->toString() << "\n";
           current = current->next;
       }
   }

    /**
     * Método para liberar la memoria de todos los nodos de la lista.
     * @return void
     * @complexity O(n)
     */
   void dispose() override {
       Node<T>* current = head;
       while (current) {
           Node<T>* next = current->next;
           delete current->data;
           delete current;
           current = next;
       }
       head = tail = nullptr;
       length = 0;
   }

    /**
     * Destructor de la clase LinkedList.
     * @return void
     * @complexity O(n)
     */
   ~LinkedList() override {
       LinkedList<T>::dispose();
   }

    /**
     * Método para obtener el tamaño de la lista.
     * @return Tamaño de la lista.
     * @complexity O(1)
     */
   int size() const { return length; }
};