#ifndef SJF_H
#define SJF_H

#include "misalgoritmos.h"

namespace algoritmos{

/**
 * @brief The SJF class
 * "Shortest Job First" algoritmo es parecido a FCFS excepto que
 * los procesos son reordenados por el tiempo total restante menor
 * Cada Vez que un proceso nuevo llega.
 *
 * Es un algoritmo no apropiativo.
 */

class SJF:public MisAlgoritmos
{
public:
    SJF(Cola ColaProcesos):MisAlgoritmos(ColaProcesos){}
    proceso siguientePaso(short tiempoSimulacion) override;
    proceso trabajarEnCPU(short tiempoSimulacion) override;

};

}

#endif // SJF_H
