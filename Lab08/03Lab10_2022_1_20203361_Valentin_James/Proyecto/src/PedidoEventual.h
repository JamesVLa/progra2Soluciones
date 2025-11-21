//
// Created by james on 21/11/2025.
//

#ifndef PROYECTO_PEDIDOEVENTUAL_H
#define PROYECTO_PEDIDOEVENTUAL_H
#include "Pedido.h"


class PedidoEventual:public Pedido{
    double flete;
    public:
    PedidoEventual();
    PedidoEventual(int codigo);
    PedidoEventual(const PedidoEventual& orig);
    ~PedidoEventual()= default;
    PedidoEventual& operator=(const PedidoEventual& orig);

    void lee(ifstream& arch)override;
    void imprime(ostream &arch) override;
    void setFlete(double flete);
    double getFlete() const;
};


#endif //PROYECTO_PEDIDOEVENTUAL_H