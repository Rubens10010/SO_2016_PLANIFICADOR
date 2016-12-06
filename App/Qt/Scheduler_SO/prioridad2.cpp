#include "prioridad2.h"

namespace algoritmos{

/**
 * @brief Prioridad2::siguientePaso := Muestra lo que sucedera en 1 seg si la simulacion trabaja con este algoritmo
 * @param tiempoSimulacion : Tiempo actual de la simulacion
 * @return Proceso en el que la CPU esta trabajando
 */

proceso Prioridad2::siguientePaso(short tiempoSimulacion)
{

    actualizarColaListos(tiempoSimulacion); // agregar procesos nuevos a la cola de listos

    /****
     * retornar el proceso actual a la cola de listos para asegurarnos que el proceso con mayor prioridad
     * sera trabajado primero.
     ***/

    if(tiempoSimulacion != 0 && proceso_actual.getTiempoRestante()!=0)
        ColaListos->agregarProceso(proceso_actual);
    if(ColaListos->size()>1)
        ColaListos->ordenarPorPrioridad();
    if(ColaListos->estaVacio())
        throw -2;   // Error cola vacia
    return trabajarEnCPU(tiempoSimulacion);
}

}
