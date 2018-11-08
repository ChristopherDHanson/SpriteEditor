#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "scribblearea.h"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    ui->setupUi(this);
//    ScribbleArea* sa = new ScribbleArea;
    connect(ui->lineBrushButton, SIGNAL(triggered()), this, SLOT(drawLine()));
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}

void SpriteEditorWindow::drawLine()
{
//    ScribbleArea::drawLineTo()
}
