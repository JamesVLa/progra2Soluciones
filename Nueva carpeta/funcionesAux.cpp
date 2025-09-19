//
// Created by james on 17/09/2025.
//

#include "funcionesAux.h"
#include <cstring>
#include <iostream>

char* leeCadDelim(ifstream &arch,char delim) {
    char *ptrCad,cad[1024];
    arch.getline(cad,1024,delim);
    if (arch.eof())return nullptr;
    ptrCad = new char[strlen(cad)+1];
    strcpy(ptrCad,cad);
    return ptrCad;
}

void cargaComentarios(const char *nomArch, void * &comentarios) {
    ifstream arch(nomArch, ios::in);
    void **publicacion = nullptr;
    void *publi;
    int num = 0, capacidad = 0;
    while (leerPublicacion(arch, publi)) {
        if (num == capacidad)incrementarPubli(publicacion, num, capacidad);
        publicacion[num]=publi;
        num++;
    }

}
bool leerPublicacion(ifstream &arch, void*& publi){
    char* codigo;
    codigo=leeCadDelim(arch,'.');
    if (arch.eof())return false;
    char* izq,*der,**menciones;
    izq=leeCadDelim(arch,'[');
    cargarMenciones(arch,menciones);
    der=leeCadDelim(arch,'\n');
    char* texto;
    texto=new char[strlen(izq)+strlen(der)+1];
    strcpy(texto,izq);
    strcat(texto,der);
    void** datosPubli=new void*[3];
    datosPubli[0]=codigo;
    datosPubli[1]=texto;
    datosPubli[2]=menciones;
    return true;
}
void cargarMenciones(ifstream& arch,char** &menciones) {
    char *buff[10];
    int num=0;
    char*mencion;
    while (leeMencion(arch,mencion)) {
        buff[num]=mencion;
        num++;
    }
    menciones = new char*[num+1]{};

    for (int i=0;i<num;i++) {
        menciones[i]=buff[i];
    }
}

bool leeMencion(ifstream &arch,char* &mencion) {
    char buffer[50];
    int num=0;

    if (arch.peek() == ']') {
        arch.get();
        return false;
    }
    while (arch.peek() != ' ' && arch.peek() != ']') {
        buffer[num++] = arch.get();
    }
    buffer[num]='\0';
    mencion=new char[strlen(buffer)+1];
    strcpy(mencion,buffer);
    if (arch.peek() == ' ') arch.get();
    return true;
}
void incrementarPubli(void**&publi, int num, int &capacidad) {
    capacidad+=5;
    if (publi==nullptr) {
        publi=new void*[capacidad+1]{};
    }
    else {
        void **aux=new void*[capacidad+1]{};
        for (int i=0;i<num;i++) {
            aux[i]=publi[i];
        }
        delete[] publi;
        publi=aux;
    }
}


void imprimeComentarios(const char* nomArch,const void* comentarios) {
    ofstream(nomArch,ios::out);
    void**vv=(void**)comentarios;
    void**v;
    for (int i=0;vv[i];i++) {
        v=(void**)vv[i];
    }
}