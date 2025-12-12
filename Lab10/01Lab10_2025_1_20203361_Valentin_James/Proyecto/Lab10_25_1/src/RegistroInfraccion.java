/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class RegistroInfraccion {
    private String codigoInfraccion;
    private double monto;
    private int puntos;
    private Captura captura;
    private Vehiculo vehiculo;

    public RegistroInfraccion(String codigoInfraccion, double monto, int puntos, Captura captura, Vehiculo vehiculo) {
        this.codigoInfraccion = codigoInfraccion;
        this.monto = monto;
        this.puntos = puntos;
        this.captura = captura;
        this.vehiculo = vehiculo;
    }
    
   
    
    @Override
    public String toString(){
        return "Registro de Infraccion de Transito " 
                + "\n Codigo de Infraccion: " + codigoInfraccion +
                "\n Monto de la Multa: "+monto+
                "\n Puntos en Licencia: "+puntos + "\n DESTINATARIO DE LA INFRACCION \n"
                +vehiculo.getPropietario() +
                "DATOS DEL VEHICULO \n" + vehiculo +
                "DATOS DE LA CAPTURA ELECTRONICA \n" + captura + "\n";
    }
    
    public String getCodigoInfraccion() {
        return codigoInfraccion;
    }

    public void setCodigoInfraccion(String codigoInfraccion) {
        this.codigoInfraccion = codigoInfraccion;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
    }

    public int getPuntos() {
        return puntos;
    }

    public void setPuntos(int puntos) {
        this.puntos = puntos;
    }

    public Captura getCaptura() {
        return captura;
    }

    public void setCaptura(Captura captura) {
        this.captura = captura;
    }

    public Vehiculo getVehiculo() {
        return vehiculo;
    }

    public void setVehiculo(Vehiculo vehiculo) {
        this.vehiculo = vehiculo;
    }
    
    
    
}
