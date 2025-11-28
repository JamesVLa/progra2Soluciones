//
// Created by james on 28/11/2025.
//

#include "Flota.h"

void Flota::cargaflota() {
    ifstream arch;
    aperturaArchivoEntrada(arch,"data/Vehiculos.csv");
    NVehiculo aux;

    while (arch>>aux) {
        vflota.push_back(aux);
    }
}
// 42157219,OTS.581,5,2.5
// 13245501,AWB.345,1,3
// …
// Cliente, Cod del Producto, cantidad, peso del pedido.
void Flota::cargapedidos() {
    ifstream arch;
    aperturaArchivoEntrada(arch,"data/Pedidos3.csv");
    int codCliente;
    while (arch>>codCliente) {
        arch.ignore();
        for (auto &cli:vflota) {
            if (cli.esCliente(codCliente)) {
                cli.ingresaPed(arch);
            }
        }
    }
}
void Flota::muestracarga() {
    ofstream arch;
    aperturaArchivoSalida(arch,"reportes/reportes.txt");

    for (auto veh:vflota) {
        veh.imprime(arch);
        arch<<endl;
    }
}


