#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <map>
#include <string>
#include "simulacion.h"
#include "colaprincipal.h"
#include <QVector>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

using namespace QtConcurrent;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Funciones
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void llenar_arreglo_gantt_cpu();
    void llenar_arreglo_gantt_es();
    void llenar_arreglo_cola_cpu();
    void llenar_arreglo_cola_es();

    void iniciar();
    void siguientePaso();
    void delay();
    void finilizarAccion();
    void cpuVisual(proceso &p, short t);
    void cpuClear();
    void pintar_tarea_cpu(proceso &p, short t);

    void limpiar_arreglos();
    void establecer_colores();

    void fillTable();
    void updateTable(proceso &p,short t);
    double getPromedioEspera();     // Tiempo promedio de espera de todos los procesos
    double getPromedioRetorno();    // Tiempo promedio de retorno para todos los procesos


    // Variables
    static int idlTiempo;
    QFuture<void> future;

    QLabel* array_gantt_cpu[47];
    QLabel* array_gantt_es[47];
    QLabel* array_cola_cpu[8];
    QLabel* array_cola_es[8];

    std::map<int, std::string> colores;

private slots:

    void on_boton_simular_clicked();
    void on_boton_detener_clicked();
    void on_boton_siguiente_clicked();
    void on_boton_reiniciar_clicked();
    void on_boton_comenzar_clicked();
    void on_boton_terminar_clicked();

    void on_info_algoritmo_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
