#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "sizeselectionwindow.h"
#include "scribblearea.h"
#include "framesarea.h"
#include "QColorDialog"
#include "previewwindow.h"
#include "QFileDialog"
#include <iostream>

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    currentFrameIndex = 0;
    ui->setupUi(this);
    connect(ui->brushSizeSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderChangeBrushSize(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinBoxChangeBrushSize()));
    connect(ui->dotBrushButton, SIGNAL(released()), this, SLOT(pencilDraw()));
    connect(ui->lineBrushButton, SIGNAL(released()), this, SLOT(lineDraw()));
    connect(ui->eraserButton, SIGNAL(released()), this, SLOT(eraser()));
    connect(ui->rectangleBrushButton, SIGNAL(released()), this, SLOT(rectDraw()));
    connect(ui->circleBrushButton, SIGNAL(released()), this, SLOT(circleDraw()));
    //connect(ui->clearFrameButton, SIGNAL(released()), this, SLOT(clearCanvas()));

    // connect(ui->lineBrushButton, &QPushButton::pressed, this, &SpriteEditorWindow::drawLine);

    connect(ui->actionNew, &QAction::triggered,
            this, &SpriteEditorWindow::newFile);
    connect(ui->actionOpen, &QAction::triggered,
            this, &SpriteEditorWindow::openFile);
    connect(ui->actionSave, &QAction::triggered,
            this, &SpriteEditorWindow::saveFile);
    connect(ui->actionSave_As, &QAction::triggered,
            this, &SpriteEditorWindow::saveAsFile);
    connect(ui->addFrameButton, &QPushButton::pressed,
            this, &SpriteEditorWindow::addFrame);
    connect(ui->deleteFrameButton, &QPushButton::pressed,
            this, &SpriteEditorWindow::deleteFrame);
    connect(ui->showPreviewButton, &QPushButton::pressed,
            this, &SpriteEditorWindow::showPreview);

    connect(ui->nextFrameButton, &QPushButton::pressed,
            this, &SpriteEditorWindow::nextFrame);
    connect(ui->previousFrameButton, &QPushButton::pressed,
            this, &SpriteEditorWindow::previousFrame);
    connect(ui->clearFrameButton, &QPushButton::pressed,
            this, &SpriteEditorWindow::clearFrame);


    //set default color
    ui->clearFrameButton->setStyleSheet("color: white");
    ui->colorPaletteButton->setFlat(false);
    ui->colorPaletteButton->setStyleSheet("QPushButton {background-color: black; border: 0px;}");
    ui->canvasWidget->setPenColor(Qt::black);
    sizeSelectionWindow* s = new sizeSelectionWindow(this, this);
    s->show();
    s->raise();
    s->activateWindow();
}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}

void SpriteEditorWindow::incrementCurrentFrameIndex() {
    QImage currentImage = ui->canvasWidget->getImage();
    model->saveFrame(currentFrameIndex, currentImage);
    if (currentFrameIndex < model->getFrames().size()) {
        currentFrameIndex++;
    }
    ui->canvasWidget->setImage(model->getFrames()[currentFrameIndex - 1]);
    ui->currentFrameIndexDisplay->setText(QString::number(currentFrameIndex));
}
void SpriteEditorWindow::decrementCurrentFrameIndex() {
    QImage currentImage = ui->canvasWidget->getImage();
    model->saveFrame(currentFrameIndex, currentImage);
    if (currentFrameIndex > 1) {
        currentFrameIndex--;
    }
    ui->canvasWidget->setImage(model->getFrames()[currentFrameIndex - 1]);
    ui->currentFrameIndexDisplay->setText(QString::number(currentFrameIndex));
}

void SpriteEditorWindow::sliderChangeBrushSize(int value)
{
    int brushSizeValue = value;
    ui->canvasWidget->setPenWidth(brushSizeValue);
    ui->spinBox->setValue(brushSizeValue);
}

void SpriteEditorWindow::spinBoxChangeBrushSize()
{

    int brushSizeValue = ui->spinBox->value();
    ui->canvasWidget->setPenWidth(brushSizeValue);
    ui->brushSizeSlider->setSliderPosition(brushSizeValue);
}

void SpriteEditorWindow::clearFrame(){
    QImage clearFrame = QImage(model->getFrames()[0].size(), QImage::Format_RGB32);
    clearFrame.fill(Qt::white);
    model->saveFrame(currentFrameIndex, clearFrame);
    ui->canvasWidget->setImage(clearFrame);
    model->updateTimeline(ui->framesSelectorWidget);
    ui->framesSelectorWidget->setSelectedFrameIndex(currentFrameIndex);
}

void SpriteEditorWindow::pencilDraw()
{
    ui->canvasWidget->toolChooserHelper(0);
}

