#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

int MainWindow::idlTiempo=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabla_tareas->resizeColumnsToContents();
    ui->tabla_tareas->resizeRowsToContents();

    //ui->tabla_tareas->setItem(0,0,new QTableWidgetItem("asd"));


    establecer_colores();
    llenar_arreglo_gantt_cpu();
    llenar_arreglo_gantt_es();
    llenar_arreglo_cola_cpu();
    llenar_arreglo_cola_es();

    //Llenando Cola
    int indice=ui->info_num_tarea->currentIndex();
    indice=indice+1;
    cpu::ColaPrincipal::crearNueva(indice);

    srand(time(NULL));

   future = QtConcurrent::run(this,&MainWindow::iniciar);

    cpu::tipoAlgoritmo = "FCFS";
     connect(ui->info_algoritmo, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[this](int index){ on_info_algoritmo_currentIndexChanged( index ); });

}

MainWindow::~MainWindow()
{

    future.cancel();
    delete ui;
}



void MainWindow::on_boton_detener_clicked()
{

}

void MainWindow::on_boton_siguiente_clicked()
{

}

void MainWindow::on_boton_reiniciar_clicked()
{
    ui->tabla_tareas->clear();
    ui->cpu_tarea_actual->setText("JOB 0");
    ui->cpu_tiempo_actual->setText("0");
    ui->cpu_utilizacion->setText("0 %");

    ui->promedio_esperando->setText("0.00");
    ui->promedio_retorno->setText("0.00");
    limpiar_arreglos();
}

void MainWindow::on_boton_comenzar_clicked()
{

}

void MainWindow::on_boton_terminar_clicked()
{

}





void MainWindow::llenar_arreglo_gantt_cpu()
{
    array_gantt_cpu[0] = ui->cpu_gantt_01;
    array_gantt_cpu[1] = ui->cpu_gantt_02;
    array_gantt_cpu[2] = ui->cpu_gantt_03;
    array_gantt_cpu[3] = ui->cpu_gantt_04;
    array_gantt_cpu[4] = ui->cpu_gantt_05;
    array_gantt_cpu[5] = ui->cpu_gantt_06;
    array_gantt_cpu[6] = ui->cpu_gantt_07;
    array_gantt_cpu[7] = ui->cpu_gantt_08;
    array_gantt_cpu[8] = ui->cpu_gantt_09;
    array_gantt_cpu[9] = ui->cpu_gantt_10;
    array_gantt_cpu[10] = ui->cpu_gantt_11;
    array_gantt_cpu[11] = ui->cpu_gantt_12;
    array_gantt_cpu[12] = ui->cpu_gantt_13;
    array_gantt_cpu[13] = ui->cpu_gantt_14;
    array_gantt_cpu[14] = ui->cpu_gantt_15;
    array_gantt_cpu[15] = ui->cpu_gantt_16;
    array_gantt_cpu[16] = ui->cpu_gantt_17;
    array_gantt_cpu[17] = ui->cpu_gantt_18;
    array_gantt_cpu[18] = ui->cpu_gantt_19;
    array_gantt_cpu[19] = ui->cpu_gantt_20;
    array_gantt_cpu[20] = ui->cpu_gantt_21;
    array_gantt_cpu[21] = ui->cpu_gantt_22;
    array_gantt_cpu[22] = ui->cpu_gantt_23;
    array_gantt_cpu[23] = ui->cpu_gantt_24;
    array_gantt_cpu[24] = ui->cpu_gantt_25;
    array_gantt_cpu[25] = ui->cpu_gantt_26;
    array_gantt_cpu[26] = ui->cpu_gantt_27;
    array_gantt_cpu[27] = ui->cpu_gantt_28;
    array_gantt_cpu[28] = ui->cpu_gantt_29;
    array_gantt_cpu[29] = ui->cpu_gantt_30;
    array_gantt_cpu[30] = ui->cpu_gantt_31;
    array_gantt_cpu[31] = ui->cpu_gantt_32;
    array_gantt_cpu[32] = ui->cpu_gantt_33;
    array_gantt_cpu[33] = ui->cpu_gantt_34;
    array_gantt_cpu[34] = ui->cpu_gantt_35;
    array_gantt_cpu[35] = ui->cpu_gantt_36;
    array_gantt_cpu[36] = ui->cpu_gantt_37;
    array_gantt_cpu[37] = ui->cpu_gantt_38;
    array_gantt_cpu[38] = ui->cpu_gantt_39;
    array_gantt_cpu[39] = ui->cpu_gantt_40;
    array_gantt_cpu[40] = ui->cpu_gantt_41;
    array_gantt_cpu[41] = ui->cpu_gantt_42;
    array_gantt_cpu[42] = ui->cpu_gantt_43;
    array_gantt_cpu[43] = ui->cpu_gantt_44;
    array_gantt_cpu[44] = ui->cpu_gantt_45;
    array_gantt_cpu[45] = ui->cpu_gantt_46;
    array_gantt_cpu[46] = ui->cpu_gantt_47;
}

