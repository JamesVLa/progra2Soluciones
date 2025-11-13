//
// Created by james on 12/11/2025.
//

#include "Nodo.h"

Nodo::Nodo() {
    dron=nullptr;
    izq=nullptr;
    der=nullptr;
}

Nodo::~Nodo() {
    delete dron;
    delete izq;
    delete der;
}
