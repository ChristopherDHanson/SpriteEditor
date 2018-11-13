#include "framesarea.h"
#include <QScrollArea>
#include <QtGui>
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include "FramesModel.h"

framesarea::framesarea(QWidget *parent) : QWidget(parent)
{
    //Assumes dimension will be 100 x 290
    this->setFixedSize(100, 290);
    this->setContentsMargins(0,0,0,0);
    this->setStyleSheet("background-color: blue");
    // set scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn );
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
    for (int i = 0; i < 5; i++){
        QPushButton *button = new QPushButton(QString::number(i));
        button->setContentsMargins(0,0,0,0);
        button->setStyleSheet("background-color: red");
        button->setFixedSize(70, 70);
        vlayout->addWidget(button);
    }
    // Above For Testing Only
    this->show();
}



void framesarea::setModel(FramesModel *_model){
    model = _model;
}

void framesarea::updateFramesArea(){
this->setStyleSheet("background-color: blue");

}

void framesarea::setSelectedFrameIndex(int frameIndex){

}

void framesarea::selectPreviousFrame(){

}

void framesarea::selectNextFrame(){

}


