#include "fcfs.h"

namespace algoritmos{

/**
 * @brief FCFS::FCFS := Pasa la cola de procesos a la clase base para su inicializacion
 * @param colaProcesos : Cola de procesos que van a ser trabajados
 */

FCFS::FCFS(Cola colaProcesos) : MisAlgoritmos(colaProcesos)
{
}

/**
 * @brief siguientePaso := Muestra lo que sucede en un paso de la simulacion usando este algoritmo
 * @param tiempoSimulacion := tiempo actual de la simulacion
 * @return : Proceso en el que la CPU estaba trabajando
 */

proceso FCFS::siguientePaso(short tiempoSimulacion)
{

    actualizarColaListos(tiempoSimulacion);
    if(!ocupada)
    {
        if(ColaListos->estaVacio())
               //throw -2;    // error 2
            return algoritmos::nul;
        ocupada = true;
        setProcesoActual();
        proceso_actual.setComienzo(tiempoSimulacion);
    }
    return trabajarEnCPU(tiempoSimulacion);

}

/**
 * @brief FCFS::trabajarEnCPU := Trabaja el proceso actual en la CPU por un tiempo de simulacion
 * @param tiempoSimulacion : Tiempo actual de la simulacion
 * @return : procso actual en el que el CPU esta trabajando
 */

proceso FCFS::trabajarEnCPU(short tiempoSimulacion)
{
    proceso_actual.procesoTrabajado(tiempoSimulacion);
    if(proceso_actual.getTiempoRestante() == 0) // establece la flag de ocupada en falso
        ocupada = false;
    return proceso_actual;
}

}
