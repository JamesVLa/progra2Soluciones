//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_ARBOL_H
#define PROYECTO_ARBOL_H
#include "Nodo.h"


class Arbol {
private:
    Nodo* raiz;
    void insertarR(Nodo*& nodoIns, Dron* aux);
    void imprimirR(ofstream &arch, Nodo *nodoImp)const;
    void contarR(Nodo* nodoEv,int& numSemaf,int& numEstac)const;
    void actualizarR(Nodo* nodoEv,int& numSemaf,int& numEstac)const;
    public:
    void lee(ifstream& arch);
    void imprimir(ofstream& arch)const;
    void insertar(Dron *aux);
    void actualiza();

    Arbol();
    ~Arbol();
};


#endif //PROYECTO_ARBOL_H