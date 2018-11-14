#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

#include "scribblearea.h"
//#include <QMouseEvent>
//#include <QPainter>
//#include <QtConfig>

ScribbleArea::ScribbleArea(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    scribbling = false;
    myPenWidth = 1;
    myPenColor = Qt::black;
    drawTool = 0;
    image = QImage(64, 64, QImage::Format_RGB32);
    image.fill(Qt::white);
}

bool ScribbleArea::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());

    if (visibleImage.save(fileName, fileFormat))
    {
        modified = false;
        return true;
    }
    else
        return false;
}

QImage ScribbleArea::getImage()
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());
    return visibleImage;
}

void ScribbleArea::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

void ScribbleArea::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}

void ScribbleArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}

void ScribbleArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //lastPoint = event->pos();
        lastPoint = normalizePos(event);
        scribbling = true;
    }
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling && drawTool == 0)
        pencilTool(normalizePos(event));

    else if ((event->buttons() & Qt::LeftButton) && scribbling && drawTool == 2)
        eraserTool(normalizePos(event));
}

void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling)
    {
        drawingTools(normalizePos(event));
        scribbling = false;
    }
}

void ScribbleArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();

    QPixmap tempPix;
    Qt::ImageConversionFlag flags=Qt::AutoColor;
    tempPix.convertFromImage(image, flags);

    //QSize sizeSmall = QSize(64,64);
    QSize sizeLarge = QSize(512, 512);
    //tempPix = tempPix.scaled(sizeSmall);
    tempPix = tempPix.scaled(sizeLarge);

    QImage tempImage;
    tempImage = tempPix.toImage();


    //painter.drawPixmap(dirtyRect, tempPix, dirtyRect);
    painter.drawImage(dirtyRect, tempImage, dirtyRect);
    update();
}

void ScribbleArea::resizeEvent(QResizeEvent *event)
{
//    if (width() > image.width() || height() > image.height()) {
//        int newWidth = qMax(width() + 128, image.width());
//        int newHeight = qMax(height() + 128, image.height());
//        resizeImage(&image, QSize(newWidth, newHeight));
//        update();
//    }
//    QWidget::resizeEvent(event);
}

// assigns tool choice int for corresponding tool function for switch
void ScribbleArea::toolChooserHelper(int tool)
{
    drawTool = tool;
}

// helper method to choose the drawing tools from buttons
void ScribbleArea::drawingTools(const QPoint &endPoint)
{
    switch (drawTool)
    {
        case 0: // pencil
        pencilTool(endPoint);
        break;
        case 1: // line
        lineTool(endPoint);
        break;
        case 2: // eraser
        eraserTool(endPoint);
        break;
        case 3:  // rectangle
        rectangleTool(endPoint);
        break;
        case 4: // circle
        ellipseTool(endPoint);
        break;
    }
}

void ScribbleArea::pencilTool(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void ScribbleArea::lineTool(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));

    painter.drawLine(lastPoint.x(), lastPoint.y(), endPoint.x(), endPoint.y());
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
}

void ScribbleArea::rectangleTool(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));

    painter.drawRect(lastPoint.x(), lastPoint.y(), endPoint.x()-lastPoint.x(), endPoint.y()-lastPoint.y());
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
}

void ScribbleArea::ellipseTool(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));

    painter.drawEllipse(lastPoint.x(), lastPoint.y(), endPoint.x()-lastPoint.x(), endPoint.y()-lastPoint.y());
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
}

void ScribbleArea::eraserTool(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(Qt::white, myPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}

void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void ScribbleArea::print()
{
//#if QT_CONFIG(printdialog)
//    QPrinter printer(QPrinter::HighResolution);

//    QPrintDialog printDialog(&printer, this);

//    if (printDialog.exec() == QDialog::Accepted) {
//        QPainter painter(&printer);
//        QRect rect = painter.viewport();
//        QSize size = image.size();
//        size.scale(rect.size(), Qt::KeepAspectRatio);
//        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
//        painter.setWindow(image.rect());
//        painter.drawImage(0, 0, image);
//    }
//#endif // QT_CONFIG(printdialog)
}

QPoint ScribbleArea::normalizePos(QMouseEvent *event) {
    QPoint toReturn;
    toReturn.setX(qRound(64.0 * (event->pos().x()) / 512.0) );
    toReturn.setY(qRound(64.0 * (event->pos().y()) / 512.0) );
    return toReturn;
}
