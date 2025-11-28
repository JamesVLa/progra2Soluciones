//
// Created by james on 27/11/2025.
//

#include "MinisterioDeTransporte.h"

void MinisterioDeTransporte::cargaDeInfracciones(const char *nomArch) {
    ifstream arch;
    archivoEntrada(arch,nomArch);
    Infraccion infra;
    while (arch>>infra) {
        tablaInfracciones.push_back(infra);
    }
    tablaInfracciones.sort();
}

void MinisterioDeTransporte::cargaDeEmpresas(const char *nomArch) {
    ifstream arch;
    archivoEntrada(arch,nomArch);
    Empresa emp;
    while (arch>>emp) {
        listaEmpresas.push_back(emp);
    }
    listaEmpresas.sort();
}

void MinisterioDeTransporte::cargaVehiculos(const char *nomArch) {
    ifstream arch;
    archivoEntrada(arch,nomArch);
    int dni;
    Vehiculo vAux;
    while (arch>>dni) {
        arch.ignore();
        arch>>vAux;
        for (auto &emp: listaEmpresas) {
            if (emp.getDni()==dni) {
                emp.insertar_vehiculo(vAux);
            }
        }
    }
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nomArch) {
    ifstream arch;
    archivoEntrada(arch,nomArch);
    Multa mult;
    while (arch>>mult) {
        //buscamos monto en Infracciones
        for (auto &inf: tablaInfracciones) {
            if (inf.getCodigo()==mult.getCodMulta()) {
                mult.setMulta(inf.getMulta());
            }
        }
        //buscar empresa
        for (auto &emp: listaEmpresas) {
            emp.buscarEmpresaPlacaAsigna(mult);
        }
    }

    for (auto &emp: listaEmpresas) {
        emp.ordenarMultas();
    }
}

void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nomArch) {
    ofstream arch;
    archivoSaida(arch,nomArch);
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (auto emp: listaEmpresas) {
        emp.eliminarInfraccionPagada();
    }
}