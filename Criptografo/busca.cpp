//
// Created by Santiago on 24/04/2025.
//
int busca(char* P, char* S) {
    // Calculamos las longitudes de los strings
    int m = 0; // Longitud del patrón P
    int n = 0; // Longitud del string S

    // Calcular longitud de P
    while (P[m] != '\0') {
        m++;
    }

    // Calcular longitud de S
    while (S[n] != '\0') {
        n++;
    }

    // Si el patrón es más largo que el string, no puede estar contenido
    if (m > n) {
        return -1;
    }

    // Para cada posición posible en S
    for (int i = 0; i <= n - m; i++) {
        // Asumimos que encontramos el patrón
        int j;

        // Verificamos si el patrón coincide desde la posición i
        for (j = 0; j < m; j++) {
            if (S[i + j] != P[j]) {
                // Si encontramos un carácter diferente, este no es el lugar
                break;
            }
        }

        // Si llegamos al final del patrón, lo encontramos
        if (j == m) {
            return i; // Retornamos la posición donde comienza el patrón
        }
    }

    // Si llegamos aquí, no encontramos el patrón
    return -1;
}
