#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"
#include "ListaconRegistros.h"

using namespace std;
int main() {
    void *lista;

    crealista(lista,leenumeros,"numeros1.txt");
    cargalista(lista, compruebanumero,leeregnumeros,"numeros2.txt");
    muestralista(lista,imprimenumeros,"repnum.txt");
    //
    crealista(lista,leeregistros,"Repartidores.csv");
    cargalista(lista, compruebaregistro,leeordenes,"ordenes.csv");
    muestralista(lista,imprimeregistros,"registros.txt");

    return 0;
}