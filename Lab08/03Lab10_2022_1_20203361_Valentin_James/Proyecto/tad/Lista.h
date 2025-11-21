//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_LISTA_H
#define PROYECTO_LISTA_H
#include "Nodo.h"

class Lista {
    Nodo* lini;
    Nodo* lfin;
    public:
    Lista();
    ~Lista();
    void leePed(ifstream &arch);
    void imprimePed(ostream &arch);
    void actualiza(int dni, int fecha);
    void insertar(Pedido *p);
};

#endif //PROYECTO_LISTA_H