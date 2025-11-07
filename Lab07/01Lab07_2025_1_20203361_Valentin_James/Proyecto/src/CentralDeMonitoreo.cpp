//
// Created by james on 6/11/2025.
//

#include "CentralDeMonitoreo.h"

CentralDeMonitoreo::CentralDeMonitoreo() {
    cantidad_multas_registradas=0;
    total_multas_acumuladas=0;
}
void CentralDeMonitoreo::leer(ifstream &arch, const char *tipo) {
    flota.cargar_drone(arch,tipo);
}
void CentralDeMonitoreo::cargar_infracciones(ifstream &arch) {

}
void CentralDeMonitoreo::imprimir(ofstream &arch) {

}
