#include <iostream>
#include "funciones/sobrecargaOp.h"
#include "funciones/CadenaDeCaracteres .h"

using namespace std;
int main() {
    CadenaDeCaracteres cad1;
    ifstream arch1("infracciones de transito.txt",ios::in);
    ofstream arch2("reporte.txt",ios::out);
    int numero;
    arch1>>numero;
    arch1>>cad1;
    arch2<<cad1;
    return 0;
}