#ifndef PRIORIDAD2_H
#define PRIORIDAD2_H

#include "misalgoritmos.h"

namespace algoritmos{

class Prioridad2:public MisAlgoritmos
{
public:
    Prioridad2(Cola colaProcesos):MisAlgoritmos(colaProcesos){}
    proceso siguientePaso(short tiempoSimulacion) override;
};

}

#endif // PRIORIDAD2_H