void MainWindow::llenar_arreglo_gantt_es()
{
    array_gantt_es[0] = ui->gantt_es_01;
    array_gantt_es[1] = ui->gantt_es_02;
    array_gantt_es[2] = ui->gantt_es_03;
    array_gantt_es[3] = ui->gantt_es_04;
    array_gantt_es[4] = ui->gantt_es_05;
    array_gantt_es[5] = ui->gantt_es_06;
    array_gantt_es[6] = ui->gantt_es_07;
    array_gantt_es[7] = ui->gantt_es_08;
    array_gantt_es[8] = ui->gantt_es_09;
    array_gantt_es[9] = ui->gantt_es_10;
    array_gantt_es[10] = ui->gantt_es_11;
    array_gantt_es[11] = ui->gantt_es_12;
    array_gantt_es[12] = ui->gantt_es_13;
    array_gantt_es[13] = ui->gantt_es_14;
    array_gantt_es[14] = ui->gantt_es_15;
    array_gantt_es[15] = ui->gantt_es_16;
    array_gantt_es[16] = ui->gantt_es_17;
    array_gantt_es[17] = ui->gantt_es_18;
    array_gantt_es[18] = ui->gantt_es_19;
    array_gantt_es[19] = ui->gantt_es_20;
    array_gantt_es[20] = ui->gantt_es_21;
    array_gantt_es[21] = ui->gantt_es_22;
    array_gantt_es[22] = ui->gantt_es_23;
    array_gantt_es[23] = ui->gantt_es_24;
    array_gantt_es[24] = ui->gantt_es_25;
    array_gantt_es[25] = ui->gantt_es_26;
    array_gantt_es[26] = ui->gantt_es_27;
    array_gantt_es[27] = ui->gantt_es_28;
    array_gantt_es[28] = ui->gantt_es_29;
    array_gantt_es[29] = ui->gantt_es_30;
    array_gantt_es[30] = ui->gantt_es_31;
    array_gantt_es[31] = ui->gantt_es_32;
    array_gantt_es[32] = ui->gantt_es_33;
    array_gantt_es[33] = ui->gantt_es_34;
    array_gantt_es[34] = ui->gantt_es_35;
    array_gantt_es[35] = ui->gantt_es_36;
    array_gantt_es[36] = ui->gantt_es_37;
    array_gantt_es[37] = ui->gantt_es_38;
    array_gantt_es[38] = ui->gantt_es_39;
    array_gantt_es[39] = ui->gantt_es_40;
    array_gantt_es[40] = ui->gantt_es_41;
    array_gantt_es[41] = ui->gantt_es_42;
    array_gantt_es[42] = ui->gantt_es_43;
    array_gantt_es[43] = ui->gantt_es_44;
    array_gantt_es[44] = ui->gantt_es_45;
    array_gantt_es[45] = ui->gantt_es_46;
    array_gantt_es[46] = ui->gantt_es_47;
}

void MainWindow::llenar_arreglo_cola_cpu()
{
    array_cola_cpu[0] = ui->cola_cpu_1;
    array_cola_cpu[1] = ui->cola_cpu_2;
    array_cola_cpu[2] = ui->cola_cpu_3;
    array_cola_cpu[3] = ui->cola_cpu_4;
    array_cola_cpu[4] = ui->cola_cpu_5;
    array_cola_cpu[5] = ui->cola_cpu_6;
    array_cola_cpu[6] = ui->cola_cpu_7;
    array_cola_cpu[7] = ui->cola_cpu_8;
}

