
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class Propietario extends Registro{

    private int dni;
    private String nombre;
    private String apellidos;
    private String direccion;
    
    @Override
    public void cargar(Scanner archivo){
        if(archivo.hasNextInt()){
            this.dni=archivo.nextInt();
            this.nombre=archivo.next();
            this.apellidos=archivo.next();
            this.direccion=archivo.next();
        }
    }
    
    @Override
    public void imprimir(){
        System.out.println(this);
    }
    
    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }
    
    @Override
    public String toString(){
        return "DNI: "+ dni + "\n Nombres: " + nombre + "\n Apellidos: " + apellidos + "\n Direccion: "+ direccion+ "\n";
    }
    
//    @Override
//    public String toString(){
//        String resultado="";
//        resultado +=String.format("DNI: %d\n",dni);
//        return resultado;
//    }
}
