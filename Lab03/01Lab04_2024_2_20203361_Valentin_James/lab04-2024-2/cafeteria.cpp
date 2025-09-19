//
// Created by james on 16/09/2025.
//
#include "enums.h"
#include "cafeteria.h"

#include <cstring>
#include <iostream>

char* leeCadenaDelim(ifstream &arch, char delim) {
    char cadena[tam::buffer],*ptrCad;
    arch.getline(cadena,tam::buffer,delim);
    if (arch.eof())return nullptr;
    ptrCad = new char[strlen(cadena)+1];
    strcpy(ptrCad,cadena);
    return ptrCad;
}
void cargarInventario(const char *nomArch, void *&inventario) {
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void **buffer=new void *[tam::buffer]{};
    int num=0;
    while (cargarInsumoInventario(arch,buffer[num]))num++;

    void** vv = new void*[num + 1] {};
    for (int i = 0; i < num; i++) {
        vv[i] = buffer[i];
    }

    inventario = vv;

    delete[] buffer;

}
bool cargarInsumoInventario(ifstream &arch, void *&insumo) {
    char* codigo;
    codigo=leeCadenaDelim(arch,',');//I001,Café Arábica,50,kg
    if (arch.eof())return false;//Café Arábica,50,kg
    void** vv=new void*[tam::invNumCampos];
    char* nombre;
    double cantDisponible;
    char* unidadMedida;

    nombre=leeCadenaDelim(arch,',');//Café Arábica,50,kg
    arch>>cantDisponible;//50,kg
    arch.ignore();//,kg
    unidadMedida=leeCadenaDelim(arch,'\n');//kg
    vv[cps::invCodigo]=codigo;
    vv[cps::invNombre]=nombre;
    vv[cps::invCantDisponible]=new double(cantDisponible);
    vv[cps::invCantRequerida]=new double(0);
    vv[cps::invUnidadMedida]=unidadMedida;
    insumo=vv;
    return true;
}
void probarCargaInventario(const char *nomArch, const void *inventario) {
}

void cargarMenu(const char *nomArch, void *&menu) {
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void **buffer=new void *[tam::buffer]{};
    int num=0;
    while (cargarBebida(arch,buffer[num]))num++;
    void** vv = new void*[num + 1] {};
    for (int i = 0; i < num; i++) {
        vv[i] = buffer[i];
    }

    menu = vv;

    delete[] buffer;

}

bool cargarBebida(ifstream &arch, void *&insumo) {
    char *codigo;
    codigo = leeCadenaDelim(arch, ','); //B001,Espresso Doble,Un espresso intenso con una mezcla de Café Arábica y Robusta para un sabor equilibrado y fuerte,C,2.50,120

    if (arch.eof())return false; //Espresso Doble,Un espresso intenso con una mezcla de Café Arábica y Robusta para un sabor equilibrado y fuerte,C,2.50,120
    void **vv = new void *[tam::bebNumCampos];
    char *nombre;
    char *descripcion;
    char* tipoBebida;
    double precio;
    int cantVentasEstimDiar;

    nombre=leeCadenaDelim(arch,',');//Espresso Doble,Un espresso intenso con una mezcla de Café Arábica y Robusta para un sabor equilibrado y fuerte,C,2.50,120
    descripcion=leeCadenaDelim(arch,',');//Un espresso intenso con una mezcla de Café Arábica y Robusta para un sabor equilibrado y fuerte,C,2.50,120
    tipoBebida=leeCadenaDelim(arch,',');//C,2.50,120
    arch>>precio;//2.50,120
    arch.ignore();//,120
    arch>>cantVentasEstimDiar;//120
    arch.get();//\n
    vv[cps::bebCodigo]=codigo;
    vv[cps::bebNombre]=nombre;
    vv[cps::bebDescripcion]=descripcion;
    vv[cps::bebTipo]=tipoBebida;
    vv[cps::bebDisponible]=new bool(true);
    vv[cps::bebPrecio]=new double(precio);
    vv[cps::bebCantVent]=new int(cantVentasEstimDiar);
    vv[cps::bebInsumoInv]=nullptr;

    insumo = vv;
    return true;
}
void pruebaCargaMenu(const char *nomArch, const void *menu) {
}






bool cargarInsumoBebida(ifstream& archivo, const void* inventario, void*& insumo, char*& codigoBebida) {
    char* codigoInsumo;
    double cantidad;
    char* unidadMedida;

    if (!archivo.eof()) {
        codigoBebida = leeCadenaDelim(archivo,',');
        codigoInsumo = leeCadenaDelim(archivo,',');
        archivo >> cantidad;
        archivo.ignore();
        unidadMedida = leeCadenaDelim(archivo, '\n');

        void** vv = new void*[tam::insNumCapos];
        vv[cps::insCodigoInv] = buscarInsumo(codigoInsumo, inventario);
        vv[cps::insCant] = new double(cantidad);
        vv[cps::insUnidadMedida] = unidadMedida;

        insumo = vv;

        return true;
    }

    return false;
}
void* buscarInsumo(const char* codigoInsumo, const void* inventario) {
    const void** insumos = (const void**)inventario;
    void** resultado = nullptr;

    for (int i = 0; insumos[i]; i++) {
        void** insumo = (void**)insumos[i];
        char* codigo = (char*)insumo[0];

        if (strcmp(codigoInsumo, codigo) == 0) {
            resultado = insumo;
            break;
        }
    }

    return resultado;
}

void* buscarBebida(const char* codigoBebida, const void* menu) {
    const void** bebidas = (const void**)menu;
    void** resultado = nullptr;

    for (int i = 0; bebidas[i]; i++) {
        void** bebida = (void**)bebidas[i];
        char* codigo = (char*)bebida[0];

        if (strcmp(codigoBebida, codigo) == 0) {
            resultado = bebida;
            break;
        }
    }

    return resultado;
}

void agregarInsumoBebida(void*& bebida, void* insumo) {
    void** vv = (void**)bebida;
    void** insumos = (void**)vv[cps::bebInsumoInv];

    int numInsumos = numInsumosBebida(insumos);
    incrementarInsumos(insumos, numInsumos, 1);
    insumos[numInsumos++] = insumo;
    vv[cps::bebInsumoInv] = insumos;
    bebida = vv;
}

void incrementarInsumos(void**& insumos, int num, int inc) {
    int cap = num + inc;
    void** vv = (void**)insumos;
    if (vv == nullptr) {
        vv = new void*[cap + 1] {};
    }
    else {
        void** aux = new void*[cap + 1] {};
        for (int i = 0; vv[i]; i++) {
            aux[i] = vv[i];
        }
        delete[] vv;
        vv = aux;
    }
    insumos = vv;
}

int numInsumosBebida(const void* insumos) {
    int num = 0;
    const void** vv = (const void**)insumos;
    if (vv != nullptr)
        for (;vv[num];num++);

    return num;
}
void actualizarMenu(const char *nomArch, void *&inventario, void *&menu) {
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void* insumo;
    char* codigoBebida;
    while(cargarInsumoBebida(arch, inventario, insumo, codigoBebida)) {
        void* bebida = buscarBebida(codigoBebida, menu);
        agregarInsumoBebida(bebida, insumo);
    }
}

void reporteMenu(const char *nomArch, const void *menu) {
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
}