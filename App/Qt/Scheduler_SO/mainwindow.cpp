#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabla_tareas->resizeColumnsToContents();
    ui->tabla_tareas->resizeRowsToContents();

    ui->tabla_tareas->setItem(0,0,new QTableWidgetItem("asd"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_boton_simular_clicked()
{
    cout << "asd" << endl;
}
