    using namespace  std;
    #include <iostream>
    #include "funcionesAux/operacionesSobrecargadas.h"

int main() {
    CadenaDeCaracteres cad{};
    !cad;

    cad <= "Valentina Gutierrez";

    CadenaDeCaracteres cad2 {};
    cad2 <= "Hola Mundo";
    CadenaDeCaracteres cad3 {};
    cad3 <= cad2;

    cad += " - ";
    cad += cad2;

    return 0;
}