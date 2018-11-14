/********************************************************************************
** Form generated from reading UI file 'spriteeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEEDITORWINDOW_H
#define UI_SPRITEEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "framesarea.h"
#include "scribblearea.h"

QT_BEGIN_NAMESPACE

class Ui_SpriteEditorWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QWidget *centralWidget;
    ScribbleArea *canvasWidget;
    QWidget *brushToolsWidget;
    QGroupBox *brushToolBox;
    QPushButton *dotBrushButton;
    QPushButton *lineBrushButton;
    QSlider *brushSizeSlider;
    QPushButton *rectangleBrushButton;
    QPushButton *circleBrushButton;
    QLabel *brushSizeLabel;
    QSpinBox *spinBox;
    QPushButton *eraserButton;
    QWidget *timelineWidget;
    QPushButton *addFrameButton;
    QPushButton *deleteFrameButton;
    QPushButton *previousFrameButton;
    QPushButton *nextFrameButton;
    framesarea *framesSelectorWidget;
    QPushButton *showPreviewButton;
    QWidget *colorPickerWidget;
    QPushButton *colorPaletteButton;
    QLabel *colorPaletteLabel;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpriteEditorWindow)
    {
        if (SpriteEditorWindow->objectName().isEmpty())
            SpriteEditorWindow->setObjectName(QStringLiteral("SpriteEditorWindow"));
        SpriteEditorWindow->resize(800, 600);
        actionNew = new QAction(SpriteEditorWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave = new QAction(SpriteEditorWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(SpriteEditorWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionOpen = new QAction(SpriteEditorWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(SpriteEditorWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));
        canvasWidget = new ScribbleArea(centralWidget);
        canvasWidget->setObjectName(QStringLiteral("canvasWidget"));
        canvasWidget->setGeometry(QRect(156, 20, 512, 512));
        canvasWidget->setSizeIncrement(QSize(0, 0));
        brushToolsWidget = new QWidget(centralWidget);
        brushToolsWidget->setObjectName(QStringLiteral("brushToolsWidget"));
        brushToolsWidget->setGeometry(QRect(10, 20, 131, 331));
        brushToolBox = new QGroupBox(brushToolsWidget);
        brushToolBox->setObjectName(QStringLiteral("brushToolBox"));
        brushToolBox->setGeometry(QRect(0, 0, 141, 331));
        QFont font;
        font.setPointSize(15);
        brushToolBox->setFont(font);
        brushToolBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        brushToolBox->setAlignment(Qt::AlignCenter);
        dotBrushButton = new QPushButton(brushToolBox);
        dotBrushButton->setObjectName(QStringLiteral("dotBrushButton"));
        dotBrushButton->setGeometry(QRect(10, 80, 111, 41));
        lineBrushButton = new QPushButton(brushToolBox);
        lineBrushButton->setObjectName(QStringLiteral("lineBrushButton"));
        lineBrushButton->setGeometry(QRect(10, 130, 111, 41));
        brushSizeSlider = new QSlider(brushToolBox);
        brushSizeSlider->setObjectName(QStringLiteral("brushSizeSlider"));
        brushSizeSlider->setGeometry(QRect(10, 50, 71, 20));
        brushSizeSlider->setMinimum(1);
        brushSizeSlider->setMaximum(20);
        brushSizeSlider->setPageStep(2);
        brushSizeSlider->setOrientation(Qt::Horizontal);
        rectangleBrushButton = new QPushButton(brushToolBox);
        rectangleBrushButton->setObjectName(QStringLiteral("rectangleBrushButton"));
        rectangleBrushButton->setGeometry(QRect(10, 230, 111, 41));
        circleBrushButton = new QPushButton(brushToolBox);
        circleBrushButton->setObjectName(QStringLiteral("circleBrushButton"));
        circleBrushButton->setGeometry(QRect(10, 280, 111, 41));
        brushSizeLabel = new QLabel(brushToolBox);
        brushSizeLabel->setObjectName(QStringLiteral("brushSizeLabel"));
        brushSizeLabel->setGeometry(QRect(30, 30, 81, 17));
        brushSizeLabel->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(brushToolBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(80, 50, 41, 21));
        spinBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(20);
        eraserButton = new QPushButton(brushToolBox);
        eraserButton->setObjectName(QStringLiteral("eraserButton"));
        eraserButton->setGeometry(QRect(10, 180, 111, 41));
        timelineWidget = new QWidget(centralWidget);
        timelineWidget->setObjectName(QStringLiteral("timelineWidget"));
        timelineWidget->setGeometry(QRect(670, 19, 120, 511));
        timelineWidget->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        addFrameButton = new QPushButton(timelineWidget);
        addFrameButton->setObjectName(QStringLiteral("addFrameButton"));
        addFrameButton->setGeometry(QRect(10, 10, 101, 41));
        deleteFrameButton = new QPushButton(timelineWidget);
        deleteFrameButton->setObjectName(QStringLiteral("deleteFrameButton"));
        deleteFrameButton->setGeometry(QRect(10, 60, 101, 41));
        previousFrameButton = new QPushButton(timelineWidget);
        previousFrameButton->setObjectName(QStringLiteral("previousFrameButton"));
        previousFrameButton->setGeometry(QRect(10, 180, 101, 41));
        nextFrameButton = new QPushButton(timelineWidget);
        nextFrameButton->setObjectName(QStringLiteral("nextFrameButton"));
        nextFrameButton->setGeometry(QRect(10, 460, 101, 41));
        framesSelectorWidget = new framesarea(timelineWidget);
        framesSelectorWidget->setObjectName(QStringLiteral("framesSelectorWidget"));
        framesSelectorWidget->setGeometry(QRect(10, 229, 100, 221));
        showPreviewButton = new QPushButton(timelineWidget);
        showPreviewButton->setObjectName(QStringLiteral("showPreviewButton"));
        showPreviewButton->setGeometry(QRect(10, 120, 101, 41));
        colorPickerWidget = new QWidget(centralWidget);
        colorPickerWidget->setObjectName(QStringLiteral("colorPickerWidget"));
        colorPickerWidget->setGeometry(QRect(10, 360, 131, 161));
        colorPaletteButton = new QPushButton(colorPickerWidget);
        colorPaletteButton->setObjectName(QStringLiteral("colorPaletteButton"));
        colorPaletteButton->setGeometry(QRect(20, 40, 81, 81));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        colorPaletteButton->setPalette(palette);
        colorPaletteButton->setAutoFillBackground(true);
        colorPaletteButton->setFlat(true);
        colorPaletteLabel = new QLabel(colorPickerWidget);
        colorPaletteLabel->setObjectName(QStringLiteral("colorPaletteLabel"));
        colorPaletteLabel->setGeometry(QRect(10, 10, 81, 17));
        colorPaletteLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 514, 61, 31));
        SpriteEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpriteEditorWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        menuBar->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setStyleSheet(QStringLiteral("background-color: rgb(136, 138, 133);"));
        SpriteEditorWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpriteEditorWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral("background-color: rgb(85, 87, 83);"));
        SpriteEditorWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SpriteEditorWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        SpriteEditorWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);

        retranslateUi(SpriteEditorWindow);

        QMetaObject::connectSlotsByName(SpriteEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpriteEditorWindow)
    {
        SpriteEditorWindow->setWindowTitle(QApplication::translate("SpriteEditorWindow", "GigBag Sprite Editor", nullptr));
        actionNew->setText(QApplication::translate("SpriteEditorWindow", "New", nullptr));
        actionSave->setText(QApplication::translate("SpriteEditorWindow", "Save As SSP", nullptr));
        actionSave_As->setText(QApplication::translate("SpriteEditorWindow", "Save As GIF", nullptr));
        actionOpen->setText(QApplication::translate("SpriteEditorWindow", "Open", nullptr));
        brushToolBox->setTitle(QApplication::translate("SpriteEditorWindow", "Brush Tools", nullptr));
        dotBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Pencil", nullptr));
        lineBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Line", nullptr));
        rectangleBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Rectangle", nullptr));
        circleBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Circle", nullptr));
        brushSizeLabel->setText(QApplication::translate("SpriteEditorWindow", "Brush Size", nullptr));
        eraserButton->setText(QApplication::translate("SpriteEditorWindow", "Eraser", nullptr));
        addFrameButton->setText(QApplication::translate("SpriteEditorWindow", "Add Frame", nullptr));
        deleteFrameButton->setText(QApplication::translate("SpriteEditorWindow", "Delete Frame", nullptr));
        previousFrameButton->setText(QApplication::translate("SpriteEditorWindow", "\342\226\262", nullptr));
        nextFrameButton->setText(QApplication::translate("SpriteEditorWindow", "\342\226\274", nullptr));
        showPreviewButton->setText(QApplication::translate("SpriteEditorWindow", "Show Preview", nullptr));
        colorPaletteButton->setText(QString());
        colorPaletteLabel->setText(QApplication::translate("SpriteEditorWindow", "Brush Color", nullptr));
        label->setText(QApplication::translate("SpriteEditorWindow", "TextLabel", nullptr));
        menuFile->setTitle(QApplication::translate("SpriteEditorWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("SpriteEditorWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpriteEditorWindow: public Ui_SpriteEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITORWINDOW_H
