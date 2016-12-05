#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void llenar_arreglo_gantt_cpu();
    void llenar_arreglo_gantt_es();
    void llenar_arreglo_cola_cpu();
    void llenar_arreglo_cola_es();

    void limpiar_arreglos();


    QLabel* array_gantt_cpu[47];
    QLabel* array_gantt_es[47];
    QLabel* array_cola_cpu[8];
    QLabel* array_cola_es[8];

private slots:
    void on_boton_simular_clicked();
    void on_boton_detener_clicked();
    void on_boton_siguiente_clicked();
    void on_boton_reiniciar_clicked();
    void on_boton_comenzar_clicked();
    void on_boton_terminar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
