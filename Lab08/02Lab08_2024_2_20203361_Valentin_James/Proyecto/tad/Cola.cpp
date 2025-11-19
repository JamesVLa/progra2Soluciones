//
// Created by james on 13/11/2025.
//

#include "Cola.h"

Cola::Cola() {
    longitud=0;
    cabeza=nullptr;
    cola=nullptr;
}
Cola::~Cola() {
    while (!esVacio()) {
        desencolar();
    }
}

bool Cola::esVacio() const{
    return longitud==0;
}
void Cola::Encolar(const DetalleComanda &aux) {
    Nodo *nuevo=new Nodo(aux);
    if (esVacio()) {
        cabeza=cola=nuevo;
    } else {
        cola->sig=nuevo;
        cola=nuevo;
    }
    longitud++;
}

DetalleComanda Cola::desencolar() {
    Nodo *temp=cabeza;
    DetalleComanda dato=temp->dato;

    cabeza=cabeza->sig;
    delete temp;
    longitud--;
    if (esVacio()) {
        cola=nullptr;
    }
    return dato;
}

// void Cola::imprimir(ofstream &arch) {
//     Nodo* aux=cabeza;
//     while (aux !=nullptr){
//         aux->dato.imprimir(arch);
//         aux=aux->sig;
//     }
// }

void Cola::imprimir(ofstream &arch) {
    Cola colaAux;
    if (esVacio()) {
        arch<<" La cola esta vacia"<<endl;
        return;
    }
    while (!esVacio()) {
        DetalleComanda datoExtr=desencolar();
        datoExtr.imprimir(arch);
        colaAux.Encolar(datoExtr);
    }
    while (!colaAux.esVacio()) {
        DetalleComanda datoRest=colaAux.desencolar();
        Encolar(datoRest);
    }
}

void Cola::eliminar(int num) {
    Cola colaAux;
    if (esVacio()) {
        return;
    }
    while (!esVacio()) {
        DetalleComanda datoExtr=desencolar();
        if (!datoExtr.validar(num)) {
            colaAux.Encolar(datoExtr);
        }

    }
    while (!colaAux.esVacio()) {
        DetalleComanda datoRest=colaAux.desencolar();
        Encolar(datoRest);
    }
}
