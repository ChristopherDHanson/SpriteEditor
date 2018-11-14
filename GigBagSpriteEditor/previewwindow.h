#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class PreviewWindow;
}

class PreviewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewWindow(QVector<QImage> frames, QWidget *parent = nullptr);
    ~PreviewWindow();

private slots:
    void on_closeButton_pressed();
    void on_fpsSpinBox_valueChanged(int arg1);
    void on_fpsSlider_valueChanged(int value);

private:
    Ui::PreviewWindow *ui;
    int currentFrameIndex;
    QVector<QImage> frames;
    QTimer *timer;
    void showImage(QImage frame);
    void switchImage();
    void setTimer(int fps);
};

#endif // PREVIEWWINDOW_H
