//
// Created by james on 13/11/2025.
//

#include "Restaurante.h"

void Restaurante::carga() {
    ifstream archivo("data/comandas2.csv",ios::in);
    if (not archivo.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        exit(1);
    }
    DetalleComanda detalle;
    int i=0;
    while (true) {
        detalle.leer(archivo);
        if (archivo.eof()) break;
        Ccomanda.Encolar(detalle);
    }
}
void Restaurante::atiende() {
    ofstream archivo("reportes/reporte.txt",ios::out);
    archivo<<"Detalle de Comandas:"<<endl;
    imprimirLinea(archivo,30,'=');
    Ccomanda.imprimir(archivo);

}
void Restaurante::elimina(int num) {
    Ccomanda.eliminar(num);
}



