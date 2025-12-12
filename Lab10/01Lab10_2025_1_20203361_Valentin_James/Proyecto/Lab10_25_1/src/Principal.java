
import java.io.FileNotFoundException;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class Principal {
    public static void main(String[]args) throws FileNotFoundException{
        AutoridadTransporte atu = new AutoridadTransporte("datos.txt");
        atu.cargarDatos();
        atu.procesarCapturas();
        atu.imprimirInfracciones();
    }
}
