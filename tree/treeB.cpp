//
// Created by Santiago on 13/03/2025.
//
template <class K, class T>
class NodoB {
public:
    K llaves[];
    T info[];
    NodoB* hijo[];
    int k;
    int conteo;

    NodoB(int k) : k(k), conteo(0) {
        llaves = new K[k - 1];
        info = new T[k - 1];
        hijo = new NodoB*[k];
        for (int i = 0; i < k; ++i) {
            hijo[i] = nullptr;
        }
    }

    ~NodoB() {
        delete[] llaves;
        delete[] info;
        delete[] hijo;
    }
};

template <class K, class T>
class ArbolB {
public:
    ArbolB(int k) : k(k), raíz(nullptr) {}

    void guardar(std::ostream& arch) {
        guardarRecursivo(arch, raíz);
    }

    void leer(std::istream& arch) {
        raíz = leerRecursivo(arch);
    }

private:
    NodoB<K, T>* raíz;
    int k;

    void guardarRecursivo(std::ostream& arch, NodoB<K, T>* nodo) {
        if (nodo == nullptr) {
            // Guardar un indicador de nodo vacío
            arch << "# ";
            return;
        }

        // Guardar el nodo actual
        guardarNodo(arch, nodo);

        // Guardar recursivamente los hijos
        for (int i = 0; i <= nodo->conteo; ++i) {
            guardarRecursivo(arch, nodo->hijo[i]);
        }
    }

    NodoB<K, T>* leerRecursivo(std::istream& arch) {
        std::string indicador;
        arch >> indicador;

        if (indicador == "#") {
            // Nodo vacío
            return nullptr;
        }

        // Leer el nodo actual
        NodoB<K, T>* nodo = leerNodo(arch);

        // Leer recursivamente los hijos
        for (int i = 0; i <= nodo->conteo; ++i) {
            nodo->hijo[i] = leerRecursivo(arch);
        }

        return nodo;
    }

    void guardarNodo(std::ostream& arch, NodoB<K, T>* nodo) {
        // Implementación de guardarNodo
    }

    NodoB<K, T>* leerNodo(std::istream& arch) {
        // Implementación de leerNodo
        return nullptr;
    }
};