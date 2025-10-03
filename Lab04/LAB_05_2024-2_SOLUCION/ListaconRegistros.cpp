//
// Created by SEMACS on 22/9/2025.
//
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ListaconRegistros.h"
using namespace std;
// JNV387,Justino Norabuena Virginia Karina,Motocicleta
// PRT150,Pairazaman Raffo Tatiana Delicia,Bicicleta
// SYI157,Sam Yallico Ines ,Motocicleta
bool leeregistros(ifstream& arch,void*&dato) {
    char*cod,*nombre,*unidad;
    cod=leerCadenaExacta(arch,8,',');
    if (arch.eof())return false;
    nombre=leerCadenaExacta(arch,100,',');
    unidad=leerCadenaExacta(arch,30,'\n');
    void **repartidor=new void*[3];
    repartidor[0]=cod;
    repartidor[1]=nombre;
    repartidor[2]=unidad;
    dato=repartidor;
    return true;
}
int compruebaregistro(void*dato1,void*dato2) {
    void **auxNodo=(void**)dato2;
    void **auxDupla=(void**)auxNodo[DUPLA];
    void **auxRepartidor=(void**)auxDupla[DATO];
    if (strcmp((char*)auxRepartidor[0],(char*)dato1)==0) {
        return 0;
    }
    else {
        return 1;
    }
}

// 12484697,2,AD-546,LAF361
// 12484697,1,PO-751,LAF361
// 12484697,3,EN-766,LAF361
bool leeordenes(ifstream &arch,void*&posicion,void*&elemento) {
    int dni,cantidad;
    char*codPlato,*codRepartidor,c;
    arch >> dni ;
    if (arch.eof())return false;
    arch >> c>>cantidad>>c;
    codPlato=leerCadenaExacta(arch,10,',');
    codRepartidor=leerCadenaExacta(arch,10,'\n');
    posicion=codRepartidor;
    void**nuevaOrden=new void*[3];
    nuevaOrden[0]=new int(dni);
    nuevaOrden[1]=new int (cantidad);
    nuevaOrden[2]=codPlato;
    elemento=nuevaOrden;
    return true;
}
void imprimeregistros(ofstream& arch,void*nodo) {
    void **auxNodo=(void**)nodo;
    void **auxDupla=(void**)auxNodo[DUPLA];
    void **auxRepartidor=(void**)auxDupla[DATO];
    arch<<setw(20)<<left<<(char*)auxRepartidor[0]<<(char*)auxRepartidor[1]<<endl;

    if (auxDupla[ARREGLO]!= nullptr) {
        void**auxArreglo=(void**)auxDupla[ARREGLO];
        arch<<"Ordenes:"<<endl;
        for (int i=0;auxArreglo[i]!=nullptr;i++) {
            void**auxOrden=(void**)auxArreglo[i];
            arch<<setw(20)<<left<<*(int*)auxOrden[0]<<right<<setw(4)<<*(int*)auxOrden[1]
            <<setw(15)<<(char*)auxOrden[2]<<endl;
        }
        arch<<endl;
    }
    else {
        arch<<"No tiene ordenes "<<endl;
    }
}
char* leerCadenaExacta(ifstream &arch,int max,char delimitador) {
    char buffer[max],*cad;
    arch.getline(buffer,max,delimitador);
    if (arch.eof())return nullptr;
    cad=new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}