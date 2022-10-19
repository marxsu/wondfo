#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ReadThread.moveToThread(&m_WorkReadThread);
    m_WriteThread.moveToThread(&m_WorkWriteThread);
    connect(&m_WorkReadThread,SIGNAL(started()),&m_ReadThread,SLOT(Run()));
    connect(&m_WorkWriteThread,SIGNAL(started()),&m_WriteThread,SLOT(Run()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_m_WriteBtn_clicked()
{
    m_WorkWriteThread.start();
}

void MainWindow::on_m_ReadBtn_clicked()
{
    m_WorkReadThread.start();
}
