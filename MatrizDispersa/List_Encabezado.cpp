//
// Created by 72358 on 14/02/2025.
//

#include <iostream>
#include "List_Encabezado.h"
using namespace std;

Nodo_Encabezado::Nodo_Encabezado(int id) : id(id) {
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->acceso = nullptr;
}

List_Encabezado::List_Encabezado(const char string[15]) {
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->length = 0;
}

List_Encabezado::~List_Encabezado() {
    Nodo_Encabezado *temp = primero;
    while (primero) {
        primero = primero->siguiente;
        delete temp;
        temp = primero;
    }
}

void List_Encabezado::insertar(Nodo_Encabezado *nuevo) {
    length++;
    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        if (nuevo->id < primero->id) {
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;
        } else if (nuevo->id > ultimo->id) {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
        } else {
            Nodo_Encabezado* temp = primero;
            while (temp->siguiente != nullptr) {
                if (nuevo->id < temp->siguiente->id) {
                    nuevo->siguiente = temp->siguiente;
                    temp->siguiente->anterior = nuevo;
                    temp->siguiente = nuevo;
                    nuevo->anterior = temp;
                    break;
                }
                temp = temp->siguiente;
            }
        }
    }
}

Nodo_Encabezado *List_Encabezado::buscar(int id) {
    Nodo_Encabezado* temp = primero;
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

void List_Encabezado::eliminar(int id) {
    Nodo_Encabezado* temp = buscar(id);
    if (temp != nullptr) {
        if (temp == primero) {
            primero = primero->siguiente;
            if (primero != nullptr) {
                primero->anterior = nullptr;
            }
        } else if (temp == ultimo) {
            ultimo = ultimo->anterior;
            if (ultimo != nullptr) {
                ultimo->siguiente = nullptr;
            }
        } else {
            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;
        }
    }
}

void List_Encabezado::imprimir() {
    Nodo_Encabezado* temp = primero;
    while (temp != nullptr) {
        cout << temp->id << " ";
        temp = temp->siguiente;
    }
}