void MainWindow::llenar_arreglo_cola_es()
{
    array_cola_es[0] = ui->cola_es_1;
    array_cola_es[1] = ui->cola_es_2;
    array_cola_es[2] = ui->cola_es_3;
    array_cola_es[3] = ui->cola_es_4;
    array_cola_es[4] = ui->cola_es_5;
    array_cola_es[5] = ui->cola_es_6;
    array_cola_es[6] = ui->cola_es_7;
    array_cola_es[7] = ui->cola_es_8;
}

void MainWindow::limpiar_arreglos()
{
    for(auto ms : array_gantt_cpu) {
        ms->setText("");
        ms->setStyleSheet("");
    }
    for(auto ms : array_gantt_es) {
        ms->setText("");
        ms->setStyleSheet("");
    }
    for(auto ms : array_cola_cpu) {
        ms->setText("");
        ms->setStyleSheet("");
    }
    for(auto ms : array_cola_es) {
        ms->setText("");
        ms->setStyleSheet("");
    }
}

void MainWindow::establecer_colores()
{
    colores[0] = "background-color:blue";
    colores[1] = "background-color:red";
    colores[2] = "background-color:yellow";
    colores[3] = "background-color:orange";
    colores[4] = "background-color:green";
    colores[5] = "background-color:rgb(142, 255, 111)";
    colores[6] = "background-color:rgb(50, 68, 72)";
    colores[7] = "background-color:rgb(99, 195, 255)";
}

void MainWindow::fillTable()
{

    ui->tabla_tareas->clearContents();

    int indice=ui->info_num_tarea->currentIndex();
    indice=indice+1;
    cpu::ColaPrincipal::crearNueva(indice);


    std::vector<std::string> temp;
    temp=cpu::ColaPrincipal::obtener().getInformacionTabla();

    for(unsigned int i=0;i<temp.size();i++)
    {
        QString qstr = QString::fromStdString(temp[i]);
        QStringList list=qstr.split(" ");
        qDebug()<<list;
        ui->tabla_tareas->setItem(i, 0, new QTableWidgetItem(list[0]));
        ui->tabla_tareas->setItem(i, 1, new QTableWidgetItem(list[1]));
        ui->tabla_tareas->setItem(i, 2, new QTableWidgetItem(list[2]));
        ui->tabla_tareas->setItem(i, 3, new QTableWidgetItem(list[3]));

    }



}


void MainWindow::iniciar()
{
      while(true)
      {
          if(!cpu::detenido && !cpu::terminado)
          {
              siguientePaso();
              delay();
          }
      }

}

void MainWindow::siguientePaso()
{
 if(!cpu::terminado)
 {
     ui->info_algoritmo->setDisabled(true);
     ui->info_num_tarea->setDisabled(true);
     ui->info_quantum->setDisabled(true);
     ui->info_velocidad->setDisabled(true);
     ui->boton_simular->setDisabled(true);

     proceso temp = cpu::Simulacion::avanzar();
     pintar_tarea_cpu(temp,cpu::Tiempo);
     //cpuVisual(temp,cpu::Tiempo);
    // pasar al visualizador
 }

    if(cpu::terminado)
    {
        finilizarAccion();

    }

    cpu::Tiempo++;
    //cpu::Simulacion::obtenerColaListos().mostrarCola(cpu::Tiempo);


}

void MainWindow::delay()
{

}

void MainWindow::finilizarAccion()
{

}




void MainWindow::on_boton_simular_clicked()
{
    fillTable();
    cpu::detenido = false;
    // bloquear simulate button
    // bloquear boton ssiguiente
    // activar boton parar
}

void MainWindow::on_info_algoritmo_currentIndexChanged(int index)
{
    qDebug()<<index;
    QString temp=ui->info_algoritmo->currentText();
    qDebug()<<temp;
    std::string algoritmo = temp.toStdString();
    cpu::tipoAlgoritmo=algoritmo;
}

void MainWindow::pintar_tarea_cpu(proceso &p, short t)
{

    if(p.get_id()==0)
        return;
    qDebug()<<QString::fromStdString(colores[p.get_id()]);
    array_gantt_cpu[t]->setStyleSheet(QString::fromStdString(colores[p.get_id()]));
    array_gantt_cpu[t]->setText(QString::fromStdString(std::to_string(p.get_id())));

}

/**
 * @brief cpuVisual Establece el contenido actual de las labels en CPU
 * @param p
 * @param t
 */
void MainWindow::cpuVisual(proceso &p, short t)
{
    if(p.getTiempoComienzo()>0)
    {
        idlTiempo++;
    }

}

void cpuClear();
