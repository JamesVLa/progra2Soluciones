//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_NODO_H
#define PROYECTO_NODO_H
#include "../src/Pedido.h"

class Nodo {
private:
    Pedido* ped;
    Nodo* sig;
    Nodo* ant;
    public:
    Nodo();
    ~Nodo()=default;
    friend class Lista;
};

#endif //PROYECTO_NODO_H