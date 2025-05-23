//
// Created by 72358 on 26/03/2025.
//
#include <vector>
#include <stack>
#include <list>
#include <cstring>

struct Vertice {
    char nombre[50];
    int valor;
};

class Grafo {
public:
    Grafo();
    ~Grafo();
    std::list<Vertice> ciclo();

private:
    Vertice V[n];
    int ma[n][n];
    bool dfs(int v, std::vector<bool>& visitado, std::vector<bool>& enRecursion, std::stack<int>& pila, std::vector<int>& padre);
};

Grafo::Grafo() {
    // Constructor
}

Grafo::~Grafo() {
    // Destructor
}

bool Grafo::dfs(int v, std::vector<bool>& visitado, std::vector<bool>& enRecursion, std::stack<int>& pila, std::vector<int>& padre) {
    visitado[v] = true;
    enRecursion[v] = true;
    pila.push(v);

    for (int i = 0; i < n; ++i) {
        if (ma[v][i] == 1) {
            if (!visitado[i]) {
                padre[i] = v;
                if (dfs(i, visitado, enRecursion, pila, padre)) {
                    return true;
                }
            } else if (enRecursion[i]) {
                padre[i] = v;
                pila.push(i);
                return true;
            }
        }
    }

    pila.pop();
    enRecursion[v] = false;
    return false;
}

std::list<Vertice> Grafo::ciclo() {
    std::vector<bool> visitado(n, false);
    std::vector<bool> enRecursion(n, false);
    std::stack<int> pila;
    std::vector<int> padre(n, -1);

    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            if (dfs(i, visitado, enRecursion, pila, padre)) {
                std::list<Vertice> cicloVertices;
                int inicio = pila.top();
                pila.pop();
                cicloVertices.push_front(V[inicio]);
                while (!pila.empty() && pila.top() != inicio) {
                    cicloVertices.push_front(V[pila.top()]);
                    pila.pop();
                }
                cicloVertices.push_front(V[inicio]);
                return cicloVertices;
            }
        }
    }

    return std::list<Vertice>(); // No se encontró ciclo
}
