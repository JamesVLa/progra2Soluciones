/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class Principal {
    public static void main(String[] args){
        Alumno alumnoA=new Alumno();
        alumnoA.setCodigo(12);
        alumnoA.setNombre("HOLA");
        Alumno alumnoB=new Alumno();
        alumnoB.setCodigo(12);
        alumnoB.setNombre("HOLA");
        System.out.println(alumnoA.equals(alumnoB));
    }
}
