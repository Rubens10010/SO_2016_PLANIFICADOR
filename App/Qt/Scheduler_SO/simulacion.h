#ifndef SIMULACION_H
#define SIMULACION_H

#include "string.h"
#include "fcfs.h"
#include "prioridad1.h"
#include "prioridad2.h"
#include "colaprincipal.h"

namespace cpu{

/**
 * @brief The Simulacion class
 * Esta clase es responsable por iniciar, seleccionar el algoritmom
 * y hacer los pasos de la simulacion.
 */

extern short Tiempo;    // Tiempo actual de la simulacion
extern std::string tipoAlgoritmo;   // tipo de algoritmo por defecto
extern short Quantum;
extern bool terminado;
extern bool detenido;

class Simulacion
{
public:

    static void reiniciar();
    static Cola obtenerColaListos();
    static proceso avanzar();
    static void seleccionarAlgoritmo();

    /*static short Tiempo;    // Tiempo actual de la simulacion
    static std::string tipoAlgoritmo;   // tipo de algoritmo por defecto
    static short Quantum;
    static bool terminado;
    static bool detenido;*/

private:
   static algoritmos::MisAlgoritmos *m_Algoritmo;   // objeto polimorfico

};

}

#endif // SIMULATION_H
