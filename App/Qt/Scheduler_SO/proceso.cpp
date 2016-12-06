#include "proceso.h"

/**
 * @brief proceso::proceso crea un nuevo proceso con los datos asignados
 * @param id_d la id del nuevo proceso
 * @param tl tiempo de llegada del proceso
 * @param ts rafagas que necesita el proceso
 */

proceso::proceso(short id_d, short tl, short ts[5], short prioridad = 0)
{

    this->id = id_d;
    this->t_llegada = tl;
    for (int i : {0, 1, 2, 3, 4})
        t_servicio[i] = ts[i];
    this->estado = Waiting;
    this->prioridad = prioridad;
    this->t_total_servicio = t_servicio[0] + t_servicio[1] + t_servicio[2] + t_servicio[3] + t_servicio[4];
    getTiempoRestante();
}

/**
 * @brief proceso::proceso crea un nuevo proceso con datos aleatorios
 * @param number
 */

proceso::proceso(short number)
{

    set_aleatorio(number);

}

/**
 * @brief proceso::set_aleatorio genera una carga de trabajo aleatoria
 * @param number la id del proceso
 */

void proceso::set_aleatorio(short number)
{


    this->id = number;
    int ciclos[3]= {1,3,5}; // Numero de rafagas que necesitara el proceso.

    this->t_llegada = (id == 1)?0:(rand()%T_LLEGADA_LIMITE) + 1;
    int times = ciclos[rand()%3];

    for(int i = 0; i < times; i++)
    {
      // Los tiempos se intercalan segun el indice: par = CPU, impar = E/s
      this->t_servicio[i] = (rand()%T_SERVICIO_MAX)+T_SERVICIO_MIN;
    }

    for(int i = times; i < 5; i++)
      this->t_servicio[i] = 0;

    t_total_servicio = t_servicio[0] + t_servicio[1] + t_servicio[2] + t_servicio[3] + t_servicio[4];

    this->prioridad = rand()%125+1;
    this->comienzo = -1;
    this->termino = 0;
    this->estado = Waiting;
    getTiempoRestante();

}

/**
 * @brief get_id getter
 * @return copia de la id de este proceso
 */

short proceso::get_id()
{

    return this->id;

}

/**
 * @brief proceso::getTiempoTotal := Suma el tiempo de la carga total de trabajo
 * @return: Tiempo total de las rafagas de trabajo.
 */

short proceso::getTiempoTotal() const
{

    return t_total_servicio;

}

/**
 * @brief proceso::setTiempoComienzo: Si la simulacion empezo y el proceso es planificado para trabajar en CPU o E/S por primera vez
 * @param t_comienzo := Tiempo en que comenzo a ejecutarse el proceso
 */

void proceso::setTiempoComienzo(short t_comienzo)
{

     if(getTiempoRestante()==t_total_servicio)
         comienzo = t_comienzo;
     comienzo = -1; // error

}

/**
 * @brief proceso::reducir_tiempo := Reduce el tiempo de una rafaga de trabajo
 * @param n: tiempo a reducir
 * @param tipo: true para reducir tiempo de CPU y false para reducir tiempo de E/S
 * @return: exito o fracaso del metodo
 */

bool proceso::reducir_tiempo(int n, bool tipo)
{

    if(estado != Waiting)
    {
       return false;
    }

    short i = 0;
    while(i != 5)
    {
        if(tipo == true)
        {
            if(i%2!=0)
            {
                i++;
                continue;
            }
        }
        else if(i%2 == 0)
        {
            i++;
            continue;
        }
        if(t_servicio[i]>0)
        {
           // asumiendo que n es menor o igual
           t_servicio[i]-=n;
           //restante-=n;
           return true;
        }
        i++;
    }
    return false;

}

/**
 * @brief proceso::guardar := Guarda el estado actual del proceso en un archivo.
 * @param file: flujo de salida hacia un archivo donde se almacenaran los datos
 * @return: bool de exito o fracaso
 */

bool proceso::guardar(std::ofstream &file)
{

    if(!file.is_open())
        return false;
    file << id << " " << t_servicio << " ";
    for(int i=0; i < 5; i++)
    {
       file << " " << i;
    }
    file << "\n";
    return true;
}

