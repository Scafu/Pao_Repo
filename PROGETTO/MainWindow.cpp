#include "MainWindow.h"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUI();
}

void MainWindow::setupUI()
{
    QTextEdit *textEdit = new QTextEdit();

    textEdit->setText("ciao Coglione");
    setCentralWidget(textEdit);
};