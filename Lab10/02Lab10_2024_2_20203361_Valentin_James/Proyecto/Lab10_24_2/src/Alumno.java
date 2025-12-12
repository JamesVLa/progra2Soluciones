
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public abstract class Alumno extends Registro{
    private int codigo;
    private String nombre;
    @Override
    public void cargar(Scanner archivo) {
        codigo= archivo.nextInt();
        nombre= archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.printf(String.format("%-15d\t%-40s", codigo,nombre));
    }
    
    public abstract String getPaisOrigen();
    public abstract double calcularPrecio(Producto producto, double tipoCambio);

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    
}
