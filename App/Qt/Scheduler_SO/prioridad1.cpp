#include "prioridad1.h"

namespace algoritmos{

/**
 * @brief Prioridad1::siguientePaso := muestra lo que sucede cuando la simulacion avanza usando este algoritmo
 * @param tiempoSimulacion
 * @return  proceso en el que la CPU esta trabajando
 */

proceso Prioridad1::siguientePaso(short tiempoSimulacion)
{

    actualizarColaListos(tiempoSimulacion); // agregar procesos que llegaron recientemente
    if(ColaListos->size() > 1)
        ColaListos->ordenarPorPrioridad();
    if(!ocupada)    // cola no apropiativa
    {
        if(ColaListos->estaVacio())
            throw -2;   // error cola vacia
        ocupada = true;
        setProcesoActual(); // mover el primer proceso en la cola de listos para ser trabajado
    }
    return trabajarEnCPU(tiempoSimulacion);

}

/**
 * @brief Prioridad1::trabajarEnCPU := Trabaja en el proceso actual de la CPU por un tiempo 1
 * @param tiempoSimulacion := Tiempo actual de la simulacion
 * @return El proceso actual en el que la CPU esta trabajando
 */


proceso Prioridad1::trabajarEnCPU(short tiempoSimulacion)
{

    proceso_actual.procesoTrabajado(tiempoSimulacion);
    if(proceso_actual.getTiempoRestante() == 0) // si proceso esta finalizado
        ocupada = false;
    return proceso_actual;

}

}
