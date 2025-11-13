//
// Created by james on 12/11/2025.
//

#include "Central.h"

void Central::carga() {
    ifstream archDrones("data/Drones.csv");
    if (not archDrones.is_open()) {
        cerr << "Errore apertura drones" << endl;
        exit(1);
    }

    while (true) {
        ADrones.lee(archDrones);
        if (archDrones.eof()) break;
    }
}
void Central::actualiza() {
    this->ADrones.actualiza();

}
void Central::muestra() {
    ofstream arch("reporte/reporte.txt",ios::out);
    arch<<fixed<<setprecision(2);
    arch<<setw(50)<<"REPORTE DE DRONES"<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
    arch<<setw(10)<<" "<<left<<setw(10)<<"Codigo"
    <<setw(15)<<"Ubicacion"<<setw(15)<<"Capacidad"<<"Velocidad/Zona/Luz"<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
    this->ADrones.imprimir(arch);
}



