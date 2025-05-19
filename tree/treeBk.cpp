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

    ArbolB* espejo() {
        ArbolB* nuevoArbol = new ArbolB(k);
        nuevoArbol->raíz = espejoRecursivo(raíz);
        return nuevoArbol;
    }

private:
    NodoB<K, T>* raíz;
    int k;

    NodoB<K, T>* espejoRecursivo(NodoB<K, T>* nodo) {
        if (nodo == nullptr) {
            return nullptr;
        }

        NodoB<K, T>* nuevoNodo = new NodoB<K, T>(k);
        nuevoNodo->conteo = nodo->conteo;

        // Copiar llaves e info
        for (int i = 0; i < nodo->conteo; ++i) {
            nuevoNodo->llaves[i] = nodo->llaves[i];
            nuevoNodo->info[i] = nodo->info[i];
        }

        // Copiar hijos en orden inverso
        for (int i = 0; i <= nodo->conteo; ++i) {
            nuevoNodo->hijo[i] = espejoRecursivo(nodo->hijo[nodo->conteo - i]);
        }

        return nuevoNodo;
    }
};