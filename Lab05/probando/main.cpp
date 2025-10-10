#include "prueba.h"
#include <iostream>
#include <cstring>
using namespace std;

void modificarTexto(char *&texto, const char *nuevo) {
    delete[] texto; // borramos memoria
    texto = new char[strlen(nuevo) + 1];
    strcpy(texto, nuevo);
    cout << "(modificarTexto) Se reasigno el texto con: " << nuevo << endl;
}

void borrarTexto(char *texto) {
    cout << "\nse borra el texto :" << texto << endl;
    delete[] texto; // cuidado con esto
    cout << "(delete externo ejecutado)" << endl;
}
int main() {
    prueba p;
    p.setTextoBien("Texto inicial seguro");
    p.setTextoMal("Texto inicial inseguro");

    cout << "\nAntes de get:" << endl;
    cout << "  textoBien (copia): " << p.getTextoBien() << endl;
    cout << "  textoMal (objeto): " << p.getTextoMal() << endl;

    char *copiaSegura = p.getTextoBien(); // copia en heap
    char *punteroInterno = p.getTextoMal(); // puntero al atributo real

    cout << "\nAntes de modificar:" << endl;
    cout << "  texto1:" << p.getTextoBien() << endl;
    cout << "  textoBien (copia): " << copiaSegura << endl;
    cout << "  textoMal (objeto): " << p.getTextoMal() << endl;
    cout << "  textoMal (interno): " << punteroInterno << endl;

    // Modificamos ambos textos
    modificarTexto(copiaSegura, "Texto cambiado externamente (copia)");
    modificarTexto(punteroInterno, "Texto cambiado externamente (interno)");

    cout << "\nDespues de modificar:" << endl;
    cout << "  texto1:" << p.getTextoBien() << endl;
    cout << "  textoBien (copia): " << copiaSegura << endl;
    cout << "  textoMal (objeto): " << p.getTextoMal() << endl;
    cout << "  textoMal (interno): " << punteroInterno << endl;

    cout << "\nborrando memoria de variables..." << endl;
    borrarTexto(copiaSegura);
    borrarTexto(punteroInterno);
    cout<<"\nFin del main: se llama al destructor automaticamente.\n" << endl;
    return 0;
}
