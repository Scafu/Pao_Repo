#include "HardwareWidget.h"
#include "Storage.h"
#include "Cpu.h"
#include <QVBoxlayout>
#include <QLabel>
QWidget *HardwareWidget::getWidget()
{
    return widget;
}

void HardwareWidget::visit(Storage *storage)
{
    // TODO: Build a widget suitable to display a storage
    widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(widget);
    QLabel *nameLabel = new QLabel("Price" + QString::number(storage->getPrice()));
    layout->addWidget(nameLabel);
    widget->setLayout(layout);
}

void HardwareWidget::visit(Cpu *cpu)
{
    // TODO: Build a widget suitable to display a CPU
    widget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(widget);
    QLabel *nameLabel = new QLabel("Price" + QString::number(cpu->getPrice()));

    layout->addWidget(nameLabel);

    widget->setLayout(layout);
}