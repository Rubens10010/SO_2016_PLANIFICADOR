#ifndef COLA_H
#define COLA_H

#include <vector>
#include <algorithm>
#include "proceso.h"

/**
 * @brief Cola es una lista de procesos, usada para proveer de algunos metodos
 * utiles para hacer uso de la lista de procesos mucho mas facilmente.
 */

class Cola
{
public:
    Cola(short numero);
    Cola(std::vector<proceso> &lista);
    void llenar();
    proceso obtenerProceso(unsigned short num);
    void removerProceso(unsigned short num);
    void agregarProceso(proceso &p);
    void establecer(short i, proceso &p);
    bool estaVacio();
    short size();    // tamaño
    void limpiarCola();
    void ordenarPorLlegada();
    void ordenarPorMenorTrabajo();
    void ordenarPorPrioridad();
    void ordenarPorMenorTiempoRestante();
    Cola obtenerCopia();
    Cola obtenerCopiaLimpia();
    void mostrarCola(short Tiempo_simulacion);
    std::vector<std::string> getInformacionTabla();

private:
    std::vector<proceso> listaPrincipal;    // lista de procesos
    short numero;   //Numero maximo de procesos
};

#endif // COLA_H
