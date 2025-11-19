//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_NODO_H
#define PROYECTO_NODO_H
#include "../src/DetalleComanda.h"


class Nodo {
    DetalleComanda dato;
    Nodo *sig;
public:
    Nodo();
    ~Nodo()=default;
    Nodo(const DetalleComanda& dato);
    friend class Cola;
};


#endif //PROYECTO_NODO_H