//
// Created by SEMACS on 2/10/2025.
//

#ifndef INC_2025_1_LAB4_SOLUCION_BIBLIOTECAGENERICA_H
#define INC_2025_1_LAB4_SOLUCION_BIBLIOTECAGENERICA_H

using namespace std;

void creaLista(void *&lista,bool(*leer)(ifstream &arch,void *&dato),int (*clasificar)(void*dato)
                ,const char* nombreArch);
void generaLista(void*&lista);
void insertaLista(int numeroBloque,void *&lista,void*&dato);
void imprimeLista(void *lista,void (*imprimir)(ofstream &arch,void*dato,int numIteracion),const char *nombreARch);

#endif //INC_2025_1_LAB4_SOLUCION_BIBLIOTECAGENERICA_H