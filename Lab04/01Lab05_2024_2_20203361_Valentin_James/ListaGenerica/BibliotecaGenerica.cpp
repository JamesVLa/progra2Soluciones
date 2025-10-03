//
// Created by james on 23/09/2025.
//

#include "BibliotecaGenerica.h"
#include "enums.h"

void* construir() {
    void** lista = new void*[tam::listaNumCampos];
    lista[listaIndices::codCabeza]=nullptr;
    lista[listaIndices::codCola]=nullptr;
    lista[listaIndices::codNumNodos]= new int(0);

    return lista;
}
bool esListaVacia(void* lista) {
    void**aux=(void**) lista;
    return aux[listaIndices::codCabeza]==nullptr;
}
void insertaFinal(void*&lista, void* dato) {
    void** auxLista = (void**)lista;
    void** nuevoNodo=new void*[tam::nodoNumCampos];
    nuevoNodo[nodoIndices::codDato]=dato;
    nuevoNodo[nodoIndices::codSiguiente]=nullptr;

    if (esListaVacia(lista)) {
        auxLista[listaIndices::codCabeza]=nuevoNodo;
    }else {
        void** auxNodo = (void**)auxLista[listaIndices::codCola];
        auxNodo[nodoIndices::codSiguiente]=nuevoNodo;
    }
    auxLista[listaIndices::codCola]=nuevoNodo;

    int* numNodos = (int*)auxLista[listaIndices::codNumNodos];
    *numNodos=*numNodos+1;
}

