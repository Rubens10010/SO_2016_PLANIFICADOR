#include "roundrobin.h"

namespace  algoritmos {

/**
 * @brief RoundRobin::RoundRobin := Pasa la cola de procesos a la clase base para su inicializacion.
 * @param ColaProcesos : Cola de procesos a trabajar
 * @param quantum : Tiempo del quantum entre procesos
 */

RoundRobin::RoundRobin(Cola ColaProcesos, short quantum):MisAlgoritmos(ColaProcesos)
{
    this->Quantum = quantum;
}

/**
 * @brief RoundRobin::siguientePaso := Lo que sucede en un paso usando este algoritmo
 * @param tiempoSimulacion : Tiempo actual de la simulacion
 * @return : Proceso de la CPU en el que trabajaba
 */

proceso RoundRobin::siguientePaso(short tiempoSimulacion)
{
    actualizarColaListos(tiempoSimulacion);
    if(!ocupada)
    {
        if(tiempoSimulacion!=0 && proceso_actual.getTiempoRestante()!=0)
            ColaListos->agregarProceso(proceso_actual);
        if(ColaListos->estaVacio())
            throw -2;
        tiempoProceso = Quantum;    // reinicia el quantum
        ocupada = true;
        setProcesoActual(); // muevev el primer proceso en la cola de listos para ser trabajado
    }
    return trabajarEnCPU(tiempoSimulacion);
}

/**
 * @brief trabajarEnCPU := trabaja el proceso actual en la CPU para un paso del tiempo de simulacion
 * @param tiempoSimulacion : Tiempo actual de la simulacion
 * @return: Proceso en el que la CPU esta trabajando
 */

proceso RoundRobin::trabajarEnCPU(short tiempoSimulacion)
{
    proceso_actual.procesoTrabajado(tiempoSimulacion);
    tiempoProceso--;
    if(tiempoProceso == 0 || proceso_actual.getTiempoRestante()==0)
        ocupada = false;
    return proceso_actual;
}

}
