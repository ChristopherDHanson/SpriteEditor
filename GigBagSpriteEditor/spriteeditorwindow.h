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

private:
    Ui::SpriteEditorWindow *ui;
    FramesModel model;
    int currentFrameIndex;

private slots:
    void sliderChangeBrushSize();
    void spinBoxChangeBrushSize();
    void pencilDraw();
    void lineDraw();
    void eraser();
    void rectDraw();
    void circleDraw();
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    void addFrame();
    void deleteFrame();
};

#endif // SPRITEEDITORWINDOW_H
