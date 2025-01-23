#include "MainWidget.h"
#include <QHBoxLayout>
#include "Storage.h"
#include "Cpu.h"
#include "HardwareWidget.h"

MainWidget::MainWidget(QWidget *parent)
{
    storageButton = new QPushButton("storage");
    cpuButton = new QPushButton("cpu");
    layout = new QVBoxLayout;
    QHBoxLayout *buttons = new QHBoxLayout;

    buttons->addWidget(storageButton);
    buttons->addWidget(cpuButton);
    layout->addLayout(buttons);

    setLayout(layout);

    // TODO: Connect click on buttons to appropriate slots
    connect(storageButton, &QPushButton::clicked, this, MainWidget::createStorage);
    connect(cpuButton, &QPushButton::clicked, this, MainWidget::createCpu);
}

void MainWidget::pushHardware()
{
    // TODO: Use HardwareWidget to create a widget for hardware, and add it to layout
    HardwareWidget visitor;
    hardware->accept(&visitor); // Chiede all'oggetto di accettare il visitor
    layout->addWidget(visitor.getWidget());
}

void MainWidget::createStorage()
{
    hardware = new Storage("My Storage", 64 * 1024 * 1024, 0.5);
    pushHardware();
}

void MainWidget::createCpu()
{
    hardware = new Cpu("My CPU", 99.99, 8 * 1024 * 1024);
    pushHardware();
}