/**
 * @brief proceso::cargar := Carga la informacion de un proceso guardado desde un archivo.
 * @param file: Flujo de entrada desde un archivo
 * @return: bool de exito o fracaso
 */

bool proceso::cargar(std::ifstream &file)
{

    if(!file.is_open())
        return false;

    file >> id;
    int t;
    for(int i=0; i < 5; i++)
    {
        file >> t;
        t_servicio[i] = t;
    }
    return true;

}

/**
 * @brief proceso::imprimir_carga_trabajo := Muestra la carga de trabajo actual en un formato especial para tablas
 */

void proceso::imprimir_carga_trabajo()
{

    std::cout << "Proceso ID is: " << this->id << ", Tiempo de llegada: "<< this->t_llegada << ", Tiempos de servicio:"<<std::endl;

    for(int j = 0; j < 5; j++)
    {
        std::cout << " " << this->t_servicio[j];
    }

    std::cout << "\n";

}

/**
 * @brief proceso::procesoTrabajado := Calcula lo que le pasa al proceso cuando hace uso del CPU o E/S.
 * @param tiempoSimulacion: Tiempo actual de la simulación
 */

void proceso::procesoTrabajado(int tiempoSimulacion)
{

    // Asumiendo que el proceso ya a empezado a trabajar
    reducir_tiempo(1,true);
    if(/*restante == 0*/getTiempoRestante()==0)
    {
        termino = tiempoSimulacion + 1;
        estado = Finished;
    }

}

/**
 * @brief proceso::getPorcentaje
 * @return: El porcentaje de la carga de trabajo ya realizada.
 */

short proceso::getPorcentaje()
{
    return (short)(((t_total_servicio - getTiempoRestante())*100)/t_total_servicio);
}


/**
 * @brief proceso::getTiempoEspera := Tiempo esperado hasta este momento.
 * @param t_ tiempo actual de la simulacion.
 * @return: Tiempo de espera
 */

short proceso::getTiempoEspera(short t_)
{
    return (getTiempoRespuesta(t_) - (t_total_servicio - getTiempoRestante()));
}

/**
 * @brief proceso::getTiempoRestante := Tiempo restante para finalizar
 * @return Tiempo total restante.
 */

short proceso::getTiempoRestante()
{

    //this->restante = t_servicio[0] + t_servicio[1] + t_servicio[2] + t_servicio[3] + t_servicio[4];
    this->restante = t_servicio[0] + t_servicio[2] + t_servicio[4];
    return this->restante;

}

/**
 * @brief proceso::getTiempoRespuesta := Calcula el tiempo de respuesta de la simulacion desde que llego el proceso
 * @param t_: Tiempo actual de la simulacion
 * @return: Tiempo de respuesta actual
 */

short proceso::getTiempoRespuesta(short t_)
{

    if(estado == Finished)
        return termino - t_llegada;
    if(t_ > t_llegada)
        return t_ - t_llegada;
    return 0;       // Si el proceso no ha llegado aun

}

/**
 * @brief proceso::getTiempoTermino := Si el proceso termino su ejecucion retornara el tiempo de termino
 * @return: Retorna cero si aun sigue ejecutandose
 */

short proceso::getTiempoTermino()
{
    return (estado == Finished)?termino:0;
}


/**
 * @brief getTiempoComienzo := Retorna el tiempo en que el proceso comenzo su ejecucion
 * @return: tiempo de comienzo
 */
short proceso::getTiempoComienzo()
{
    return comienzo;
}

/**
 * @brief proceso::getPrioridad := Retorna la prioridada de este proceso.
 * @return
 */

short proceso::getPrioridad() const
{
    return this->prioridad;
}

/**
 * @brief setTiempoRestante := Establece el tiempo total restante del proceso
 * @param restante: Rafagas de tiempo de servicio.
 */

void proceso::setTiempoRestante(short restante[5])
{

    this->restante = restante[0] + restante[1] + restante[2] + restante[3] + restante[4];
    for (int i : {0, 1, 2, 3, 4})
        t_servicio[i] = restante[i];

}

