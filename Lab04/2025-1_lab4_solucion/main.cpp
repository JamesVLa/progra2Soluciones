#include <iostream>
#include <iomanip>
#include <cstring>
#include "BibliotecaGenerica.h"
#include "BibliotecaRegistros.h"
#include "BibliotecaEnteros.h"
using namespace std;

int main() {
    void *lista;

    creaLista(lista,leenum,calsificaentero,"numeros.txt");
    imprimeLista(lista,imprimenum,"Repnum.txt");
    //
    creaLista(lista,leeregistro,calsificaregistro,"RegistroDeFaltas1.csv");
    imprimeLista(lista,imprimeregistro,"Repfalta.txt");
    return 0;

}