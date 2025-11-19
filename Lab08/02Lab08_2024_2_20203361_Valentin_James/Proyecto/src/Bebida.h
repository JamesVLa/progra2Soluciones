//
// Created by james on 13/11/2025.
//

#ifndef PROYECTO_BEBIDA_H
#define PROYECTO_BEBIDA_H
#include "Producto.h"


class Bebida :public Producto{
private:
    char* tamano;
    public:
    Bebida();
    ~Bebida();
    Bebida(const Bebida& b);
    void lee(ifstream &arch) override;
    void imprime(ostream &arch) override;
    Bebida& operator=(const Bebida& origen);
    void getTamano(char* tamano)const;
    void setTamano(const char* tamano);
    bool validar(int num)const;
    Producto* clone() const override;
};


#endif //PROYECTO_BEBIDA_H