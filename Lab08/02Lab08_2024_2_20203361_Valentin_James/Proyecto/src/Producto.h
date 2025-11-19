//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_PRODUCTO_H
#define PROYECTO_PRODUCTO_H

#include "Comunes.h"

class Producto {
private:
    char* nombre;
    double precio;
    public:
    Producto();
    Producto(const Producto& producto);

    virtual ~Producto();
    Producto& operator=(const Producto& producto);

    virtual void lee(ifstream& arch);
    virtual void imprime(ostream& arch);
    void getNombre(char* nom) const;
    void setNombre(const char * nombre);
    double getPrecio() const;
    void setPrecio(double precio);

    virtual Producto* clone() const = 0;
    virtual bool validar(int num)const =0;
};


#endif //PROYECTO_PRODUCTO_H