//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_CENTRAL_H
#define PROYECTO_CENTRAL_H
#include "../tad/Arbol.h"


class Central {
    Arbol ADrones;
    public:
    Central()=default;
    ~Central()=default;
    void carga();
    void actualiza();
    void muestra();
};


#endif //PROYECTO_CENTRAL_H