//
// Created by 72358 on 27/03/2025.
//
#include <vector>
#include <limits>
#include <list>

struct Vertice {
    char nombre[50];
    int valor;
};

class Grafo {
public:
    std::list<Vertice> ruta(int i, int j);

private:
    Vertice V[n] ; // arreglo de vértices
    int ma [n,n] ; // matriz de adyacencia
};

template <class INDEX, class T>
class PriorityQueue {
public:
    PriorityQueue();
    ~PriorityQueue();

    //* agrega un elemento a la cola
    void add(INDEX i, T info);
    //* saca el elemento de la cola con el menor índice
    T popMin();
    bool isEmpty();
};

std::list<Vertice> Grafo::ruta(int i, int j) {
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<int> prev(n, -1);
    PriorityQueue<int, int> pq;

    dist[i] = 0;
    pq.add(i, 0);

    while (!pq.isEmpty()) {
        int u = pq.popMin();

        if (u == j) break;

        for (int v = 0; v < n; ++v) {
            if (ma[u][v] != -1) {
                int alt = dist[u] + ma[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    pq.add(v, alt);
                }
            }
        }
    }

    std::list<Vertice> path;
    for (int at = j; at != -1; at = prev[at]) {
        path.push_front(V[at]);
    }

    if (path.front().valor != V[i].valor) {
        path.clear(); // No se encontró un camino
    }

    return path;
}