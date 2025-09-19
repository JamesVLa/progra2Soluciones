//
// Created by james on 16/09/2025.
//

#ifndef LAB04_2024_2_CAFETERIA_H
#define LAB04_2024_2_CAFETERIA_H
#include <iostream>
#include <fstream>

using namespace std;
char* leeCadenaDelim(ifstream &arch, char delim);
void cargarInventario(const char *nomArch, void *&inventario);
bool cargarInsumoInventario(ifstream &arch, void *&insumo);

void probarCargaInventario(const char *nomArch, const void *inventario);

void cargarMenu(const char *nomArch, void *&menu);
bool cargarBebida(ifstream &arch, void *&insumo);

void pruebaCargaMenu(const char *nomArch, const void *menu);






bool cargarInsumoBebida(ifstream& archivo, const void* inventario, void*& insumo, char*& codigoBebida);
void agregarInsumoBebida(void*& bebida, void* insumo);
void* buscarInsumo(const char* codigoInsumo, const void* inventario);
void* buscarBebida(const char* codigoBebida, const void* menu);
void incrementarInsumos(void**& insumos, int num, int inc);
int numInsumosBebida(const void* insumos);
void actualizarMenu(const char *nomArch, void *&inventario, void *&menu);

void reporteMenu(const char *nomArch, const void *menu);
#endif //LAB04_2024_2_CAFETERIA_H