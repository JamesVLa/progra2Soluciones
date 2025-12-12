
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public  class AlumnoRegular extends Alumno{
    private String especialidad;
    private String facultad;
    
    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        especialidad=archivo.next();
        facultad=archivo.next();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.printf(String.format("%-10s\t%-30s\t%-20s\t%-55s\t%-5s", facultad,especialidad,"N/A","N/A","N/A"));
    }
    
    @Override
    public  String getPaisOrigen(){
        String pais="Perú";
        return pais;
    }
    
    @Override
    public  double calcularPrecio(Producto producto, double tipoCambio){
        
        return 0;
    }

    public String getEspecialidad() {
        return especialidad;
    }

    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    public String getFacultad() {
        return facultad;
    }

    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }
    
    
}
