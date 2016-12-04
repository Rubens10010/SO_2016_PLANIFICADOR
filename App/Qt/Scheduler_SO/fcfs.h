#ifndef FCFS_H
#define FCFS_H

#include "misalgoritmos.h"

/**
 *  Espacio para almacenar los algoritmos de planificacion usados por el programa
 */

namespace algoritmos{

    /**
     * @brief The FCFS clase es "First Come First Served" algoritmo, funciona como su nombre
     *  lo indica, el primer proceso en llegar a la cola de listo es el primero en ser trabajado.
     */

    class FCFS: public MisAlgoritmos
    {
    public:
        FCFS(Cola ColaProcesos);
        proceso siguientePaso(short tiempoSimulacion) override;
        proceso trabajarEnCPU(short tiempoSimulacion) override;

    };

}

#endif // FCFS_H
