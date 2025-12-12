
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
class Producto extends Registro{
    private String codigo;
    private final List<Traduccion> nombres;
    private final List<Traduccion> descripciones;
    private double precio;
    private int stock;
    
    public Producto(){
        nombres= new ArrayList<>();
        descripciones= new ArrayList<>();
    }
    
    @Override
    public void cargar(Scanner archivo) {
        codigo=archivo.next();
        while(!archivo.hasNextDouble()){
            Traduccion traducNomb= new Traduccion();
            nombres.add(traducNomb.leeTraducion(archivo));
        }
        precio=archivo.nextDouble();
        while(!archivo.hasNextInt()){
            Traduccion traducDesc= new Traduccion();
            nombres.add(traducDesc.leeTraducion(archivo));
        }
        stock=archivo.nextInt();
    }
    
    @Override
    public void imprimir() {
        
    }
}
