#include "previewwindow.h"
#include "ui_previewwindow.h"
#include "QTimer"
#include <iostream>

PreviewWindow::PreviewWindow(QVector<QImage> frames, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewWindow)
{
    ui->setupUi(this);
    ui->fpsSpinBox->setRange(0, 12);
    ui->fpsSpinBox->setSingleStep(1);
    ui->fpsSlider->setTickInterval(5);
    ui->fpsSlider->setRange(0, 12);
    this->frames = frames;
    currentFrameIndex = 0;
    if (frames.size() > 0)
    {
        showImage(frames.at(currentFrameIndex));
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(switchImage()));
        timer->start(0);
    }
}

PreviewWindow::~PreviewWindow()
{
    delete ui;
}

void PreviewWindow::on_closeButton_pressed()
{
    timer->stop();
    this->close();
}

void PreviewWindow::showImage(QImage frame)
{
    ui->frameLabel->setPixmap(QPixmap::fromImage(frame));
    ui->frameLabel->show();
}

void PreviewWindow::switchImage()
{
    currentFrameIndex = (currentFrameIndex+1) % frames.size();
    //std::cout << currentFrameIndex << std::endl;
    showImage(frames.at(currentFrameIndex));
}

void PreviewWindow::setTimer(int fps)
{
    if (fps == 0)
        timer->stop();
    else if (frames.size() > 0){
        timer->setInterval(1000/fps);
        if (!timer->isActive())
            timer->start();
    }

}

void PreviewWindow::on_fpsSpinBox_valueChanged(int arg1)
{
    setTimer(arg1);
    ui->fpsSlider->setValue(arg1);
}

void PreviewWindow::on_fpsSlider_valueChanged(int value)
{
    setTimer(value);
    ui->fpsSpinBox->setValue(value);
}
