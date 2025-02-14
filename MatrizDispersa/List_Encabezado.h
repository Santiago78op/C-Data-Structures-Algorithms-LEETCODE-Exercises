//
// Created by 72358 on 14/02/2025.
//

#ifndef DATA_ESTRUCTURE_C_LIST_ENCABEZADO_H
#define DATA_ESTRUCTURE_C_LIST_ENCABEZADO_H

class Nodo_Encabezado {
    public:
       int id;
       Nodo_Encabezado* siguiente;
       Nodo_Encabezado* anterior;
       void* acceso; // Puntero genérico para apuntar a nodos internos

       explicit Nodo_Encabezado(int id);
};

class List_Encabezado {
    public:
        Nodo_Encabezado* primero;
        Nodo_Encabezado* ultimo;
        int length;

        /**
         * Constructor que inicializa la lista con un valor dado.
         */
        List_Encabezado(const char string[15]);

        /**
         * Destructor que libera la memoria de los nodos de la lista.
         */
        virtual ~List_Encabezado();

        /**
         * Método que inserta un nodo en la lista.
         * @param nuevo Nodo a insertar
         */
        void insertar(Nodo_Encabezado* nuevo);

        /**
         * Método que busca un nodo en la lista.
         * @param id Identificador del nodo a buscar
         * @return Puntero al nodo buscado
         */
        Nodo_Encabezado* buscar(int id);

        /**
         * Método que elimina un nodo de la lista.
         * @param id Identificador del nodo a eliminar
         */
        void eliminar(int id);

        /**
         * Método que imprime los valores de la lista.
         */
        void imprimir();

};


#endif //DATA_ESTRUCTURE_C_LIST_ENCABEZADO_H
