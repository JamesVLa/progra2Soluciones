//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_NODO_H
#define PROYECTO_NODO_H
#include "../src/Dron.h"
//class Arbol;

class Nodo {
    Dron *dron;
    Nodo *izq;
    Nodo *der;
public:
    friend class Arbol;
    Nodo();
    ~Nodo();
};


#endif //PROYECTO_NODO_H