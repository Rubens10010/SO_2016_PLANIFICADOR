#include "colaprincipal.h"

namespace cpu{

/**
 * @brief crearNueva := crea una nueva cola principal y la llena de procesos aleatorios
 * @param numeroDeProcesos: numero de procesos a simular
 * @return : La cola principal de procesos
 */

Cola* ColaPrincipal::principalQ;
Cola ColaPrincipal::tempPrincipalQ(0);

Cola* ColaPrincipal::crearNueva(short numeroDeProcesos)
{

    principalQ = new Cola(numeroDeProcesos);
    principalQ->llenar();
    tempPrincipalQ = principalQ->obtenerCopiaLimpia();
    return principalQ;

}

/**
 * @brief reiniciar : Reestablece los datos iniciales de la cola principal
 */

void ColaPrincipal::reiniciar()
{
    *principalQ = tempPrincipalQ.obtenerCopiaLimpia();
}

/**
 * @brief ColaPrincipal::agregar := llena la cola principal con procesos de otra cola
 * @param lista : cola de procesos
 */

void ColaPrincipal::agregar(Cola lista)
{
    *principalQ = lista.obtenerCopiaLimpia();
    tempPrincipalQ = principalQ->obtenerCopiaLimpia();
}

/**
 * @brief ColaPrincipal::obtener : getter de la cola principal
 * @return : retorna una copia separa de la cola principal
 */

Cola ColaPrincipal::obtener()
{
    return principalQ->obtenerCopia();
}

}
