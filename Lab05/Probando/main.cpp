#include <iostream>

#include <iostream>

#include "RedSocial.h"
#include "Usuario.h"

using namespace std;

int main() {
    RedSocial redSocial;
    redSocial.cargarUsuarios("usuarios.csv");
    redSocial.generarReporteUsuarios("reporteUsuarios.txt");

    Usuario usuario;
    usuario.setCorreo("hola");
    cout<<usuario;
    return 0;
}