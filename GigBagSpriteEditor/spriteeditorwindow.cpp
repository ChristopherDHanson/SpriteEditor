#include "spriteeditorwindow.h"
#include "ui_spriteeditorwindow.h"
#include "scribblearea.h"
#include "framesarea.h"
#include "QColorDialog"

SpriteEditorWindow::SpriteEditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpriteEditorWindow)
{
    ui->setupUi(this);
    //ScribbleArea* sa = new ScribbleArea;
    connect(ui->lineBrushButton, &QPushButton::pressed, this, &SpriteEditorWindow::drawLine);

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
    connect(ui->colorPaletteButton, &QPushButton::pressed,
            this, &SpriteEditorWindow::showColorPalette);

}

SpriteEditorWindow::~SpriteEditorWindow()
{
    delete ui;
}

void SpriteEditorWindow::drawLine()
{
    //ScribbleArea::drawLineTo()
    std::cout << "draw line\n";
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
    model.saveAsSSP("testSaveFile");
}
void SpriteEditorWindow::saveAsFile() {
    std::cout << "save as file\n";
    model.saveAsGIF("testGIFSaveFile.gif");
}
void SpriteEditorWindow::addFrame() {
    std::cout << "add frame\n";
    model.addFrame();
}
void SpriteEditorWindow::deleteFrame() {
   std::cout << "delete frame\n";
   model.deleteFrame(currentFrameIndex);
}

void SpriteEditorWindow::showPreview()
{
    std::cout << "show preview\n";
    model.showPreview();
}

void SpriteEditorWindow::showColorPalette()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid()){
        QPalette palette = ui->colorPaletteButton->palette();
        palette.setColor(ui->colorPaletteButton->backgroundRole(), color);
        palette.setColor(ui->colorPaletteButton->foregroundRole(), color);
        ui->colorPaletteButton->setAutoFillBackground(true);
        ui->colorPaletteButton->setPalette(palette);
        //TODO: Method to send in the QColor value.
    }
}
