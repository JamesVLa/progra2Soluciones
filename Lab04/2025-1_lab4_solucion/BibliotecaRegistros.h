//
// Created by SEMACS on 2/10/2025.
//

#ifndef INC_2025_1_LAB4_SOLUCION_BIBLIOTECAREGISTROS_H
#define INC_2025_1_LAB4_SOLUCION_BIBLIOTECAREGISTROS_H

using namespace std;
bool leeregistro(ifstream &arch,void*& dato);
int calsificaregistro(void *dato);
void imprimeregistro(ofstream &arch,void*dato,int numIteracion);
char* leerCadenaExacta(ifstream &arch,int max,char delimitador);

#endif //INC_2025_1_LAB4_SOLUCION_BIBLIOTECAREGISTROS_H