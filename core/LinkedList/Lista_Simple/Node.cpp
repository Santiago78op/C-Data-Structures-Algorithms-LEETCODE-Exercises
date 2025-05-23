//
// Created by 72358 on 23/05/2025.
//

/**
 * Clase Node: Representa un nodo en una lista enlazada simple.
 * @tparam T Tipo de dato a almacenar en el nodo.
 */
template<typename T>
struct Node {
    T* data; // Puntero al dato almacenado en el nodo
    Node<T>* next; // Puntero al siguiente nodo

    // Constructor
    Node(T* data) : data(data), next(nullptr) {}
};