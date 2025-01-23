#include "TimerHandler.h"

TimerHandler::TimerHandler(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000); // Trigger every 1 second

    // TODO: Connect the timer's timeout signal to the updateMessage() slot
    connect(timer, &QTimer::timeout, this, &TimerHandler::updateMessage);
    // Start the timer
    timer->start();
}

void TimerHandler::updateMessage()
{
    qDebug() << "Timer triggered: Updating the message!";
}