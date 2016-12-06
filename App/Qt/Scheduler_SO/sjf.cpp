#include "sjf.h"

namespace algoritmos{

/**
 * @brief algoritmos::siguientePaso := Muestra lo que sucede cuando el algoritmo es aplicado a un paso de la simulacion
 * @param tiempoSimulacion := Tiempo actual de la simulacion
 * @return Proceso que esta siendo trabajado
 */

proceso SJF::siguientePaso(short tiempoSimulacion)
{

    actualizarColaListos(tiempoSimulacion); // asegurarse que el proceso con el menor tiempo restante siempre este primero en la cola
    if(ColaListos->size() > 1)
        ColaListos->ordenarPorMenorTiempoRestante();
    if(!ocupada)
    {
        if(ColaListos->estaVacio())
            throw -2;
        ocupada = true;
        setProcesoActual(); // muevev el primer proceso en la cola de listos para ser trabajado
    }
    return trabajarEnCPU(tiempoSimulacion);

}

/**
 * @brief trabajarEnCPU := Trabaja en el proceso actual en la CPU por espacio de 1
 * @param tiempoSimulacion : Tiempo actual de la simulacion
 * @return El proceso trabajado por la cpu
 */

proceso SJF::trabajarEnCPU(short tiempoSimulacion)
{

    proceso_actual.procesoTrabajado(tiempoSimulacion);
    if(proceso_actual.getTiempoRestante()==0)
        ocupada = false;
    return proceso_actual;

}

}
