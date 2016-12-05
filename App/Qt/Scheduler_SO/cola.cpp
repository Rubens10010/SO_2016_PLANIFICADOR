#include "cola.h"

/**
 * @brief Cola::Cola := Crea una cola vacia con tamaño para almacenar un numero
 *                   especifico de procesos.
 * @param numero : numero de procesos maximo.
 */

Cola::Cola(short numero)
{
    //listaPrincipal.resize(numero);
    listaPrincipal.reserve(numero);
    this->numero = numero;
}

/**
 * @brief Cola::Cola := Crea una cola y la llena con datos de una lista de procesos dada.
 * @param lista : lista de procesos para la cola.
 */

Cola::Cola(std::vector<proceso> &lista)
{
    listaPrincipal = lista;
}

/**
 * @brief Cola::llenar := Llena la cola con procesos con carga de trabajo aleatoria
 */

void Cola::llenar()
{
    for(short i = 0; i < numero; i++)
    {
        proceso p(i+1);
        listaPrincipal.push_back(p);
    }
}

/**
 * @brief Cola::obtenerProceso := devuelve el proceso en el indice indicado.
 * @param num: Indice del proceso en la listas.
 */

proceso Cola::obtenerProceso(unsigned short num)
{
    if(num > listaPrincipal.size())
        throw -1;   // error
    return listaPrincipal[num];
}

/**
 * @brief Cola::removerProceso := remueve un proceso de la cola.
 * @param num : indice del proceso.
 */

void Cola::removerProceso(unsigned short num)
{
    listaPrincipal.erase(listaPrincipal.begin() + num);
}


/**
 * @brief Cola::agregarProceso := agrega un proceso al final de la cola
 * @param proceso : Proceso a agregar
 */

void Cola::agregarProceso(proceso &p)
{
    listaPrincipal.push_back(p);
}

/**
 * @brief Cola::establecer := reemplaza el proceso en la posicion especificada de la cola.
 * @param i : indice del proceso a cambiar.
 * @param p : nuevo proceso para reemplazar el anterior.
 */

void Cola::establecer(short i, proceso &p)
{
    listaPrincipal[i] = p;
}

/**
 * @brief Cola::estaVacio := Verifica si la cola se encuentra vacia
 * @return := verdadero si esta vacio
 */

bool Cola::estaVacio()
{
    return (listaPrincipal.empty());
}

/**
 * @brief Cola::size
 * @return := tamaño de la cola
 */

short Cola::size()
{
    return listaPrincipal.size();
}

/**
 * @brief Cola::limpiarCola := Remueve todos los elementos de la cola
 */

void Cola::limpiarCola()
{
    listaPrincipal.clear();
}

/**
 * @brief Cola::ordenarPorLlegada := Ordena los procesos de la cola por el tiempo de llegada
 */

void Cola::ordenarPorLlegada()
{
    std::sort(listaPrincipal.begin(), listaPrincipal.end(), Primero);
}

/**
 * @brief Cola::ordenarPorMenorTrabajo := Ordena los procesos de la cola por la carga de trabajo total
 */

void Cola::ordenarPorMenorTrabajo()
{
    std::sort(listaPrincipal.begin(), listaPrincipal.end(), MasCorto);
}

/**
 * @brief Cola::ordenarPorPrioridad := Ordena los procesos de la cola por su prioridad.
 */

void Cola::ordenarPorPrioridad()
{
    std::sort(listaPrincipal.begin(), listaPrincipal.end(), MasPrioridad);
}

/**
 * @brief Cola::ordenarPorMenorTiempoRestante
 */

void Cola::ordenarPorMenorTiempoRestante()
{
    std::sort(listaPrincipal.begin(), listaPrincipal.end(), proceso::MasCortoRestante);
}

/**
 * @brief Cola::obtenerCopia := Creauna copia de la cola con todos sus procesos.
 * @return : Copia separada de la cola actual
 */

Cola Cola::obtenerCopia()
{
    Cola nuevo(listaPrincipal);
    return nuevo;
}

/**
 * @brief Cola::obtenerCopiaLimpia :=
 * @return
 */

Cola Cola::obtenerCopiaLimpia()
{
    std::vector<proceso> lista;
    for(unsigned int i = 0; i < listaPrincipal.size(); i++)
    {
        proceso temp = listaPrincipal[i].obtenerCopiaLimpia();
        lista.push_back(temp);
    }
    return lista;
}

/**
 * @brief Cola::mostrarCola := Muestra el contenido actual de la cola (cada detalle de los procesos)
 * @param Tiempo_simulacion : Tiempo actual de la simulacion
 */

void Cola::mostrarCola(short Tiempo_simulacion)
{
    if(estaVacio())
    {
        std::cout << "Empty Queue" << std::endl;
        return;
    }

    std::cout << "number of jobs "<< listaPrincipal.size()<<std::endl;
    std::cout << "# "<<" Arrive "<<" Burst "<<" Priority "<<" Start "<<" Wait "<<" Remain "<<" Finish "<<" Turn "<<" % "<<std::endl;
    for(unsigned int i=0 ; i<listaPrincipal.size() ; i++) // show every job data
    {
        proceso temp = listaPrincipal[i];
        std::cout<<temp.get_id() << "    " << temp.t_llegada << "      " << temp.getTiempoTotal() << "       ";
        std::cout<<temp.getPrioridad() << "      " << temp.getTiempoComienzo() + "      " << temp.getTiempoEspera(Tiempo_simulacion)<< "      ";
        std::cout<<temp.getTiempoRestante() << "       " << temp.getTiempoTermino() << "      " << temp.getTiempoRespuesta(Tiempo_simulacion) << "    ";
        std::cout << temp.getPorcentaje() <<std::endl;
    }

}


std::vector<std::string> Cola::getInformacionTabla()
{
    std::vector<std::string> v;
    for(int i = 0; i < listaPrincipal.size(); i++)
    {
        v.push_back(listaPrincipal[i].getString());
    }
    return v;
}
