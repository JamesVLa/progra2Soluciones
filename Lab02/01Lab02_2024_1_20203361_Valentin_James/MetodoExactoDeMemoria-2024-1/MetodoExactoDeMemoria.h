//
// Created by james on 7/09/2025.
//

#ifndef METODOEXACTODEMEMORIA_2024_1_METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_2024_1_METODOEXACTODEMEMORIA_H
// char ***libros,***pedidosLibros;
// int **stock, **pedidosClientes;
// bool **pedidosAtendidos;
#include <fstream>
using namespace std;
void lecturaDeLibros (const char* nomArch,char *** &libros, int ** &stock);
void pruebaDeLecturaDeLibros(const char* nomArch,
                             char* const* const* libros,
                             const int* const* stock);
bool imprimeLibro(ofstream &arch, char const* const* datosLibro);
bool imprimeStock(ofstream &arch,int const *datosStock);

// void pruebaDeLecturaDeLibros(const char* nomArch,const char*** libros,const int** stock);

// bool imprimeLibro(ofstream &arch, const char**datosLibro);
// bool imprimeStock(ofstream &arch,const int*datosStock);
bool leeLibro(ifstream& arch,char**&datoLibro);
bool leeStock(ifstream& arch,int*&datoStock);
char* leeCadena(ifstream &arch, const char delim);
#endif //METODOEXACTODEMEMORIA_2024_1_METODOEXACTODEMEMORIA_H