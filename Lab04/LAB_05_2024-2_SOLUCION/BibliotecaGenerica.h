//
// Created by SEMACS on 22/9/2025.
//

#ifndef LAB_05_2024_2_SOLUCION_BIBLIOTECAGENERICA_H
#define LAB_05_2024_2_SOLUCION_BIBLIOTECAGENERICA_H
#include <fstream>
#include "enum.h"
using namespace std;
void crealista(void *&lista,bool (*leeDatos)(ifstream& arch,void*&dato),const char*nombreArch);
bool esListaVacia(void*lista);
void insertarSiguiente(void *lista,void *nodo,void *dato);
void cargalista(void *lista, int (*comprueDato)(void*dato1,void*dato2),
    bool (*leerREgistros)(ifstream &arch,void*&posicion,void*&elemento),const char*nombreArch);
void insertarEleEnArreglo(void *recorrido,void*elementoArreglo);
void muestralista(void *lista,void (*imprir)(ofstream& arch,void*nodo),const char*nombreArch);

#endif //LAB_05_2024_2_SOLUCION_BIBLIOTECAGENERICA_H