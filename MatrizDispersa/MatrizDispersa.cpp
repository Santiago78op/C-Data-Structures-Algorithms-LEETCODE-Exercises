//
// Created by 72358 on 14/02/2025.
//

#include "MatrizDispersa.h"

#include <utility>


MatrizDispersa::MatrizDispersa(std::string nombre) : nombre(std::move(nombre)) {
    eFilas = new List_Encabezado("LISTA DE FILAS");
    eColumnas = new List_Encabezado("LISTA DE COLUMNAS");
}
