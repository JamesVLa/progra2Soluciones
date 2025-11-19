//
// Created by james on 13/11/2025.
//

#include "Nodo.h"

Nodo::Nodo() {
    sig=nullptr;
}

Nodo::Nodo(const DetalleComanda &dato):Nodo() {
    this->dato=dato;
}