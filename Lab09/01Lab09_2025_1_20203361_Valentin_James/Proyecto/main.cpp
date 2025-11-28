#include "src/Utils.h"
#include "src/MinisterioDeTransporte.h"

int main() {
    MinisterioDeTransporte ministerio;
    ministerio.cargaDeInfracciones("data/TablaDeInfracciones.csv");
    ministerio.cargaDeEmpresas("data/EmpresasRegistradas.csv");
    ministerio.cargaVehiculos("data/VehiculosRegistrados.csv");
    ministerio.cargaInfraccionesCometidas("data/InfraccionesCometidas.csv");
    ministerio.reporteDeEmpresasConInfracciones("reporte/Reporte.txt");
    ministerio.eliminaInfraccionesPagadas();
    ministerio.reporteDeEmpresasConInfracciones("reporte/ReportePostEliminacion.txt");
    return 0;
}