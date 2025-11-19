//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_RESTAURANTE_H
#define PROYECTO_RESTAURANTE_H
#include "../tad/Cola.h"
#include "Comunes.h"

class Restaurante {
    Cola Ccomanda;
public:
    void carga();
    void elimina(int num);
    void atiende();
    Restaurante()=default;
    ~Restaurante()=default;
};


#endif //PROYECTO_RESTAURANTE_H