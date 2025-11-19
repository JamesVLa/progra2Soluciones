//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_COLA_H
#define PROYECTO_COLA_H
#include "Nodo.h"


class Cola {
    int longitud;
    Nodo* cabeza;
    Nodo* cola;
public:
    Cola();
    ~Cola();

    void Encolar(const DetalleComanda & aux);
    DetalleComanda desencolar();
    void imprimir(ofstream& arch);
    void eliminar(int num);
    bool esVacio()const;
};


#endif //PROYECTO_COLA_H