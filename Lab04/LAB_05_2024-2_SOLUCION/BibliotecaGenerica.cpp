//
// Created by SEMACS on 22/9/2025.
//
#include <iomanip>
#include <iostream>
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"


using namespace std;

void crealista(void *&lista,bool (*leeDatos)(ifstream& arch,void*&dato),const char*nombreArch) {
    ifstream arch(nombreArch,ios::in);
    if (not arch.is_open()) {
        cout<< "Error opening file " << nombreArch << endl;
    }

    void**auxLista=new void *[3];
    auxLista[INICIO]=nullptr;//inicio
    auxLista[FIN]=nullptr;
    auxLista[NUMNODOS]=new int(0);
    lista=auxLista;
    void*buffer;
    int cantDatos=0;
    while (leeDatos(arch,buffer)) {
        insertarSiguiente(lista,auxLista[FIN],buffer);
        cantDatos++;
    }
    auxLista[NUMNODOS]=new int(cantDatos);

}

bool esListaVacia(void*lista) {
    void**auxLista=(void**)lista;
    return auxLista[INICIO]==nullptr && auxLista[FIN]==nullptr && *(int*)auxLista[NUMNODOS]==0;
}

void insertarSiguiente(void *lista,void *nodo,void *dato) {
    void**auxLista=(void**)lista;
    void **nuevoNodo=new void *[2];
    void **dupla=new void *[2];
    dupla[DATO]=dato;
    dupla[ARREGLO]=nullptr;
    nuevoNodo[DUPLA]=dupla;
    nuevoNodo[SIGUIENTE]=nullptr;//por si se inserta al final
    if (nodo==nullptr) {
        if (esListaVacia(lista)) {
            auxLista[INICIO]=nuevoNodo;
            auxLista[FIN]=nuevoNodo;
            auxLista[NUMNODOS]=new int(1);
        }
        else {
            nuevoNodo[SIGUIENTE]=auxLista[INICIO];
            auxLista[INICIO]=nuevoNodo;
        }
    }
    else {
        void**auxNodo=(void**)nodo;
        nuevoNodo[SIGUIENTE]=auxNodo[SIGUIENTE];
        auxNodo[SIGUIENTE]=nuevoNodo;
        if (nodo==auxLista[FIN]) { // en el caso que se inserte al final
            auxLista[FIN]=nuevoNodo;
        }
    }

}

void cargalista(void *lista, int (*comprueDato)(void*dato1,void*dato2),
    bool (*leerREgistros)(ifstream &arch,void*&posicion,void*&elemento),const char*nombreArch) {
    ifstream arch(nombreArch,ios::in);
    if (not arch.is_open()) {
        cout<< "Error opening file " << nombreArch << endl;
    }
    void*posDatoDupla,*elementoArreglo,*direcDato;
    void**auxLista=(void**)lista,*recorrido;;

    while (leerREgistros(arch,posDatoDupla,elementoArreglo)) {
        recorrido=auxLista[INICIO];
        while (recorrido!=nullptr) {
            if (comprueDato(posDatoDupla,recorrido)==0)break;
            void**auxNodo=(void**)recorrido;
            recorrido=auxNodo[SIGUIENTE];
        }
        if (recorrido!=nullptr) {
            insertarEleEnArreglo(recorrido,elementoArreglo);
        }
    }
}

void insertarEleEnArreglo(void *recorrido,void*elementoArreglo) {
    void **auxNodo=(void**)recorrido;
    void**auxDupla=(void**)auxNodo[DUPLA];
    int cantDatos=0;
    void**auxArreglo=(void**)auxDupla[ARREGLO];

    if (auxDupla[ARREGLO]!=nullptr) {

        for (int i=0;auxArreglo[i]!=nullptr;i++) {
            cantDatos++;
        }
    }

    void **nuevoArreglo=new void *[cantDatos+2];
    for (int i=0;i<cantDatos;i++) {
        nuevoArreglo[i]=auxArreglo[i];
    }
    nuevoArreglo[cantDatos]=elementoArreglo;
    nuevoArreglo[cantDatos+1]=nullptr;

    delete[] auxArreglo;
    auxDupla[ARREGLO]=nuevoArreglo;
}
void muestralista(void *lista,void (*imprir)(ofstream& arch,void*nodo),const char*nombreArch) {
    ofstream arch(nombreArch,ios::out);
    if (not arch.is_open()) {
        cout<< "Error opening file " << nombreArch << endl;
    }
    void**auxLista=(void**)lista;

    void *recorrido=auxLista[INICIO];

    while (recorrido!=nullptr) {
        imprir(arch,recorrido);
        void**auxNodo=(void**)recorrido;
        recorrido=auxNodo[SIGUIENTE];
    }

}