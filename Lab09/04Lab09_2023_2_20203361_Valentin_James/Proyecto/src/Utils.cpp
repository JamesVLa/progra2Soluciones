//
// Created by james on 28/11/2025.
//

#include "Utils.h"

void imprimirLinea(ofstream &arch,char c, int tam) {
    for(int i=0;i<tam;i++) {
        arch<<c;
    }
    arch<<endl;
}

void aperturaArchivoEntrada(ifstream &arch,const char*nomb) {
    arch.open(nomb,ios::in);
    if(!arch.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
}
void aperturaArchivoSalida(ofstream &arch, const char *nomb) {
    arch.open(nomb,ios::out);
    if(!arch.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
}