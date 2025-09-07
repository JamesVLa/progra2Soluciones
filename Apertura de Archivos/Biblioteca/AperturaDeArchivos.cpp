//
// Created by james on 31/08/2025.
//
#include "AperturaDeArchivos.h"

// Funciones para abrir un archivo y verificar su apertura

// ********************************************************
// LA VARIABLE DE ARCHIVO NO DEBE INVOCAR AL CONSTUCTOR
// ********************************************************

void AperturaDeUnArchivoDeTextosParaLeer(ifstream &archivo,
                                         const char *nombreDelArchivo) {
    archivo.open(nombreDelArchivo, ios::in);
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo de lectura: "
             << nombreDelArchivo << endl;
        exit(1);
    }
}

void AperturaDeUnArchivoDeTextosParaEscribir(ofstream &archivo,
                                             const char *nombreDelArchivo) {
    archivo.open(nombreDelArchivo, ios::out);
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo de escritura: "
             << nombreDelArchivo << endl;
        exit(1);
    }
}