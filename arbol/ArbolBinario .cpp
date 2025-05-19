//
// Created by 72358 on 13/05/2025.
//
#include <iostream>
using namespace std;

// Clase para el nodo del árbol binario
class Nodo {
public:
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor
    Nodo(int valor) {
        dato = valor;
        izquierda = NULL;
        derecha = NULL;
    }
};

// Clase para el árbol binario
class ArbolBinario {
private:
    Nodo* raiz;

    // Funciones auxiliares privadas
    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        // Si el árbol está vacío, retorna un nuevo nodo
        if (nodo == NULL) {
            return new Nodo(valor);
        }

        // Si no, recorre el árbol
        if (valor < nodo->dato) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }

        // Retorna el puntero al nodo (sin cambios)
        return nodo;
    }

    void inordenRecursivo(Nodo* nodo) {
        if (nodo != NULL) {
            inordenRecursivo(nodo->izquierda);
            cout << nodo->dato << " ";
            inordenRecursivo(nodo->derecha);
        }
    }

    void preordenRecursivo(Nodo* nodo) {
        if (nodo != NULL) {
            cout << nodo->dato << " ";
            preordenRecursivo(nodo->izquierda);
            preordenRecursivo(nodo->derecha);
        }
    }

    void postordenRecursivo(Nodo* nodo) {
        if (nodo != NULL) {
            postordenRecursivo(nodo->izquierda);
            postordenRecursivo(nodo->derecha);
            cout << nodo->dato << " ";
        }
    }

    Nodo* buscarRecursivo(Nodo* nodo, int valor) {
        // Caso base: raíz es NULL o el valor está en la raíz
        if (nodo == NULL || nodo->dato == valor)
            return nodo;

        // El valor es mayor que el dato de la raíz
        if (nodo->dato < valor)
            return buscarRecursivo(nodo->derecha, valor);

        // El valor es menor que el dato de la raíz
        return buscarRecursivo(nodo->izquierda, valor);
    }

    Nodo* encontrarMinimo(Nodo* nodo) {
        Nodo* actual = nodo;

        // Encuentra la hoja más a la izquierda
        while (actual && actual->izquierda != NULL)
            actual = actual->izquierda;

        return actual;
    }

    Nodo* eliminarRecursivo(Nodo* raiz, int valor) {
        // Caso base
        if (raiz == NULL) return raiz;

        // Si el valor a eliminar es menor que el valor de la raíz,
        // entonces está en el subárbol izquierdo
        if (valor < raiz->dato)
            raiz->izquierda = eliminarRecursivo(raiz->izquierda, valor);

            // Si el valor a eliminar es mayor que el valor de la raíz,
            // entonces está en el subárbol derecho
        else if (valor > raiz->dato)
            raiz->derecha = eliminarRecursivo(raiz->derecha, valor);

            // Si el valor es igual al valor de la raíz, entonces este es el nodo
            // a ser eliminado
        else {
            // Nodo con solo un hijo o sin hijos
            if (raiz->izquierda == NULL) {
                Nodo* temp = raiz->derecha;
                delete raiz;
                return temp;
            } else if (raiz->derecha == NULL) {
                Nodo* temp = raiz->izquierda;
                delete raiz;
                return temp;
            }

            // Nodo con dos hijos: obtener el sucesor inorden (el menor
            // en el subárbol derecho)
            Nodo* temp = encontrarMinimo(raiz->derecha);

            // Copiar el contenido del sucesor inorden
            raiz->dato = temp->dato;

            // Eliminar el sucesor inorden
            raiz->derecha = eliminarRecursivo(raiz->derecha, temp->dato);
        }
        return raiz;
    }

public:
    // Constructor
    ArbolBinario() {
        raiz = NULL;
    }

    // Métodos públicos
    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    void inorden() {
        inordenRecursivo(raiz);
        cout << endl;
    }

    void preorden() {
        preordenRecursivo(raiz);
        cout << endl;
    }

    void postorden() {
        postordenRecursivo(raiz);
        cout << endl;
    }

    Nodo* buscar(int valor) {
        return buscarRecursivo(raiz, valor);
    }

    void eliminar(int valor) {
        raiz = eliminarRecursivo(raiz, valor);
    }
};

// Función principal para demostrar el funcionamiento
int main() {
    ArbolBinario arbol;

    // Insertar algunos valores
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(10);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(90);
    arbol.insertar(20);
    arbol.insertar(70);
    arbol.insertar(80);

    cout << "Recorrido Inorden: ";
    arbol.inorden();

    cout << "Recorrido Preorden: ";
    arbol.preorden();

    cout << "Recorrido Postorden: ";
    arbol.postorden();

    // Buscar un valor
    int valorBuscado = 40;
    Nodo* resultado = arbol.buscar(valorBuscado);
    if (resultado)
        cout << "Valor " << valorBuscado << " encontrado en el árbol." << endl;
    else
        cout << "Valor " << valorBuscado << " no encontrado en el árbol." << endl;

    // Eliminar un nodo
    cout << "Eliminando el valor 20..." << endl;
    arbol.eliminar(20);
    cout << "Recorrido Inorden después de eliminar: ";
    arbol.inorden();

    return 0;
}