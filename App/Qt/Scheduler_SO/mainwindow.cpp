#include "mainwindow.h"
#include "ui_mainwindow.h"

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
