//
// Created by james on 27/11/2025.
//

#include "Utils.h"

void archivoEntrada(ifstream &arch, const char *nomb) {
    arch.open(nomb,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nomb<<endl;
    }
}

void archivoSaida(ofstream &arch, const char *nomb) {
    arch.open(nomb,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nomb<<endl;
    }
}