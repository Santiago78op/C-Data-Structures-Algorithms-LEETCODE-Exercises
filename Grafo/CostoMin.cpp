//
// Created by Santiago Barrera on 2/04/2025.
//
#include <utility>
#include <stack>
#include <vector>

struct Vertice {
    char nombre[50];
    int valor;
};

class Grafo {
public:
    Grafo();
    ~Grafo();
     /* Puntos a mejorar,
      * 1. Inconsistencia de los nombres de las variables, visitado, enCamino, padre
      * 2. Uso de constantes para el tamaño de la matriz y el arreglo de vértices
      * 3. Hacer un struct de visitado, enCamino y padre
      * 4. Utilizar banderas para indicar si se ha encontrado un ciclo
      * 5. Cambiar el nombre de la función a "ciclo" para que sea más descriptivo
      * 6. No usar los Break y Return en el mismo lugar, es mejor usar un flag
      * 7. Sacar ciertas implementaciones de los if, para no ser redundantes.
      */
    List<Vertice> ciclo() {
        const int TAMANIO = n; // Asumiendo que n es una constante o miembro de la clase

        // Estructuras para seguimiento
        bool visitado[TAMANIO] = {false};    // Nodos ya visitados
        bool enCamino[TAMANIO] = {false};    // Nodos en el camino actual
        int padre[TAMANIO];                  // Para reconstruir el ciclo

        for (int i = 0; i < TAMANIO; i++) {
            padre[i] = -1;
        }

        stack<std::pair<int, int>> pila;  // Par (nodoActual, índiceVecino)
        List<Vertice> resultado;

        // Comenzamos desde el vértice 0 como se indicó
        int nodoActual = 0;
        int indiceVecino = 0;
        pila.push(std::make_pair(nodoActual, indiceVecino));
        visitado[nodoActual] = true;
        enCamino[nodoActual] = true;

        while (!pila.empty()) {
            // Obtenemos el nodo actual y su índice de vecino a explorar
            std::pair<int, int> actual = pila.top();
            nodoActual = actual.first;
            indiceVecino = actual.second;
            pila.pop();

            // Buscamos el siguiente vecino no visitado a partir del índice actual
            while (indiceVecino < TAMANIO && (indiceVecino != nodoActual || !visitado[indiceVecino])) {
                indiceVecino++;
            }

            // Si encontramos un vecino
            if (indiceVecino < TAMANIO) {
                // Guardamos el estado actual para continuar después con el siguiente vecino
                pila.push(make_pair(nodoActual, indiceVecino + 1));

                // Si el vecino ya está en nuestro camino actual, hemos encontrado un ciclo
                if (enCamino[indiceVecino]) {
                    // Reconstruimos el ciclo
                    int inicio = indiceVecino;
                    int actual = nodoActual;

                    // Añadimos el nodo que cierra el ciclo
                    resultado.pushFront(V[inicio]);

                    // Reconstruimos el camino desde el nodo actual hasta el inicio del ciclo
                    while (actual != inicio) {
                        resultado.pushFront(V[actual]);
                        actual = padre[actual];
                    }

                    // Añadimos el nodo inicial para cerrar el ciclo
                    resultado.pushFront(V[inicio]);

                    return resultado;
                }

                // Si el vecino no ha sido visitado, avanzamos a él
                if (!visitado[indiceVecino]) {
                    padre[indiceVecino] = nodoActual;
                    visitado[indiceVecino] = true;
                    enCamino[indiceVecino] = true;

                    // Avanzamos al siguiente nodo
                    nodoActual = indiceVecino;
                    indiceVecino = 0;
                    pila.push(make_pair(nodoActual, indiceVecino));
                }
            }
            else {
                // Si terminamos de explorar todos los vecinos, este nodo ya no está en el camino actual
                enCamino[nodoActual] = false;
            }
        }

        // Si no encontramos ciclo, devolvemos una lista vacía
        return resultado;
    }

private:
    Vertice V[n];  // Asumiendo que n es una constante conocida
    int ma[n][n];  // Matriz de adyacencia con sintaxis correcta
};