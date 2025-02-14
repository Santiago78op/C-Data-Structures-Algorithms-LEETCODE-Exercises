//
// Created by 72358 on 14/02/2025.
//

#ifndef DATA_ESTRUCTURE_C_MATRIZDISPERSA_H
#define DATA_ESTRUCTURE_C_MATRIZDISPERSA_H


#include <string>
#include "List_Encabezado.h"

class MatrizDispersa {
    public:
        std::string nombre;
        List_Encabezado* eFilas{};
        List_Encabezado* eColumnas{};

    explicit MatrizDispersa(std::string nombre);
};


#endif //DATA_ESTRUCTURE_C_MATRIZDISPERSA_H
