//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_MINISTERIODETRANSPORTES_H
#define PROYECTO_MINISTERIODETRANSPORTES_H
#include "CentralDeMonitoreo.h"

class MinisterioDeTransportes {
    CentralDeMonitoreo centros[10];
    char* zonas[10];
    int cantidad_centros;

    void apertura_archivo_leer(ifstream& arch,const char* nombre_archivo);
    void apertura_archivo_escribir(ofstream& arch,const char* nombre_archivo);
    int obtener_ruta(const char* carpeta_base, const char* tipo,
        const char* zona, char* ruta)const;

    public:
    MinisterioDeTransportes();
    ~MinisterioDeTransportes();
    //---------Metodos extra------
    void cargar_drones(const char* ruta_base);
    void procesar_todos_los_eventos(const char* ruta_base);
    void imprimir(const char* nombre_archivo);
};

#endif //PROYECTO_MINISTERIODETRANSPORTES_H