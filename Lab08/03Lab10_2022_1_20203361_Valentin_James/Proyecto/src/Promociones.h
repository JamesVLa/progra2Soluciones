//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_PROMOCIONES_H
#define PROYECTO_PROMOCIONES_H
#include "../tad/Lista.h"


class Promociones {
    Lista Lpedidos;
    public:
    Promociones()=default;
    ~Promociones()=default;
    void leePedidos();
    void actualizaPedidos();
    void imprimePedidos();
};


#endif //PROYECTO_PROMOCIONES_H