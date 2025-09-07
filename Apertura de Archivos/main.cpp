#include "Biblioteca/AperturaDeArchivos.h"
void porReferencia(int*& x) {
    // Afecta al puntero original ya que es una referencia
    x = new int;
    *x = 20;
}

void porValor(int* x) {
    // No afecta al puntero original ya que es una copia
    x = new int;
    *x = 20;
    delete x;
}

int main() {
    // int arr[5]{1,3,2,4,5};
    int* p;
    // p=arr;


    /*** Inicio: Paso de punteros por valor o por referencia ***/
    p = new int; // reservar memoria dinámicamente en el heap
    *p = 10; // asignar valor a la dirección de memoria a la que apunta p
    porValor(p); // pasar puntero por valor
    cout << *p << endl; // sigue siendo 10, ya que la función no afecta al puntero original

    porReferencia(p); // pasar puntero por referencia
    cout << *p << endl; // ahora es 20, ya que la función afecta al puntero original
    // ifstream entrada;
    // ofstream salida;
    //
    // AperturaDeUnArchivoDeTextosParaLeer(entrada, "entrada.txt");
    // AperturaDeUnArchivoDeTextosParaEscribir(salida, "salida.txt");
    return 0;
}
