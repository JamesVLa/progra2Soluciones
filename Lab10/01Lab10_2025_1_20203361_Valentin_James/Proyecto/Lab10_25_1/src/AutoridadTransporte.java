
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


//import java.util.List;
//import java.util.ArrayList
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author james
 */
public class AutoridadTransporte {
    private final List<Propietario> propietarios;
    private final List<Vehiculo> vehiculos;
    private final List<Captura> capturas;
    private final List<RegistroInfraccion> regInfracciones;
    private final Scanner arch; 

    public AutoridadTransporte() {
        this.propietarios = new ArrayList<>();
        this.vehiculos = new ArrayList<>();
        this.capturas = new ArrayList<>();
        this.regInfracciones = new ArrayList<>();
        this.arch = new Scanner(System.in);
    }
    
    public AutoridadTransporte(final String nombreArchivo) throws FileNotFoundException{
        this.propietarios = new ArrayList<>();
        this.vehiculos = new ArrayList<>();
        this.capturas = new ArrayList<>();
        this.regInfracciones = new ArrayList<>();
        
        this.arch = new Scanner(new File(nombreArchivo));
    }
    
    public void cargarDatos(){
        this.cargarPropietarios();
        this.cargarVehiculos();
        this.cargarCapturas();
    }
    
    private void cargarPropietarios(){
        while(true){
           Propietario prop=new Propietario();
           prop.cargar(arch);
           propietarios.add(prop);
           if(!arch.hasNextInt())break;
        }
        arch.next();
    }
    
    private void cargarVehiculos(){
        int dniProp;
        while(true){
            Vehiculo veh = new Vehiculo();
            veh.cargar(arch);
            if(veh.getPlaca()==null)break;
            dniProp=arch.nextInt();
            veh.setPropietario(this.buscarPropietario(dniProp));
            vehiculos.add(veh);
        }
    }
    
    private Propietario buscarPropietario(int dni){
        for (Propietario p:this.propietarios){
            if(p.getDni() == dni){
                return p;
            }
        }
        return null;
    }
    
    private void cargarCapturas(){
        while(arch.hasNext()){
            Captura cap=new Captura();
            cap.cargar(arch);
            capturas.add(cap);
        }
    }
    
    
    public void procesarCapturas(){
        for (Captura cap: capturas){
            this.procesaCaptura(cap);
        }
    }
    
    private void procesaCaptura(final Captura cap){
        double vel=cap.getVelocidad();
        int km=cap.getKm();
        Vehiculo veh=buscarVehiculo(cap.getPlaca());
        
        Carril carril=cap.getCarril();
        boolean velocidadPermitida=carril.velocidadPermitida(km, vel);
        boolean vehiculoPermitido=carril.vehiculoPermitido(veh.getCategoria());
        
        if(!velocidadPermitida){
            regInfracciones.add(new RegistroInfraccion("M20",963.00,50,cap,veh));
        }
        if(!vehiculoPermitido){
            regInfracciones.add(new RegistroInfraccion("G29",428.00,50,cap,veh));
        }
        
    }
    
    private Vehiculo buscarVehiculo(String placa){
        for (Vehiculo veh: vehiculos){
            if(veh.getPlaca().equals(placa)){
                return veh;
            }
        }
        return null;
    }
    public void imprimirInfracciones(){
        for (RegistroInfraccion infraccion : regInfracciones){
            System.out.println(infraccion);
        }
    }
}
