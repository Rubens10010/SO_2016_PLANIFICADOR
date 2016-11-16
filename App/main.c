#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************Proyeco de Sistemas Operativos: Planificador de procesos**********************************/
/***                                    ***
        AUTORES:
        - Ruben Edwin Hualla Quispe
        - Enrique Gutierrez Salazar
        - Diego David Charrez Ticona

***                                     ***/

// Estructura proceso que almacena el pda de un proceso

typedef enum {Running, Waiting, Finished} Estado;
typedef enum { false, true } bool;

typedef struct {
    
    char id[5];
    short t_llegada;
    short t_servicio[5];
    Estado estado;
    
} proceso;

// Reducir el tiempo de servicio cuando el proceso a sido servido por el CPU o E/S
// Si el estado del proceso es diferente de waiting*, no se podra reducir el tiempo

bool reduce_time(proceso *p, int n)
{
    
    if(p->estado != Waiting)
    {
        return false;
    }
    
    short i = 0;
    while(i != 5)
    {
        if(p->t_servicio[i]>0)
        {
            // asumiendo que n es menor o igual
            p->t_servicio[i]-=n;
            return true;
        }
        i++;
    }
    return false;
    
}

// Esta función genera una carga de trabajo aleatoria

int generar(proceso **procesos)
{
    time_t t;
    time(&t);
    srand((unsigned)t);
    //free(*procesos);
    int n = rand()%100+1;   // Número de procesos
    *procesos = malloc(n*sizeof(proceso));
    
    int ciclos[3]= {1,3,5};
    
    for(int i = 0; i < n; i++)
    {
        proceso nuevo;
        sprintf(nuevo.id, "P%d", i);
        nuevo.t_llegada = (rand()%50) + 1;
        
        int times = ciclos[rand()%3];
        for(int i = 0; i < times; i++)
        {
            
            nuevo.t_servicio[i] = (rand()%46)+5;
        }
        for(int i = times; i < 5; i++)
            nuevo.t_servicio[i] = 0;
        
        nuevo.estado = Waiting;
        (*procesos)[i] = nuevo; 
    }
    
    return n;
    
}

int main()
{
    proceso *procesos;
    int n;
    n = generar(&procesos);
    for(int i = 0; i < n; i++)
    {
        printf("Number %d: Id is %s, Tiempo de llegada: %d, ", i , procesos[i].id, procesos[i].t_llegada);
        printf("Tiempos de servicio: ");
        for(int j = 0; j < 5; j++)
        {
            printf("%d ",procesos[i].t_servicio[j]);
        }
        printf("\n");
    }
    return 0;
    
}