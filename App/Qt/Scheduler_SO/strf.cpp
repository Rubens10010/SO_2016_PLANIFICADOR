#include "strf.h"

namespace  algoritmos {

/**
 * @brief algoritmos::siguientePaso := Muestra lo que sucede cuando el algoritmo es aplicado a un paso de la simulacion
 * @param tiempoSimulacion := Tiempo actual de la simulacion
 * @return Proceso que esta siendo trabajado
 */

proceso STRF::siguientePaso(short tiempoSimulacion){

    actualizarColaListos(tiempoSimulacion);
    /* Agregar el proceso actual de regreso a la cola listos para compararlo con los nuevos procesos */

    if(tiempoSimulacion != 0 && proceso_actual.getTiempoRestante()!=0)
        ColaListos->agregarProceso(proceso_actual);
    if(ColaListos->size()>1)
        ColaListos->ordenarPorMenorTiempoRestante();
    if(ColaListos->estaVacio())
        throw -2;
    setProcesoActual();
    return trabajarEnCPU(tiempoSimulacion); // utilizar el  default
}

}
