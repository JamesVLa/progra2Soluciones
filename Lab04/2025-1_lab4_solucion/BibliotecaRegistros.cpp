//
// Created by SEMACS on 2/10/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaRegistros.h"

using namespace std;
// 26522329,U5W-825,22/11/2019,101,SANCHEZ DEL CASTILLO FIORELLA ROSARIO
// 47844324,X7J-719,14/09/2019,101,VILCA LEE NESTOR HUGO
// 53374153,R2T-476,5/09/2019,101,SERRANO IBEROS FRANCISCO
bool leeregistro(ifstream &arch,void*& dato) {
    int licencia,fecha,dia,mes,anho,infraccion;
    char *placa,c,*nombre;
    arch >> licencia;
    if (arch.eof()) return false;
    arch.ignore();
    placa=leerCadenaExacta(arch,10,',');
    arch>>dia>>c>>mes>>c>>anho>>c>>infraccion>>c;
    nombre=leerCadenaExacta(arch,100,'\n');
    void **aux=new void*[4];
    //guardamos la fecha en un solo numero
    fecha=anho*10000+mes*100+dia;
    aux[0]=new int(fecha);
    aux[1]=new int(licencia);
    aux[2]=nombre;
    aux[3]=new int (infraccion);
    dato=aux;
    return true;

}
int calsificaregistro(void *dato) {
    void **aux=(void **)dato;
    int numero=*(int *)aux[3]/100;
    if (numero==1) {
        return 1;
    }
    else {
        return 2;
    }
}
void imprimeregistro(ofstream &arch,void*dato,int numIteracion) {
    void **aux=(void **)dato;
    if (numIteracion==0) {
        arch<<left<<setw(13)<<"FECHA"<<setw(11)<<"LICENCIA"<<setw(50)<<"NOMBRE"<<"FALTA"<<endl;
        for (int i=0;i<300;i++) {
            arch.put('=');
        }
        arch<<endl;
    }
    int anho,mes,dia,fecha;
    fecha=*(int*)aux[0];
    dia=fecha%100;
    fecha=fecha/100;
    mes=fecha%100;
    anho=fecha/100;
    arch<<anho<<'/'<<setfill('0')<<right<<setw(2)<<mes<<'/'<<setfill('0')<<setw(2)<<dia<<"    "<<setfill(' ')
    <<left<<*(int*)aux[1]<<"  "<<setw(50)<<(char*)aux[2]<<*(int*)aux[3]<<endl;


}
char* leerCadenaExacta(ifstream &arch,int max,char delimitador) {
    char buffer[max],*cad;
    arch.getline(buffer,max,delimitador);
    if (arch.eof()) return nullptr;
    cad=new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}