void SpriteEditorWindow::lineDraw()
{
    ui->canvasWidget->toolChooserHelper(1);
}

void SpriteEditorWindow::eraser()
{
    ui->canvasWidget->toolChooserHelper(2);
}

void SpriteEditorWindow::rectDraw()
{
    ui->canvasWidget->toolChooserHelper(3);
}

void SpriteEditorWindow::circleDraw()
{
    ui->canvasWidget->toolChooserHelper(4);
}

void SpriteEditorWindow::clearCanvas()
{
    ui->canvasWidget->clearImage();
}

void SpriteEditorWindow::newFile() {
    sizeSelectionWindow* s = new sizeSelectionWindow(this, this);
    s->show();
    s->raise();
    s->activateWindow();
    model->newProject();
}
void SpriteEditorWindow::openFile() {
    std::cout << "open file\n";

    QString fileName = QFileDialog::getOpenFileName(this,
       tr("Open SSP File"), "",
       tr("SSP (*.ssp)"));

    model->openSSP(fileName.toUtf8().constData());
    model->updateTimeline(ui->framesSelectorWidget);
    ui->canvasWidget->setImage(model->getFrames().at(0));
     ui->framesSelectorWidget->setSelectedFrameIndex(currentFrameIndex);
}
void SpriteEditorWindow::saveFile() {
    QImage currentImage = ui->canvasWidget->getImage();
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save SSP File"), "",
        tr("SSP (*.ssp)"));
    model->saveFrame(currentFrameIndex, currentImage);
    model->saveAsSSP(fileName.toUtf8().constData());

}

void SpriteEditorWindow::saveAsFile() {
    QImage currentImage = ui->canvasWidget->getImage();

    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save GIF File"), "",
        tr("GIF (*.gif)"));

    model->saveFrame(currentFrameIndex, currentImage);
    model->saveAsGIF(fileName.toUtf8().constData());
}

void SpriteEditorWindow::addFrame() {
    QImage currentImage = ui->canvasWidget->getImage();
    model->saveFrame(currentFrameIndex, currentImage);
    model->addDuplicateFrame();
    currentFrameIndex = model->getFrames().length()-1;
    model->updateTimeline(ui->framesSelectorWidget);
     ui->framesSelectorWidget->setSelectedFrameIndex(currentFrameIndex);
}

void SpriteEditorWindow::addFirstFrame(){
    QImage currentImage = ui->canvasWidget->getImage();
    model->saveFrame(0, currentImage);
    model->updateTimeline(ui->framesSelectorWidget);
}

void SpriteEditorWindow::deleteFrame() {
   model->deleteFrame(currentFrameIndex);
   ui->canvasWidget->setImage(model->getFrames()[currentFrameIndex]);
   model->updateTimeline(ui->framesSelectorWidget);
   ui->framesSelectorWidget->setSelectedFrameIndex(currentFrameIndex);
}

void SpriteEditorWindow::showPreview()
{
    PreviewWindow *w = new PreviewWindow(model->getFrames());
    w->show();
}

void SpriteEditorWindow::on_colorPaletteButton_clicked()
{
    ui->colorPaletteButton->setFlat(true);
    ui->colorPaletteButton->setAutoFillBackground(true);
    ui->colorPaletteButton->setStyleSheet("background-color: rgba(255, 555, 255, 0);");
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid())
    {
        QPalette palette = ui->colorPaletteButton->palette();
        palette.setColor(ui->colorPaletteButton->backgroundRole(), color);
        palette.setColor(ui->colorPaletteButton->foregroundRole(), color);
        ui->colorPaletteButton->setAutoFillBackground(true);
        ui->colorPaletteButton->setPalette(palette);
        ui->canvasWidget->setPenColor(color);
    }
}

void SpriteEditorWindow::nextFrame()
{
    QImage image = ui->canvasWidget->getImage();
    QImage newImage = model->nextFrame(ui->framesSelectorWidget, image, currentFrameIndex);
    ui->canvasWidget->setImage(newImage);
    ui->currentFrameIndexDisplay->setText(QString::number(currentFrameIndex+1));
}

void SpriteEditorWindow::previousFrame()
{
    QImage image = ui->canvasWidget->getImage();
    QImage newImage = model->previousFrame(ui->framesSelectorWidget, image, currentFrameIndex);
    ui->canvasWidget->setImage(newImage);
    ui->currentFrameIndexDisplay->setText(QString::number(currentFrameIndex+1));
}

void SpriteEditorWindow::setDimensions(int dim) {
    dimensions = dim;
    model = new FramesModel(dimensions);
    ui->canvasWidget->init(currentFrameIndex, ui->framesSelectorWidget, model);
    ui->canvasWidget->setImageSize(dim);
    addFirstFrame();
}
