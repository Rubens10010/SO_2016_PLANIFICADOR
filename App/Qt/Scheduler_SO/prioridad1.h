#ifndef PRIORIDAD1_H
#define PRIORIDAD1_H

#include "misalgoritmos.h"

namespace algoritmos{

class Prioridad1 : public MisAlgoritmos
{
public:
    Prioridad1(Cola colaProcesos):MisAlgoritmos(colaProcesos){};
    proceso siguientePaso(short tiempoSimulacion) override;
    proceso trabajarEnCPU(short tiempoSimulacion) override;
};

}

#endif // PRIORIDAD1_H
