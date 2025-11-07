
#include "src/MinisterioDeTransportes.h"

int main() {
    MinisterioDeTransportes ministerio;

    ministerio.cargar_drones("Datos");
    ministerio.procesar_todos_los_eventos("Datos");
    ministerio.imprimir("Reporte.txt");
    return 0;
}
