//
// Created by SEMACS on 22/9/2025.
//
#include "ListaconEnteros.h"
#include "enum.h"
using namespace std;
// 2
// 4
// 6
bool leenumeros(ifstream& arch,void*&dato) {
    int numero;
    arch >> numero;
    if (arch.eof())return false;
    arch.ignore();
    dato=new int(numero);
    return true;
}
int compruebanumero(void*dato1,void*dato2) {
    void **auxNodo=(void**)dato2;
    void **auxDupla=(void**)auxNodo[DUPLA];
    if (*(int*)auxDupla[DATO]==*(int*)dato1) {
        return 0;
    }
    else {
        return 1;
    }
}
// 2 4
// 2 2
// 4 1
bool leeregnumeros(ifstream &arch,void*&posicion,void*&elemento) {
    int pos,eleme;
    arch >> pos ;
    if (arch.eof())return false;
    arch >> eleme;
    // arch.ignore();
    posicion=new int(pos);
    elemento=new int(eleme);
    return true;
}

void imprimenumeros(ofstream& arch,void*nodo) {
    void **auxNodo=(void**)nodo;
    void **auxDupla=(void**)auxNodo[DUPLA];
    arch<<*(int*)auxDupla[DATO]<<endl;
    if (auxDupla[ARREGLO]!= nullptr) {
        void**auxArreglo=(void**)auxDupla[ARREGLO];
        for (int i=0;auxArreglo[i]!=nullptr;i++) {
            arch<<*(int*)auxArreglo[i]<<" ";
        }
        arch<<endl;
    }
    else {
        arch<<"No tiene numeros en el arreglo."<<endl;
    }

}