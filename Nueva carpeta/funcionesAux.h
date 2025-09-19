//
// Created by james on 17/09/2025.
//

#ifndef NUEVA_CARPETA_FUNCIONESAUX_H
#define NUEVA_CARPETA_FUNCIONESAUX_H
#include <fstream>
using namespace std;
char* leeCadDelim(ifstream &arch,char delim);
void cargaComentarios(const char* nomArch,void* &comentarios);

bool leerPublicacion(ifstream &arch, void*& publi);
void cargarMenciones(ifstream& arch,char** &menciones);
bool leeMencion(ifstream &arch,char* &mencion);
void incrementarPubli(void**&publi, int num, int &capacidad);

void imprimeComentarios(const char* nomArch,const void* comentarios);
#endif //NUEVA_CARPETA_FUNCIONESAUX_H