#ifndef STRF_H
#define STRF_H

#include "misalgoritmos.h"

namespace algoritmos {

class STRF : public MisAlgoritmos
{
public:
    STRF(Cola colaProcesos):MisAlgoritmos(colaProcesos){}
     proceso siguientePaso(short tiempoSimulacion) override;

};

}

#endif // STRF_H
