//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_PEDIDOUSUAL_H
#define PROYECTO_PEDIDOUSUAL_H
#include "Pedido.h"


class PedidoUsual:public Pedido{
private:
    double descuento;
    double flete;
    public:
    PedidoUsual();
    PedidoUsual(int codigo);
    PedidoUsual(const PedidoUsual& orig);
    ~PedidoUsual()= default;
    PedidoUsual& operator=(const PedidoUsual& orig);

    void lee(ifstream& arch)override;
    void imprime(ostream &arch)override;
    void setDescuento(double descuento);
    double getDescuento()const;
    void setFlete(double flete);
    double getFlete()const;
};


#endif //PROYECTO_PEDIDOUSUAL_H