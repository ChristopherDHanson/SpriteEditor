#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QObject>
#include <QWidget>

class ScribbleArea : public QWidget
{
//    Q_OBJECT

public:
    ScribbleArea(QWidget *parent = 0);
    ~ScribbleArea();
//    ScribbleArea(const ScribbleArea& other);
//    ScribbleArea& operator=(ScribbleArea other);
    QImage image;
    //void setPenColor(const QColor &newColor);
private:
        bool openImage(const QString &fileName);
        bool saveImage(const QString &fileName, const char *fileFormat);
        void setPenColor(const QColor &newColor);
        void setPenWidth(int newWidth);

        bool isModified() const { return modified; }
        QColor penColor() const { return myPenColor; }
        int penWidth() const { return myPenWidth; }

    public slots:
        void clearImage();
        void print();

    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;
        void paintEvent(QPaintEvent *event) override;
        void resizeEvent(QResizeEvent *event) override;

    private:
        void drawLineTo(const QPoint &endPoint);
        void resizeImage(QImage *image, const QSize &newSize);

        bool modified;
        bool scribbling;
        int myPenWidth;
        QColor myPenColor;
//        QImage image;
        QPoint lastPoint;
};

#endif // SCRIBBLEAREA_H
