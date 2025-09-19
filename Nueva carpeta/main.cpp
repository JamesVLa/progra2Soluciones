#include <iostream>
#include "funcionesAux.h"
int main() {
    void* comentarios;
    cargaComentarios("comentarios.csv",comentarios);
    imprimeComentarios("prueba.txt",(const void*)comentarios);
    return 0;
}