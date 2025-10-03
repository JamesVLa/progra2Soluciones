//
// Created by SEMACS on 22/9/2025.
//

#ifndef LAB_05_2024_2_SOLUCION_LISTACONREGISTROS_H
#define LAB_05_2024_2_SOLUCION_LISTACONREGISTROS_H
#include "enum.h"
using namespace std;


bool leeregistros(ifstream& arch,void*&dato);
int compruebaregistro(void*dato1,void*dato2);
bool leeordenes(ifstream &arch,void*&posicion,void*&elemento);
void imprimeregistros(ofstream& arch,void*nodo);
char* leerCadenaExacta(ifstream &arch,int max,char delimitador);

#endif //LAB_05_2024_2_SOLUCION_LISTACONREGISTROS_H