#ifndef MISALGORITMOS_H
#define MISALGORITMOS_H

#include "proceso.h"
#include "cola.h"

namespace algoritmos
{

    /**
     * @brief The MisAlgoritmos class usada como clase base para todas las clases de algoritmos de planificacion
     * para el uso de polimorfismo. Ademas mantiene variables y metodos comunes a todas las clases de algoritmos
     */

    class MisAlgoritmos
    {
    public:
        MisAlgoritmos(Cola colaTrabajo);
        virtual proceso siguientePaso(short tiempoSimulacion) = 0;  // metodo abstracto necesario para sobreescribir en clases hijas.
        Cola obtenerColaListos();
        bool finalizado();

    protected:
        virtual proceso trabajarEnCPU(short tiempoSimulacion);
        void actualizarColaListos(short tiempoSimulacion);
        void setProcesoActual();

        Cola lista; // lista de todos los procesos
        proceso proceso_actual; // proceso actual en el que la simulacion esta trabajando (CPU)
        Cola* ColaListos;    // lista de procesos listos para hacer uso del CPU o E/S
        bool ocupada;   // Indica si la CPU se encuentra ocupada o no (Procesos no apropiativos)

    };

}

#endif // MISALGORITMOS_H
