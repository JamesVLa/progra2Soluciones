
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class Captura extends Registro{
    private String placa;
    private double velocidad;
    private Carril carril;
    private double latidud;
    private double longitud;
    private String region;
    private String provincia;
    private int km;
    private String fecha;
    private String hora;
    private String codigoCamara;
    
    @Override
    public void cargar(Scanner archivo){
        this.placa=archivo.next();
        this.velocidad=archivo.nextDouble();
        this.carril=getCarril(archivo.nextInt());
        this.latidud=archivo.nextDouble();
        this.longitud=archivo.nextDouble();
        this.region=archivo.next();
        this.provincia=archivo.next();
        this.km=archivo.nextInt();
        this.fecha=archivo.next();
        this.hora=archivo.next();
        this.codigoCamara=archivo.next();
    }
    
    @Override
    public void imprimir(){
        System.out.println(this);
    }
    public Carril getCarril(int num){
        return switch (num){
            case 1 -> new CarrilEmergencia();
            case 2 -> new CarrilLento();
            case 5 -> new CarrilRapido();
            default -> new CarrilEstandar();
        };
    }
    
    @Override
    public String toString(){
        return "Placa: "+placa
                +"\n Velocidad: " + velocidad + " km/h"
                +"\n Carril: "+ carril.getTipo()
                +"\n Ubicacion: Lat "+latidud + ", Lon "+longitud
                +"\n Region: "+ region
                +"\n Provincia:" + provincia
                +"\n Kilometro: " + km
                +"\n Fecha: "+fecha
                +"\n Hora: " + hora
                +"\n Código Cámara: "+ codigoCamara + "\n";
    }
    
    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public double getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(double velocidad) {
        this.velocidad = velocidad;
    }

    public Carril getCarril() {
        return carril;
    }

    public void setCarril(Carril carril) {
        this.carril = carril;
    }

    public double getLatidud() {
        return latidud;
    }

    public void setLatidud(double latidud) {
        this.latidud = latidud;
    }

    public double getLongitud() {
        return longitud;
    }

    public void setLongitud(double longitud) {
        this.longitud = longitud;
    }

    public String getRegion() {
        return region;
    }

    public void setRegion(String region) {
        this.region = region;
    }

    public String getProvincia() {
        return provincia;
    }

    public void setProvincia(String provincia) {
        this.provincia = provincia;
    }

    public int getKm() {
        return km;
    }

    public void setKm(int km) {
        this.km = km;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getHora() {
        return hora;
    }

    public void setHora(String hora) {
        this.hora = hora;
    }

    public String getCodigoCamara() {
        return codigoCamara;
    }

    public void setCodigoCamara(String codigoCamara) {
        this.codigoCamara = codigoCamara;
    }
   
    
}
