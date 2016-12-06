#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include "misalgoritmos.h"
//#include "proceso.h"


namespace algoritmos{

class RoundRobin:public MisAlgoritmos
{
public:
    RoundRobin(Cola ColaProcesos, short quantum);
    proceso siguientePaso(short tiempoSimulacion) override;
    proceso trabajarEnCPU(short tiempoSimulacion) override;

private:
    short Quantum;
    short tiempoProceso;

};

}
#endif // ROUNDROBIN_H
