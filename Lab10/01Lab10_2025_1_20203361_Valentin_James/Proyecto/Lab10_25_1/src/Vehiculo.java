
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class Vehiculo extends Registro{
    private String placa;
    private String marca;
    private String modelo;
    private int anhoFb;
    private String categoria;
    private Propietario propietario;
    
    @Override
    public void cargar(Scanner archivo){
        String texto =archivo.next();
        if(texto.equals("FIN"))return;
        this.placa=texto;
        this.marca=archivo.next();
        this.modelo=archivo.next();
        this.anhoFb=archivo.nextInt();
        this.categoria=archivo.next();
    }
    
    @Override
    public void imprimir(){
        System.out.println(this);
    }
    
    @Override
    public String toString(){
        return "Placa: "+ placa
                + "\n Marca: "+ marca 
                + "\n Modelo: " + modelo 
                + "\n Año de Fabricación: "+ anhoFb 
                + "\n Categoría: " + categoria 
                + "\n";
    }
    
    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAnhoFb() {
        return anhoFb;
    }

    public void setAnhoFb(int anhoFb) {
        this.anhoFb = anhoFb;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public Propietario getPropietario() {
        return propietario;
    }

    public void setPropietario(Propietario propietario) {
        this.propietario = propietario;
    }
}
