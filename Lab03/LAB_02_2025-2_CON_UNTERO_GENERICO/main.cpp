#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "funcionesAuxiliares.h"

using namespace std;

int main() {
    void* categorias;
    cargarCategorias("categorias.csv",categorias);

    void*streamers;
    cargarStreamers("streamers.csv",streamers);
    void *comentarios;
    cargarComentarios("comentarios.csv",comentarios);

    imprimirReporte(categorias,streamers,comentarios,"ReporteFinal.txt");
    return 0;
}