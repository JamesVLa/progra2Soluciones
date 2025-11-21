//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_PEDIDO_H
#define PROYECTO_PEDIDO_H
#include "Comunes.h"

class Pedido {
    private:
    int codigo;
    char* nombre;
    int cantidad;
    int dni;
    int fecha;
    double total;
public:
    Pedido();
    virtual ~Pedido();
    Pedido(const Pedido &p);
    Pedido& operator=(const Pedido &p);
    bool operator<(const Pedido &p) const;
    bool operator>(const Pedido &p) const;
    virtual void lee(ifstream& arch);
    virtual void imprime(ostream& arch);
    int getCodigo()const;
    const char* getNombre()const;
    int getCantidad()const;
    int getDni()const;
    int getFecha()const;
    double getTotal()const;

    void setCodigo(int codigo);
    void setNombre(const char* nombre);
    void setCantidad(int cantidad);
    void setDni(int dni);
    void setFecha(int fecha);
    void setTotal(double total);
};


#endif //PROYECTO_PEDIDO_H