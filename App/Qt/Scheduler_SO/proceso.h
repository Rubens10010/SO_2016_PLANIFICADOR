#ifndef PROCESO_H
#define PROCESO_H

#include <string>
#include <fstream>
#include <iostream>

#define TIEMPO_TOTAL 100
#define T_LLEGADA_LIMITE 50
#define T_SERVICIO_MIN 10
#define T_SERVICIO_MAX 40	// Disminuir el T_servicio_min


/**
 *
 * @ Proyecto de Sistemas Operativos - 2016
 * " Proceso " es una clase para representar un proceso de la CPU,
 * sus datos y algunos metodos utiles para crear, compara y copiar procesos.
 * Asi como funciones, setters y getters.
 */


typedef enum {Running, Waiting, Finished} Estado;   // Estado del proceso


class proceso
{

public:

    proceso(short id_d, short tl, short ts[5], short prioridad);
    proceso(short i);

    void set_aleatorio(short i);   // Establece una carga de trabajo aleatoria al proceso
    short get_id();   // Retorna la id de este proceso
    bool reducir_tiempo(int n, bool tipo);  // Reduce el tiempo de servicio restante en cpu o E/S
    bool guardar(std::ofstream &file);
    bool cargar(std::ifstream &file);
    void imprimir_carga_trabajo();
    void procesoTrabajado(int tiempoSimulacion);

    short getTiempoTotal() const;   // El tiempo total de la carga de trabajo
    short getPorcentaje();
    short getTiempoEspera(short t_simulacion);
    short getTiempoRestante();
    short getTiempoRespuesta(short t_simulacion);
    short getTiempoTermino();
    short getTiempoComienzo();
    short getPrioridad() const;
    void setTiempoComienzo(short t_comienzo);
    void setTiempoRestante(short restante[5]);
    void setTermino(short termino);
    void setComienzo(short comienzo);
    bool voyPrimero(const proceso &otro) const;
    bool soyMasCorto(const proceso &otro) const;
    bool tengoMasPrioridad(const proceso &otro) const;
    static bool MasCortoRestante(proceso &p1, proceso &p2);

    proceso* copiarProceso();
    proceso obtenerCopiaLimpia();

    short id;
    short t_llegada;

private:
    //short id;
    //short t_llegada;
    short t_servicio[5];    // Rafagas de CPU y E/S
    short t_total_servicio;
    short comienzo;
    short prioridad;
    short termino;  // Tiempo en que termino su carga de trabajo.
    short restante;
    Estado estado;  // Almacena el estado actual del proceso.

};

bool Primero(const proceso &p1, const proceso &p2);
bool MasCorto(const proceso &p1, const proceso &otro);
bool MasPrioridad(const proceso &p1, const proceso &otro);
//bool MasCortoRestante(const proceso &p1, const proceso &p2);

#endif // PROCESO_H
