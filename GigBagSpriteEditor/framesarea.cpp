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
    this->setStyleSheet("background-color: gray");
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
    for (int i = 0; i < buttonFrames->length(); i++){
        delete buttonFrames->at(i);
    }
    buttonFrames->clear();
}


void framesarea::updateFramesArea(QVector<QImage> *frames){
    clearFrames();
    for(int i = 0; i < frames->length(); i++) {
        QImage img = frames->at(i);
        QPushButton *button = new QPushButton(QString::number(i+1));
        button->setFlat(true);
        button->setAutoFillBackground(true);
        button->setContentsMargins(0,0,0,0);
        button->setStyleSheet("background-color: red");
        button->setFixedSize(70, 70);
        button->setIcon(QIcon(QPixmap::fromImage(img).scaled(50, 50, Qt::IgnoreAspectRatio)));
        button->setIconSize(QSize(50,50));
        buttonFrames->append(button);
        vlayout->addWidget(button);
    }
    if (buttonFrames->length() > 0){
        setSelectedFrameIndex(0);
    }

}

void framesarea::setSelectedFrameIndex(int frameIndex){
    //unselect all of them
    for (int i = 0; i < buttonFrames->length(); i++){
        buttonFrames->at(i)->setStyleSheet("QPushButton {color: white;}");
        //buttonFrames->at(i)->setFixedSize(70, 70);
    }
    //select specific one
    if (frameIndex >= 0 && frameIndex < buttonFrames->length()){
        buttonFrames->at(frameIndex)->setStyleSheet("QPushButton {color: red;}");
        //buttonFrames->at(frameIndex)->setFixedSize(80, 80);
    }

}





