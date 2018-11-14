#ifndef SPRITEEDITORWINDOW_H
#define SPRITEEDITORWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "FramesModel.h"

namespace Ui {
class SpriteEditorWindow;
}

class SpriteEditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpriteEditorWindow(QWidget *parent = nullptr);
    ~SpriteEditorWindow();
    void setDimensions(int dim);

private:
    Ui::SpriteEditorWindow *ui;
    FramesModel* model;
    int currentFrameIndex;
    int dimensions;

private slots:
    void sliderChangeBrushSize();
    void spinBoxChangeBrushSize();
    void pencilDraw();
    void lineDraw();
    void eraser();
    void rectDraw();
    void circleDraw();
    void clearCanvas();
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    void addFrame();
    void deleteFrame();
    void showPreview();
    void on_colorPaletteButton_clicked();
    void on_actionOpen_triggered();
};

#endif // SPRITEEDITORWINDOW_H
