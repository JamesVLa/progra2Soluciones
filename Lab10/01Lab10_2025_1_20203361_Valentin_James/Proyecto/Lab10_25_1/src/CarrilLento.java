/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class CarrilLento extends Carril{
    @Override
    public String getTipo(){
        return "Lento";
    }
    @Override
    public double velocidadMaxima(int km){
        return 60.00;
    }
    
    @Override
    public boolean velocidadPermitida(int km, double velocidad){
        return velocidad <=velocidadMaxima(km);
    }
    @Override
    public boolean vehiculoPermitido(String categoria){
        return categoria.equals("Camion") || 
                categoria.equals("Tractor") || 
                categoria.equals("Trailer");
    }
}
