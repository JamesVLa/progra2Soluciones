//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_DETALLECOMANDA_H
#define PROYECTO_DETALLECOMANDA_H
#include "Producto.h"


class DetalleComanda {
    int id;
    Producto* pedido;
public:
    DetalleComanda();
    ~DetalleComanda();
    void leer(ifstream &arch);
    void imprimir(ostream &arch);
    DetalleComanda(const DetalleComanda& orig);
    DetalleComanda& operator=(const DetalleComanda& orig);
    int getId() const;
    void setId(int id);
    bool validar(int num);
};


#endif //PROYECTO_DETALLECOMANDA_H