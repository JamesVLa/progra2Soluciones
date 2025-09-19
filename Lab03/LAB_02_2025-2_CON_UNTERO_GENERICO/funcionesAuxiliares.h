//
// Created by Admin on 18/9/2025.
//

#ifndef LAB_02_2025_2_CON_UNTERO_GENERICO_FUNCIONESAUXILIARES_H
#define LAB_02_2025_2_CON_UNTERO_GENERICO_FUNCIONESAUXILIARES_H
#include <fstream>

using namespace std;

void cargarCategorias(const char *nombreArch,void *&categorias);
void leerCategoria(ifstream &arch,void**&categoria);
char*leerCadenaExacta(ifstream &arch,int max,char delimitador);
void incrementarCategorias(void **&registroCategorias,int &cantdatos,int &capacidad);
void cargarStreamers(const char *nombreArch,void *&streamers);
void leerStreamer(ifstream &arch,void**&streamer);
void incrementarStreamers(void **&registroStreamers,int &cantdatos,int &capacidad);
void cargarComentarios(const char*nombreArch,void*&comentarios);
void leerComentario(ifstream &arch,void**&comentario);
void cargarEtiquetas(ifstream &arch,void**&etiquetas);
bool leerEtiqueta(ifstream &archivo,char *&etiqueta);
void incrementarComentarios(void**&regComentarios,int &cantdatos,int& capacidad);
void imprimirReporte(void *categorias,void *streamers,void *comentarios,const char *nombreArch);
void imprimirStreamers(void* streamers,void* comentarios,char* codigoCategoria,ofstream &arch);

#endif //LAB_02_2025_2_CON_UNTERO_GENERICO_FUNCIONESAUXILIARES_H