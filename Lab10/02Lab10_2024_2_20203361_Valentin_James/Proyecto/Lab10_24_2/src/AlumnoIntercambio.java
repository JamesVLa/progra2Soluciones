
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
public class AlumnoIntercambio extends Alumno{
    private String paisOrigen;
    private List<String> idiomas;
    private int numeroDeSemestres;
    public AlumnoIntercambio(){
        idiomas = new ArrayList<>();
    }
    
      @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        paisOrigen=archivo.next();
        while(!archivo.hasNextInt()){
            String idioma=archivo.next();
            idiomas.add(idioma);
        }
        numeroDeSemestres=archivo.nextInt();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.printf("%-10s\t%-30s\t%-24s%","N/A","N/A",paisOrigen);
        
        String listaIdiomas = "[";
        for(int i=0;i<idiomas.size();i++){
            listaIdiomas +=idiomas.get(i);
            if (i<idiomas.size()-1){
                listaIdiomas += ",";
            }
        }
        listaIdiomas += "]";
        System.out.printf("%-50s\t%-10s\t%d%n",listaIdiomas,"Semestres",numeroDeSemestres);
    }
    
    @Override
    public  String getPaisOrigen(){
        return paisOrigen;
    }
    
    @Override
    public  double calcularPrecio(Producto producto, double tipoCambio){
        
        return 0;
    }
}
