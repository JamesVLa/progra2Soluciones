//
// Created by james on 21/11/2025.
//

#include "Promociones.h"

void Promociones::leePedidos() {
    ifstream archivo("data/pedidos5.csv",ios::in);
    if (not archivo.is_open()) {
        cout<<"Error al abrir pedidos5.csv";
        exit(1);
    }
    Lpedidos.leePed(archivo);
}

void Promociones::actualizaPedidos() {
    ifstream archivo("data/promocion.csv",ios::in);
    if (not archivo.is_open()) {
        cout<<"Error al abrir promocion.csv";
        exit(1);
    }
    char c;
    int dni,fecha,dd,mm,yyyy;
    while (archivo>>dni) {
        archivo>>c>>dd>>c>>mm>>c>>yyyy;
        fecha=dd+mm*100+yyyy*10000;
        Lpedidos.actualiza(dni,fecha);
        archivo.get();
    }
}

void Promociones::imprimePedidos() {
    ofstream archivo("reportes/reporte.txt",ios::out);
    if (not archivo.is_open()) {
        cout<<"Error al abrir reporte.txt";
        exit(1);
    }
    archivo<<setw(15)<<" "<<"REPORTE DE PROMOCIONES"<<endl;
    imprimirLinea(archivo,50,'=');
    archivo<<endl;
    Lpedidos.imprimePed(archivo);
}