/**
 * @brief setTermino := Establece el tiempo de termino del proceso
 * @param termino
 */

void proceso::setTermino(short termino)
{
    this->termino = termino;
}

/**
 * @brief setComienzo := Establece el tiempo en que comienza la ejecucion del proceso
 * @param comienzo
 */

void proceso::setComienzo(short comienzo)
{
    this->comienzo = comienzo;
}

/**
 * @brief voyPrimero := Compara los tiempos de llegada
 * @param otro: Otro proceso
 * @return: verdadero si este proceso llega antes
 */

bool proceso::voyPrimero(const proceso &otro) const
{

    if(this->t_llegada == otro.t_llegada)
        return this->id < otro.id;
    return this->t_llegada < otro.t_llegada;

}

/**
 * @brief soyMasCorto := Compara los tiempos de trabajo
 * @param otro: Otro proceso
 * @return: verdadero si este proceso tiene un tiempo total de trabajo mas corto
 */

bool proceso::soyMasCorto(const proceso &otro) const
{

    if(t_total_servicio == otro.getTiempoTotal())
        return voyPrimero(otro);
    return t_total_servicio < otro.getTiempoTotal();

}

/**
 * @brief tengoMasPrioridad := compara la prioridad de los procesos
 * @param otro: Otro proceso
 * @return : Vedadero si este proceso tiene mas alta prioridad (menor numero).
 */

bool proceso::tengoMasPrioridad(const proceso &otro) const
{

    if(this->prioridad == otro.getPrioridad())
        return voyPrimero(otro);
    return this->prioridad < otro.getPrioridad();

}

/**
 * @brief copiarProceso := Crea una copia del proceso con todos sus datos
 * @return trabajo diferente con los mismos datos
 */

proceso* proceso::copiarProceso()
{

    return new proceso(*this);

}

/**
 * @brief obtenerCopiaLimpia := Crea una copia con solo los datos iniciales del proceso, usado para reiniciar la simulacion.
 * @return: Una copia del estado inicial del proceso
 */

proceso proceso::obtenerCopiaLimpia()
{

    // Falta verificar;
    proceso temp(this->id, this->t_llegada, this->t_servicio, this->prioridad);
    temp.setTiempoRestante(this->t_servicio);
    return temp;
}


bool Primero(const proceso &p1, const proceso &p2)
{

    if(p1.t_llegada == p2.t_llegada)
        return p1.id < p2.id;
    return p1.t_llegada < p2.t_llegada;

}

bool MasCorto(const proceso &p1, const proceso &otro)
{

    if(p1.getTiempoTotal() == otro.getTiempoTotal())
        return p1.voyPrimero(otro);
    return p1.getTiempoTotal() < otro.getTiempoTotal();

}

bool MasPrioridad(const proceso &p1, const proceso &otro)
{

    if(p1.getPrioridad() == otro.getPrioridad())
        return p1.voyPrimero(otro);
    return p1.getPrioridad() < otro.getPrioridad();

}

bool proceso::MasCortoRestante(proceso &p1, proceso &p2)
{
    if(p1.getTiempoRestante() == p2.getTiempoRestante())
        return p1.voyPrimero(p2);
    return p1.getTiempoRestante() < p2.getTiempoRestante();
}


std::string proceso::getString(short t)
{
    std::string row;

    row = std::to_string(this->id) +" ";
    row = row + std::to_string(this->t_llegada) + " ";

    for(int j = 0; j < 4; j++)
    {
        row = row + std::to_string(this->t_servicio[j]) +"-";
    }
    row = row + std::to_string(this->t_servicio[4]) + " " + std::to_string(this->getPrioridad()) +" ";
    row = row + std::to_string(this->getTiempoComienzo()) + " ";
    row = row + std::to_string(this->getTiempoEspera(t)) + " ";
    row = row + std::to_string(this->getTiempoRestante()) + " ";
    row = row + std::to_string(this->getTiempoTermino()) + " ";
    row = row + std::to_string(this->getTiempoRespuesta(t)) + " ";
    row = row + std::to_string(this->getPorcentaje());
    return row;
}
