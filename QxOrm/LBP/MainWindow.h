#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "ReadThread.h"
#include "WriteThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_m_WriteBtn_clicked();

    void on_m_ReadBtn_clicked();

private:
    Ui::MainWindow *ui;
    QThread m_WorkWriteThread;
    QThread m_WorkReadThread;

    CReadThread m_ReadThread;
    CWriteThread m_WriteThread;
};
#endif // MAINWINDOW_H
