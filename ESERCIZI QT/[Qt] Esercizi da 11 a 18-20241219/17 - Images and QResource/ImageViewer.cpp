#include "ImageViewer.h"
#include <QVBoxLayout>
#include <QPixmap>

ImageViewer::ImageViewer(QWidget *parent)
    : QWidget(parent), currentImage(":/images/image1.png")
{ // Initial image
    imageLabel = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(imageLabel);
    setLayout(layout);

    // TODO: Set the initial image on the label
    // Hint: Use QPixmap and QLabel::setPixmap()
    QPixmap pixmap(currentImage);
    imageLabel->setPixmap(pixmap);
}

void ImageViewer::keyPressEvent(QKeyEvent *event)
{
    // TODO: Check if the Ctrl+T keyboard shortcut is pressed
    if (event->key() == Qt::Key_T && (event->modifiers() & Qt::ControlModifier))
    {
        switch_image();
    }
    // If pressed, toggle between "image1.png" and "image2.png"
    // Hint: Use QKeyEvent::modifiers() and QKeyEvent::key()
}

void ImageViewer::switch_image()
{
    if (currentImage == ":/images/image1.png")
    {
        currentImage = ":/images/image2.png";
    }
    else
    {
        currentImage = ":/images/image1.png";
    }

    QPixmap pixmap(currentImage);
    imageLabel->setPixmap(pixmap);
}
