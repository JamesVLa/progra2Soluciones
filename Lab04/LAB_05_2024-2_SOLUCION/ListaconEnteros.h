//
// Created by SEMACS on 22/9/2025.
//

#ifndef LAB_05_2024_2_SOLUCION_LISTACONENTEROS_H
#define LAB_05_2024_2_SOLUCION_LISTACONENTEROS_H
#include <fstream>
using namespace std;
bool leenumeros(ifstream& arch,void*&dato);
int compruebanumero(void*dato1,void*dato2);
bool leeregnumeros(ifstream &arch,void*&posicion,void*&elemento);
void imprimenumeros(ofstream& arch,void*nodo);
#endif //LAB_05_2024_2_SOLUCION_LISTACONENTEROS_H