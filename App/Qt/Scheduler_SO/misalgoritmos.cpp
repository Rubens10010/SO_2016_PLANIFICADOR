#include "misalgoritmos.h"

namespace algoritmos {

proceso nul(0);

/**
 * @brief MisAlgoritmos::MisAlgoritmos := Inicializa la lista de procesos y la cola de listos y toma una copia de la cola de simulacion a trabajar
 *           y la reordena por tiempo de llegada lo cual hace mas facil para el planificador saber cual proceso vino primero.
 * @param colaTrabajo : cola de procesos de la simulacion
 */

MisAlgoritmos::MisAlgoritmos(Cola colaTrabajo):proceso_actual(9),lista(colaTrabajo.size())
{
    ColaListos = new Cola(colaTrabajo.size());  // inicializa el tamaño de la cola de listos
    //proceso_actual = new proceso(9);    // inicializa un proceso aleatorio
    ocupada = false;
    lista = colaTrabajo.obtenerCopia();
    lista.ordenarPorLlegada();
}

/**
 * @brief obtenerColaListos := retorna una copia separada de la cola de listos
 * @return
 */

Cola MisAlgoritmos::obtenerColaListos()
{
    return ColaListos->obtenerCopia();
}

/**
 * @brief finalizado := revisa si el algoritmos ha terminado su simulacion o no.
 *              se tiene que cumplir si la lista principal y la cola de listos esta vacia y la CPU y E/S no trabajan en ningun proceso
 * @return true si la simulacion ha terminado
 */

bool MisAlgoritmos::finalizado()
{
    return (lista.estaVacio() && ColaListos->estaVacio() && !ocupada && proceso_actual.getTiempoRestante()==0);
}

/**
 * @brief MisAlgoritmos::trabajarEnCPU := Cambia los datos del proceso actual despues de ser trabajado en la simulacion por 1 paso.
 * @param tiempoSimulacion := Tiempo actual de la simulacion
 * @return : Proceso actual en el que el CPU esta trabajando
 */

proceso MisAlgoritmos::trabajarEnCPU(short tiempoSimulacion)
{
    proceso_actual.procesoTrabajado(tiempoSimulacion);
    return proceso_actual;
}

/**
 * @brief MisAlgoritmos::actualizarColaListos := agrega procesos nuevos que llegan a la cola de listos comparando el tiempo de llegada con el tiempo de simulacion.
 * @param tiempoSimulacion : Tiempo actual de la simulacion
 */

void MisAlgoritmos::actualizarColaListos(short tiempoSimulacion)
{

    for (int i = 0 ; i < lista.size() ; i++)
    {
        proceso temp = lista.obtenerProceso(i);
        if(temp.t_llegada == tiempoSimulacion)  // Si el proceso ha llegado
        {
            ColaListos->agregarProceso(temp);  // Moverlo a la cola de listos
            lista.removerProceso(i);   // Removerlo de la cola principal
            i--; // Reduce el tamaño de la iteracion por 1
        }
    }

}

/**
 * @brief MisAlgoritmos::setProcesoActual := Mueve el primer proceso en la cola de listos para ser el proceso trabajo actualmente
 */

void MisAlgoritmos::setProcesoActual()
{
    proceso_actual = ColaListos->obtenerProceso(0);
    ColaListos->removerProceso(0);
}

}
