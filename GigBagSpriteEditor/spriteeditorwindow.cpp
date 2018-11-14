#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "scribblearea.h"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    currentFrameIndex = 0;
    ui->setupUi(this);

    connect(ui->brushSizeSlider, SIGNAL(sliderReleased()), this, SLOT(sliderChangeBrushSize()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinBoxChangeBrushSize()));
    connect(ui->dotBrushButton, SIGNAL(released()), this, SLOT(pencilDraw()));
    connect(ui->lineBrushButton, SIGNAL(released()), this, SLOT(lineDraw()));
    connect(ui->eraserButton, SIGNAL(released()), this, SLOT(eraser()));
    connect(ui->rectangleBrushButton, SIGNAL(released()), this, SLOT(rectDraw()));
    connect(ui->circleBrushButton, SIGNAL(released()), this, SLOT(circleDraw()));

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

}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}

void SpriteEditorWindow::sliderChangeBrushSize()
{
    int brushSizeValue = ui->brushSizeSlider->value();
    ui->canvasWidget->setPenWidth(brushSizeValue);
    ui->spinBox->setValue(brushSizeValue);
}

void SpriteEditorWindow::spinBoxChangeBrushSize()
{
    int brushSizeValue = ui->spinBox->value();
    ui->canvasWidget->setPenWidth(brushSizeValue);
    ui->brushSizeSlider->setSliderPosition(brushSizeValue);
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

void SpriteEditorWindow::newFile() {
    std::cout << "new file\n";
    model.newProject();
}
void SpriteEditorWindow::openFile() {
    std::cout << "open file\n";
    model.openSSP("test.ssp");
}
void SpriteEditorWindow::saveFile() {
    std::cout << "save file\n";
    QImage currentImage = ui->canvasWidget->getImage();
    model.saveFrame(currentFrameIndex, currentImage);
    model.saveAsSSP("testSaveFile");
}

void SpriteEditorWindow::saveAsFile() {
    std::cout << "save as file\n" ;
    QImage currentImage = ui->canvasWidget->getImage();
    model.saveFrame(currentFrameIndex, currentImage);
    model.saveAsGIF("testGIFSaveFile");
}

void SpriteEditorWindow::addFrame() {
    std::cout << "add frame\n";
    model.addDuplicateFrame();
}
void SpriteEditorWindow::deleteFrame() {
   std::cout << "delete frame\n";
   model.deleteFrame(currentFrameIndex);
}
