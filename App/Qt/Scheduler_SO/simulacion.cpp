#include "simulacion.h"

namespace cpu{

/*short Simulacion::Quantum = 2;
bool Simulacion::terminado = false;
bool Simulacion::detenido = true;
*/

short Quantum = 2;
bool terminado = false;
bool detenido = true;
short Tiempo = 0;
std::string tipoAlgoritmo ="";

algoritmos::MisAlgoritmos* Simulacion::m_Algoritmo;

/**
 * @brief Simulacion::reiniciar := reinicia la simulacion completa
 */

void Simulacion::reiniciar()
{
    Tiempo = 0;
    terminado = false;
}

/**
 * @brief Simulacion::obtenerColaListos
 * @return : retorna la cola de listos en su estado actual
 */

Cola Simulacion::obtenerColaListos()
{
    return m_Algoritmo->obtenerColaListos();
}

/**
 * @brief Simulacion::avanzar := Deja al algoritmo seleccionado avanzar su ejecucion por un tiempo
 * @return : el proceso actual trabajado por el algoritmo
 */

proceso Simulacion::avanzar()
{

    proceso p(0);
    if(Tiempo == 0)
        seleccionarAlgoritmo();
    p = m_Algoritmo->siguientePaso(Tiempo);
    if(m_Algoritmo->finalizado())
        terminado = true;
    return p;

}

/**
 * @brief Simulacion::seleccionarAlgoritmo := selecciona e inicializa el algoritmo seleccionado.
 */

void Simulacion::seleccionarAlgoritmo()
{

    if(tipoAlgoritmo == "FCFS")
        m_Algoritmo = new algoritmos::FCFS(ColaPrincipal::obtener());
    else if(tipoAlgoritmo == "SJF")
        m_Algoritmo = new algoritmos::FCFS(ColaPrincipal::obtener());
    else if(tipoAlgoritmo ==  "Priority1")
        m_Algoritmo = new algoritmos::Prioridad1(ColaPrincipal::obtener());
    else if(tipoAlgoritmo == "STRF")
        m_Algoritmo = new algoritmos::FCFS(ColaPrincipal::obtener());
    else if(tipoAlgoritmo == "Priority2")
        m_Algoritmo = new algoritmos::Prioridad2(ColaPrincipal::obtener());
    else if(tipoAlgoritmo == "Round Robin")
        m_Algoritmo = new algoritmos::FCFS(ColaPrincipal::obtener());

}

}
