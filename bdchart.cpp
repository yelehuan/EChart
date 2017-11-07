#include "bdchart.h"
#include <QDebug>

BDChart::BDChart(QObject *parent) : QObject(parent)
{

}

void BDChart::slotTest()
{
    qDebug() << "send data bdchart" << endl;
    emit signalTest();
}

void BDChart::slotBack()
{
    qDebug() << "back" << endl;
}
