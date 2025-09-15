//
// Created by james on 7/09/2025.
//

#include "MetodoExactoDeMemoria.h"
#include <iomanip>
#include <cstring>
#include <iostream>
// char ***libros,***pedidosLibros;
// int **stock, **pedidosClientes;
// bool **pedidosAtendidos;

void lecturaDeLibros (const char* nomArch,char *** &libros, int ** &stock) {
    libros=nullptr;
    stock=nullptr;
    ifstream arch(nomArch,ios::in);
    if(!arch.is_open()) {
        cout << "Error al abrir el archivo " << nomArch << endl;
        exit(1);
    }

    char **libro[300]{};
    int *stockIni[300]{};
    int cantDatos=0;
    while (leeLibro(arch,libro[cantDatos])&&leeStock(arch,stockIni[cantDatos])) {
        cantDatos++;
    }
    libros=new char**[cantDatos+1]{};
    stock=new int*[cantDatos+1]{};
    for (int i = 0; i < cantDatos; i++) {
        libros[i]=libro[i];
        stock[i]=stockIni[i];
    }

}

bool leeLibro(ifstream& arch,char**&datoLibro) {
    char* codigo;
    char* nombre;
    char* autor;
    codigo=leeCadena(arch,',');
    if (arch.eof())return false;
    nombre=leeCadena(arch,',');
    autor=leeCadena(arch,',');
    datoLibro=new char*[3]{codigo,nombre,autor};
    return true;
}
bool leeStock(ifstream& arch,int*&datoStock) {
    int stock;
    if (arch>>stock) {
        while (arch.get()!='\n');
        datoStock=new int[2]{stock};
        return true;
    }
    return false;
}

char* leeCadena(ifstream &arch, const char delim) {
    char cad[100],*ptrCad;
    arch.getline(cad,100,delim);
    if (arch.eof())return nullptr;
    ptrCad=new char[strlen(cad)+1];
    strcpy(ptrCad,cad);
    return ptrCad;
}

void pruebaDeLecturaDeLibros(const char* nomArch,
                             char* const* const* libros,
                             const int* const* stock){
    ofstream arch(nomArch,ios::out);
    int i=0;
    arch<<left<<setw(10)<<"Codigo"<<setw(60)<<"Nombre del Libro"<<setw(40)<<"Autor"<<right<<setw(8)<<"Stock"<<setw(13)<<"No atendido"<<endl;;
    for (int i=0;imprimeLibro(arch,libros[i])&&imprimeStock(arch,stock[i]);i++);
}
bool imprimeLibro(ofstream &arch, char const* const* datosLibro) {
    if (datosLibro==nullptr)return false;
    arch<<left<<setw(10)<<datosLibro[0]<<setw(60)<<datosLibro[1]<<setw(40)<<datosLibro[2];
    return true;
}
bool imprimeStock(ofstream &arch,int const *datosStock) {
    if (datosStock==nullptr)return false;
    arch<<right<<setw(8)<<datosStock[0]<<setw(13)<<datosStock[1]<<endl;
    return true;
}

// void pruebaDeLecturaDeLibros(const char* nomArch,const char*** libros,const int** stock){
    // ofstream arch(nomArch,ios::out);
    // int i=0;
    // arch<<left<<setw(10)<<"Codigo"<<setw(60)<<"Nombre del Libro"<<setw(40)<<"Autor"<<right<<setw(4)<<"Stock"<<setw(4)<<"No atendido"<<endl;;
    // for (int i=0;imprimeLibro(arch,libros[i])&&imprimeStock(arch,stock[i]);i++);
// }

// bool imprimeLibro(ofstream &arch, const char**datosLibro) {
// if (datosLibro==nullptr)return false;
// arch<<left<<setw(10)<<datosLibro[0]<<setw(60)<<datosLibro[1]<<setw(40)<<datosLibro[2];
// return true;
// }
// bool imprimeStock(ofstream &arch,const int*datosStock) {
//     if (datosStock==nullptr)return false;
// arch<<right<<setw(8)<<datosStock[0]<<setw(13)<<datosStock[1]<<endl;
// return true;
// }