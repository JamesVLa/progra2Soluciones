//
// Created by Admin on 18/9/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "funcionesAuxiliares.h"

using namespace std;

void cargarCategorias(const char *nombreArch,void *&categorias) {
    ifstream arch(nombreArch,ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
    }

    void**registroCategorias=nullptr;
    void**categoria;


    int cantdatos=0,capacidad=0;
    while (true) {
        leerCategoria(arch,categoria);
        if (arch.eof()) break;
        if (cantdatos==capacidad) {
            incrementarCategorias(registroCategorias,cantdatos,capacidad);
        }
        registroCategorias[cantdatos-1]=categoria;
        cantdatos++;
    }
    registroCategorias[cantdatos]=nullptr;
    categorias=registroCategorias;
}

// UM1000,Just Chatting,Casual conversations; reactions; and hangouts without a main game.
// DN1001,League of Legends,5v5 MOBA; ranked climbs; pro play analysis; and coaching.
void leerCategoria(ifstream &arch,void**&categoria) {
    char *codigo,*nombre,*descripcion;
    codigo=leerCadenaExacta(arch,10,',');
    if (arch.eof()) return;
    nombre=leerCadenaExacta(arch,100,',');
    descripcion=leerCadenaExacta(arch,100,'\n');
    categoria=new void*[3];
    categoria[0]=codigo;
    categoria[1]=nombre;
    categoria[2]=descripcion;
}
char*leerCadenaExacta(ifstream &arch,int max,char delimitador) {
    char buffer[max],*cad;
    arch.getline(buffer,max,delimitador);
    if (arch.eof()) return nullptr;
    cad=new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void incrementarCategorias(void **&registroCategorias,int &cantdatos,int &capacidad) {
    capacidad+=5;
    if (registroCategorias==nullptr) {
        registroCategorias=new void*[capacidad];
        registroCategorias[0]=nullptr;
        cantdatos++;
    }
    else {
        void**aux=new void*[capacidad];
        for (int i=0;i<cantdatos;i++) {
            aux[i]=registroCategorias[i];
        }
        delete[] registroCategorias;
        registroCategorias=aux;
    }
}
void cargarStreamers(const char *nombreArch,void *&streamers) {
    ifstream arch(nombreArch,ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
    }

    void**registroStreamers=nullptr;
    void**streamer;


    int cantdatos=0,capacidad=0;
    while (true) {
        leerStreamer(arch,streamer);
        if (arch.eof()) break;
        if (cantdatos==capacidad) {
            incrementarStreamers(registroStreamers,cantdatos,capacidad);
        }
        registroStreamers[cantdatos-1]=streamer;
        cantdatos++;
    }
    registroStreamers[cantdatos]=nullptr;
    streamers=registroStreamers;
}

// xQcOW,8/1/2022,13/8/2025,6196161750,27716,3246298,QA1080
// summit1g,25/12/2021,25/8/2025,6091677300,25610,5310163,MK1092
// Gaules,13/6/2023,14/8/2025,5644590915,10976,1767635,CY1025
void leerStreamer(ifstream &arch,void**&streamer) {
    char*cuenta,*codigoCategoria,c;
    int diaC,mesC,anhoC,diaT,mesT,anhoT,promEspec;
    long long tiempoTotalreducido,seguidores;
    cuenta=leerCadenaExacta(arch,40,',');
    if (arch.eof())return;
    arch>>diaC>>c>>mesC>>c>>anhoC>>c>>diaT>>c>>mesT>>c>>anhoT>>c;
    arch>>tiempoTotalreducido>>c>>promEspec>>c>>seguidores>>c;
    codigoCategoria=leerCadenaExacta(arch,10,'\n');
    streamer=new void*[7];
    streamer[0]=cuenta;
    streamer[1]=codigoCategoria;
    int fechaCreacion=anhoC*10000+mesC*100+diaC;
    streamer[2]=new int (fechaCreacion);
    int fechaUTrans=anhoT*10000+mesT*100+diaT;
    streamer[3]=new int (fechaUTrans);
    streamer[4]=new int (promEspec);
    streamer[5]=new long long(tiempoTotalreducido);
    streamer[6]=new long long(seguidores);

}
void incrementarStreamers(void **&registroStreamers,int &cantdatos,int &capacidad) {
    capacidad+=5;
    if (registroStreamers==nullptr) {
        registroStreamers=new void*[capacidad];
        registroStreamers[0]=nullptr;
        cantdatos++;
    }
    else {
        void**aux=new void*[capacidad];
        for (int i=0;i<cantdatos;i++) {
            aux[i]=registroStreamers[i];
        }
        delete[] registroStreamers;
        registroStreamers=aux;
    }
}
void cargarComentarios(const char*nombreArch,void*&comentarios) {
    ifstream arch(nombreArch,ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
    }

    void**regComentarios=nullptr;
    void**comentario;


    int cantdatos=0,capacidad=0;
    while (true) {
        leerComentario(arch,comentario);
        if (arch.eof()) break;
        if (cantdatos==capacidad) {
            incrementarComentarios(regComentarios,cantdatos,capacidad);
        }
        regComentarios[cantdatos-1]=comentario;
        cantdatos++;
    }
    comentarios=regComentarios;
}

// ab7f2910,Can someone please help me understand [Castro_1021 loltyler1] how to do trading properly?
// 3d1a843f,[summit1g Gaules] Imagine doing this on a proper Road to Glory that's just a crazy thought.
// e2b1002c,Wow there are [xQcOW summit1g] 5110 people in here!
void leerComentario(ifstream &arch,void**&comentario) {
    char*usuario,*text1=nullptr,*text2=nullptr,*textCompleto;

    usuario=leerCadenaExacta(arch,40,',');
    if (arch.eof())return;
    void **etiquetas;
    if (arch.peek()=='[') {
        arch.ignore();
        cargarEtiquetas(arch,etiquetas);
        textCompleto=leerCadenaExacta(arch,100,'\n');
    }
    else {
        text1=leerCadenaExacta(arch,100,'[');
        cargarEtiquetas(arch,etiquetas);
        if (arch.peek()=='\n') {
            textCompleto=new char[strlen(text1)+1];
            strcpy(textCompleto,text1);
        }
        else {
            text2=leerCadenaExacta(arch,100,'\n');
            textCompleto=new char[strlen(text1)+strlen(text2)+1];
            strcpy(textCompleto,text1);
            strcat(textCompleto,text2);
        }
    }
    comentario=new void*[3];
    comentario[0]=usuario;
    comentario[1]=textCompleto;
    comentario[2]=etiquetas;

}

void cargarEtiquetas(ifstream &arch,void**&etiquetas) {
    void *buffer[10];// considerando que hya un maximo de 10 etiquetas
    int num=0;
    char*etiqueta;

    while (leerEtiqueta(arch,etiqueta)) {
        buffer[num]=etiqueta;
        num++;
    }
    etiquetas=new void*[num+1]{};
    for (int i=0;i<num;i++) {
        etiquetas[i]=buffer[i];
    }
}

bool leerEtiqueta(ifstream &archivo,char *&etiqueta) {
    char buffer[50];//poneiendo un tope a lo largo que puede ser una etiqueta
    int num=0;
    //si elsguiente caracter es ']' no hay mas etiquetas
    if (archivo.peek()==']') {
        archivo.ignore();
        return false;
    }

    while (archivo.peek()!=' ' & archivo.peek()!=']') {
        buffer[num]=archivo.get();
        num++;
    }
    buffer[num]='\0';
    etiqueta=new char[strlen(buffer)+1];
    strcpy(etiqueta,buffer);
    //para comnsumir le espacio entre cada una de las etiquetas consumimos el espacio que hay en medio
    if (archivo.peek()==' ') {
        archivo.ignore();
    }
    return true;
}
void incrementarComentarios(void**&regComentarios,int & cantdatos,int& capacidad) {
    capacidad+=5;
    if (regComentarios==nullptr) {
        regComentarios=new void*[capacidad];
        regComentarios[0]=nullptr;
        cantdatos++;
    }
    else {
        void**aux=new void*[capacidad];
        for (int i=0;i<capacidad;i++) {
            aux[i]=regComentarios[i];
        }
        delete [] regComentarios;
        regComentarios=aux;
    }
}

void imprimirReporte(void *categorias,void *streamers,void *comentarios,const char *nombreArch) {
    ofstream arch(nombreArch,ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
    }
    void**regCat=(void**) categorias;
    for (int i=0;regCat[i]!=nullptr;i++) {
        void**ptcategory=(void**) regCat[i];
        arch<<"*****************************************"<<(char*)ptcategory[1]<<"****************************************"<<endl;
        imprimirStreamers(streamers,comentarios,(char*)ptcategory[0],arch);
    }
}

void imprimirStreamers(void* streamers,void* comentarios,char* codigoCategoria,ofstream &arch) {
    void**regStreamers=(void**) streamers;
    arch<<setw(30)<<left<<"CUENTA"<<setw(30)<<"FECHA CREACION"<<setw(30)<<"FECHA ULT. STREAM"<<setw(50)<<"TIEMPO REP."
    <<setw(25)<<"CANT. SEGUID."<<"ETIQUETAS"<<endl;
    for (int i=0;regStreamers[i]!=nullptr;i++) {
        void**ptrStreamers=(void**) regStreamers[i];
        if (strcmp((char*)ptrStreamers[1],codigoCategoria)==0) {
            arch<<setw(30)<<left<<(char*)ptrStreamers[0]<<setw(30)<<*(int*)ptrStreamers[2]<<setw(30)
            <<*(int*)ptrStreamers[3]<<setw(50)<<*(long long*)ptrStreamers[5]
            <<setw(25)<<*(long long*)ptrStreamers[6]<<"ETIQUETAS"<<endl;
        }
    }
}