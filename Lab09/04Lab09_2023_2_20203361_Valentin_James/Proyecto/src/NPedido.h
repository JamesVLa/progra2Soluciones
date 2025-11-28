//
// Created by james on 28/11/2025.
//

#ifndef PROYECTO_NPEDIDO_H
#define PROYECTO_NPEDIDO_H
#include "Utils.h"

class NPedido {
private:
    string codigo;
    int cantidad;
    double peso;
    public:
    NPedido();
    NPedido(const NPedido& p);
    NPedido& operator=(const NPedido &p);
    ~NPedido()=default;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch)const;
    string getCodigo() const;
    void setCodigo(const string &codigo);

    int getCantidad() const;
    void setCantidad( int cantidad);

    double getPeso() const;
    void setPeso( double peso);

};


#endif //PROYECTO_NPEDIDO_H