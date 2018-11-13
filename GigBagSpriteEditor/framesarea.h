#ifndef FRAMESAREA_H
#define FRAMESAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "FramesModel.h"

class framesarea : public QWidget
{
    QVBoxLayout *vlayout = nullptr;
    FramesModel *model = nullptr;
    int selectedFrameIndex;
public:
    explicit framesarea(QWidget *parent = nullptr);
    void setModel(FramesModel *_model);
    void updateFramesArea();
    void setSelectedFrameIndex(int frameIndex);
    void selectPreviousFrame();
    void selectNextFrame();
};

#endif // FRAMESAREA_H
