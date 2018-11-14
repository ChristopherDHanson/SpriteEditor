#include "framesarea.h"
#include <QScrollArea>
#include <QtGui>
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QVector>

framesarea::framesarea(QWidget *parent) : QWidget(parent)
{
    //Assumes dimension will be 100 x 290
    this->setFixedSize(100, 290);
    this->setContentsMargins(0,0,0,0);
    this->setStyleSheet("background-color: blue");
    // set scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFixedSize(100, 290);
    scrollArea->setContentsMargins(0,0,0,0);

    QWidget *widget = new QWidget();
    scrollArea->setWidget(widget);

    // set vertical box laylout for buttons
    vlayout = new QVBoxLayout();
    vlayout->setAlignment(Qt::AlignTop);
    vlayout->setContentsMargins(0,0,0,0);

    widget->setLayout(vlayout);

    // For testing only

//    clearFrames();
//    for (int i = 0; i < 5; i++){
//        QPushButton *button = new QPushButton(QString::number(i));
//        button->setFlat(true);
//        button->setAutoFillBackground(true);
//        button->setContentsMargins(0,0,0,0);
//        button->setStyleSheet("background-color: red");
//        button->setFixedSize(70, 70);
//        buttonFrames->append(button);
//        vlayout->addWidget(button);
//    }
//    setSelectedFrameIndex(0);
    // Above For Testing Only
    this->show();
}

void framesarea::clearFrames(){
    for (int i = 0; i < buttonFrames->size(); i++){
        delete buttonFrames->at(i);
    }
    buttonFrames->clear();
}


void framesarea::updateFramesArea(QVector<QImage> *frames){
    clearFrames();
    for(int i = 0; i < frames->size(); i++) {
        QImage img = frames->at(i);
        QPushButton *button = new QPushButton(QString::number(i+1));
        button->setFlat(true);
        button->setAutoFillBackground(true);
        button->setContentsMargins(0,0,0,0);
        button->setStyleSheet("background-color: red");
        button->setFixedSize(70, 70);
        button->setIcon(QIcon(QPixmap::fromImage(img)));
        button->setIconSize(img.size());
        buttonFrames->append(button);
        vlayout->addWidget(button);
    }
    if (buttonFrames->size() > 0){
        setSelectedFrameIndex(0);
    }

}

void framesarea::setSelectedFrameIndex(int frameIndex){
    //unselect all of them
    for (int i = 0; i < buttonFrames->size(); i++){
        buttonFrames->at(i)->setStyleSheet("QPushButton {background-color: red; color: black;}");
    }
    //select specific one
    if (frameIndex >= 0 && frameIndex < buttonFrames->size()){
        frameIndex = frameIndex % buttonFrames->size();
    }

    buttonFrames->at(frameIndex)->setStyleSheet("QPushButton {background-color: red; color: yellow;}");
}





