#include <iostream>
#include "LinkedList/LinkedList.h"

using namespace std;

int fibonacciOptimo(int n, int a, int b);

int main() {

    // Funcion fibonacci
    fibonacciOptimo(5,0,1);
    // Imprimir hola mundo
    cout << "Hello, World!" << endl;
    return 0;
}

/**
 * Función auxiliar recursiva que calcula el n-ésimo número de la serie de Fibonacci.
 * @param n Número de la serie de Fibonacci a calcular
 * @param a Valor del (n-2)-ésimo número de la serie de Fibonacci
 * @param b Valor del (n-1)-ésimo número de la serie de Fibonacci
 * @return N-ésimo número de la serie de Fibonacci
 */
int fibonacciOptimo(int n, int a, int b) {
    if (n == 0) {
        return a;
    } else {
        return fibonacciOptimo(n - 1, b, a + b);
    }
}


