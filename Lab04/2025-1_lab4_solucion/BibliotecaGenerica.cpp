//
// Created by SEMACS on 2/10/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaGenerica.h"

using namespace std;

void creaLista(void *&lista,bool(*leer)(ifstream &arch,void *&dato),int (*clasificar)(void*dato)
                ,const char* nombreArch) {
    ifstream arch(nombreArch,ios::in);
    if(!arch.is_open()) {
        cout << "Error opening file " << nombreArch << endl;
    }
    void *dato;
    generaLista(lista);
    int numeroBloque;
    while(leer(arch,dato)) {
        numeroBloque = clasificar(dato);
        insertaLista(numeroBloque,lista,dato);
    }

}

void generaLista(void*&lista) {
    void **auxLista=new void *[2];
    void **bloquue1=new void *[2];
    void **bloquue2=new void *[2];
    bloquue1[0]=nullptr;
    bloquue2[0]=nullptr;
    bloquue1[1]=bloquue2;
    bloquue2[1]=nullptr;
    auxLista[0]=bloquue1;
    auxLista[1]=bloquue2;
    lista=auxLista;
}
void insertaLista(int numeroBloque,void *&lista,void*&dato) {
    void **auxNodo;
    void **auxLista=(void**)lista;
    if (numeroBloque==1) {//Si se inserta en el bloque 1 de la lista
        auxNodo=(void**)auxLista[0];
        if (auxNodo[0]==nullptr) {
            auxNodo[0]=dato;
        }
        else {
            void*recorrido=auxLista[0];
            void *anterior;
            while (recorrido!=auxLista[1]) {
                auxNodo=(void**)recorrido;
                anterior=recorrido;
                recorrido=auxNodo[1];
            }
            void **nuevoNodo=new void*[2];
            nuevoNodo[0]=dato;
            nuevoNodo[1]=recorrido;
            auxNodo=(void**)anterior;
            auxNodo[1]=nuevoNodo;
        }
    }
    else {//si se inserta en el bloque 2 de la lista
        auxNodo=(void**)auxLista[1];
        if (auxNodo[0]==nullptr) {
            auxNodo[0]=dato;
        }
        else {
            void*recorrido=auxLista[1];
            void *anterior;
            while (recorrido!=nullptr) {
                auxNodo=(void**)recorrido;
                anterior=recorrido;
                recorrido=auxNodo[1];
            }
            void **nuevoNodo=new void*[2];
            nuevoNodo[0]=dato;
            nuevoNodo[1]=nullptr;
            auxNodo=(void**)anterior;
            auxNodo[1]=nuevoNodo;
        }
    }
}

void imprimeLista(void *lista,void (*imprimir)(ofstream &arch,void*dato,int numIteracion),const char *nombreARch) {
    ofstream arch(nombreARch,ios::out);
    if (!arch.is_open()) {
        cout << "Error opening file " << nombreARch << endl;
    }
    void **auxLista=(void**)lista;
    void **auxNodo=(void**)auxLista[0];
    int i=0;
    while (auxNodo!=nullptr) {
        imprimir(arch, auxNodo[0],i);
        auxNodo=(void**)auxNodo[1];
        i++;
    }
}