#ifndef CWRITETHREAD_H
#define CWRITETHREAD_H

#include <QObject>

class CWriteThread : public QObject
{
    Q_OBJECT
public:
    explicit CWriteThread(QObject *parent = nullptr);

private slots:

    void Run();

signals:

};

#endif // CWRITETHREAD_H
