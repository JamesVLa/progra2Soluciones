//
// Created by james on 29/09/2025.
//

#ifndef PROBANDO_REDSOCIAL_H
#define PROBANDO_REDSOCIAL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Usuario.h"

using namespace std;

class RedSocial {
    Usuario* usuarios;
    int cantUsuarios;
public:
    RedSocial();

    void cargarUsuarios(const char*);
    void generarReporteUsuarios(const char*) const;
};


#endif //PROBANDO_REDSOCIAL_H