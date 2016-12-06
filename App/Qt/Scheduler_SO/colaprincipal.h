#ifndef COLAPRINCIPAL_H
#define COLAPRINCIPAL_H

#include "cola.h"

namespace cpu{

/**
 * @brief The ColaPrincipal class
 *  ColaPrincipal es la lista principal de procesos en la simulacion, esta clase es usada para mantener la cola principal y
 *  una cola temporal de respaldo para reiniciar la simulacion con los mismos datos.
 */

class ColaPrincipal
{
public:

    static Cola* crearNueva(short numeroDeProcesos);
    static void reiniciar();
    static void agregar(Cola lista);
    static Cola obtener();

private:
    static Cola* principalQ; // lista principal de procesos
    static Cola tempPrincipalQ; // copia temporal de la lista principal


};

}

#endif // COLAPRINCIPAL_H
