/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class CarrilRapido extends Carril {
    @Override
    public String getTipo(){
        return "Rapido";
    }
    @Override
    public double velocidadMaxima(int km){
        if(km<=100){
            return 120.00;
        }else if(km<=200){
            return 160.00;
        }else{
            return 140.00;
        }
    }
    public double velocidadMinima(int km){
        if(km<=100){
            return 80.00;
        }else if(km<=200){
            return 100.00;
        }else{
            return 90.00;
        }
    }
    @Override
    public boolean velocidadPermitida(int km, double velocidad){
        return velocidad <=velocidadMaxima(km) && velocidad >=velocidadMinima(km);
        
    }
    @Override
    public boolean vehiculoPermitido(String categoria){
        return 
                categoria.equals("Motocicleta") || 
                categoria.equals("Coupe") || 
                categoria.equals("SUV") || 
                categoria.equals("Camioneta") || 
                categoria.equals("Sedan") || 
                categoria.equals("Ambulancia");
    }
}
