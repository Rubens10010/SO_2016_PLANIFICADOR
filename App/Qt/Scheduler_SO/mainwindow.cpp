#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabla_tareas->resizeColumnsToContents();
    ui->tabla_tareas->resizeRowsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}
