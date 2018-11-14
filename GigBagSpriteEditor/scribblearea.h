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
//    ~ScribbleArea();
//    ScribbleArea(const ScribbleArea& other);
//    ScribbleArea& operator=(ScribbleArea other);
        void setPenColor(const QColor &newColor);
        void setPenWidth(int newWidth);
        void toolChooserHelper(int tool);
        void setImageSize(int size);
        void setImage(QImage newImage);
        QImage getImage();
private:
        bool openImage(const QString &fileName);
        bool saveImage(const QString &fileName, const char *fileFormat);
        bool isModified() const { return modified; }
        QColor penColor() const { return myPenColor; }
        int penWidth() const { return myPenWidth; }
        double imageSize;

    public slots:
        void clearImage();
        void print();

    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;
        void paintEvent(QPaintEvent *event) override;

    private:
        void drawingTools(const QPoint &endPoint);
        void pencilTool(const QPoint &endPoint);
        void lineTool(const QPoint &endPoint);
        void rectangleTool(const QPoint &endPoint);
        void ellipseTool(const QPoint &endPoint);
        void eraserTool(const QPoint &endPoint);
        void resizeImage(QImage *image, const QSize &newSize);
        QPoint normalizePos(QMouseEvent *event);

        bool modified;
        bool scribbling;
        int myPenWidth;
        int drawTool;
        QColor myPenColor;
        QImage image;
        QPoint lastPoint;
};

#endif // SCRIBBLEAREA_H
