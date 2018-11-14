#ifndef FRAMESAREA_H
#define FRAMESAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

class framesarea : public QWidget
{
    QVBoxLayout *vlayout = nullptr;
    QVector<QPushButton*> *buttonFrames = new QVector<QPushButton*>();
    int selectedFrameIndex;
    void clearFrames();
public:
    explicit framesarea(QWidget *parent = nullptr);
    void updateFramesArea(QVector<QImage> *frames);
    void setSelectedFrameIndex(int frameIndex);
};

#endif // FRAMESAREA_H
