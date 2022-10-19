#ifndef CREADTHREAD_H
#define CREADTHREAD_H

#include <QObject>

class CReadThread : public QObject
{
    Q_OBJECT
public:
    explicit CReadThread(QObject *parent = nullptr);

private slots:

    void Run();
signals:

};

#endif // CREADTHREAD_H
