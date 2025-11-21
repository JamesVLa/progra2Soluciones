//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_PEDIDOESPECIAL_H
#define PROYECTO_PEDIDOESPECIAL_H
#include "Pedido.h"


class PedidoEspecial:public Pedido{
    private:
    double descuento;
    public:
    PedidoEspecial();
    PedidoEspecial(int codigo);
    PedidoEspecial(const PedidoEspecial& orig);
    ~PedidoEspecial()= default;
    PedidoEspecial& operator=(const PedidoEspecial& orig);

    void lee(ifstream& arch)override;
    void imprime(ostream &arch) override;
    void setDescuento(double descuento);
    double getDescuento()const;
};


#endif //PROYECTO_PEDIDOESPECIAL_H