//
// Created by james on 6/11/2025.
//

#include "MinisterioDeTransportes.h"

#include <cstring>

#include "Comunes.h"
#include <iostream>
MinisterioDeTransportes::MinisterioDeTransportes() {
    for (int i=0; i<10; i++) {
        this->zonas[i] = nullptr;
    }
    cantidad_centros = 0;
}

MinisterioDeTransportes::~MinisterioDeTransportes() {
    for (int i=0; i<10; i++) {
        liberarCadena(this->zonas[i]);
    }
}

void MinisterioDeTransportes::apertura_archivo_leer(ifstream &arch, const char *nombre_archivo) {
    arch.open(nombre_archivo,ios::in);
    if (not arch.is_open()) {
        cout<<"No se pudo abrir el archivo "<<nombre_archivo<<endl;
        exit(1);
    }
}
void MinisterioDeTransportes::apertura_archivo_escribir(ofstream &arch, const char *nombre_archivo) {
    arch.open(nombre_archivo,ios::out);
    if (not arch.is_open()) {
        cout<<"No se pudo abrir el archivo "<<nombre_archivo<<endl;
        exit(1);
    }
}
int MinisterioDeTransportes::obtener_ruta(const char *carpeta_base, const char *tipo, const char *zona, char *ruta) const {
    if (carpeta_base==nullptr || tipo==nullptr || zona==nullptr) return 0;
    ruta[0]='\0';
    strcat(ruta,carpeta_base);
    strcat(ruta,"/");
    strcat(ruta,tipo);
    strcat(ruta,"_");
    strcat(ruta,zona);
    strcat(ruta,".csv");
    return 1;
}
void MinisterioDeTransportes::cargar_drones(const char *ruta_base) {
    ifstream archZonas,archDrones;
    char nombreZona[50];
    apertura_archivo_leer(archZonas,"Datos/Zonas.txt");
    while (archZonas.getline(nombreZona,50)) {
        this->zonas[this->cantidad_centros]=miString(nombreZona);
        char ruta[200];
        obtener_ruta(ruta_base, "Drones", nombreZona, ruta);
        apertura_archivo_leer(archDrones,ruta);
        char tipo[30];
        cout<<zonas[this->cantidad_centros]<<endl;
        while (true) {
            archDrones.getline(tipo, 30, ',');
            if (archDrones.eof()) break;
            centros[cantidad_centros].leer(archDrones, tipo);
            cout<<tipo<<endl;
        }
        cout<<endl;
        this->cantidad_centros++;
        archDrones.close();
    }
}
void MinisterioDeTransportes::procesar_todos_los_eventos(const char *ruta_base) {
    char ruta[50];
    for (int i=0; i<this->cantidad_centros; i++) {
        obtener_ruta(ruta_base,"Eventos",this->zonas[i],ruta);

    }
}
void MinisterioDeTransportes::imprimir(const char *nombre_archivo) {

}






