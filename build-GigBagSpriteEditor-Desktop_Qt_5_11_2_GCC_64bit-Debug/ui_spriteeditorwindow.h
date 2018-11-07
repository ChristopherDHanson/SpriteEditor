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

QT_BEGIN_NAMESPACE

class Ui_SpriteEditorWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen;
    QWidget *centralWidget;
    QWidget *canvasWidget;
    QWidget *brushToolsWidget;
    QGroupBox *brushToolBox;
    QPushButton *dotBrushButton;
    QPushButton *lineBrushButton;
    QSlider *brushSizeSlider;
    QPushButton *rectangleBrushButton;
    QPushButton *circleBrushButton;
    QLabel *brushSizeLabel;
    QSpinBox *spinBox;
    QWidget *timelineWidget;
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
        canvasWidget = new QWidget(centralWidget);
        canvasWidget->setObjectName(QStringLiteral("canvasWidget"));
        canvasWidget->setGeometry(QRect(145, 20, 512, 512));
        brushToolsWidget = new QWidget(centralWidget);
        brushToolsWidget->setObjectName(QStringLiteral("brushToolsWidget"));
        brushToolsWidget->setGeometry(QRect(10, 59, 120, 451));
        brushToolBox = new QGroupBox(brushToolsWidget);
        brushToolBox->setObjectName(QStringLiteral("brushToolBox"));
        brushToolBox->setGeometry(QRect(0, 0, 121, 451));
        dotBrushButton = new QPushButton(brushToolBox);
        dotBrushButton->setObjectName(QStringLiteral("dotBrushButton"));
        dotBrushButton->setGeometry(QRect(10, 90, 101, 41));
        lineBrushButton = new QPushButton(brushToolBox);
        lineBrushButton->setObjectName(QStringLiteral("lineBrushButton"));
        lineBrushButton->setGeometry(QRect(10, 140, 101, 41));
        brushSizeSlider = new QSlider(brushToolBox);
        brushSizeSlider->setObjectName(QStringLiteral("brushSizeSlider"));
        brushSizeSlider->setGeometry(QRect(10, 60, 71, 20));
        brushSizeSlider->setOrientation(Qt::Horizontal);
        rectangleBrushButton = new QPushButton(brushToolBox);
        rectangleBrushButton->setObjectName(QStringLiteral("rectangleBrushButton"));
        rectangleBrushButton->setGeometry(QRect(10, 200, 101, 41));
        circleBrushButton = new QPushButton(brushToolBox);
        circleBrushButton->setObjectName(QStringLiteral("circleBrushButton"));
        circleBrushButton->setGeometry(QRect(10, 260, 101, 41));
        brushSizeLabel = new QLabel(brushToolBox);
        brushSizeLabel->setObjectName(QStringLiteral("brushSizeLabel"));
        brushSizeLabel->setGeometry(QRect(10, 30, 71, 17));
        spinBox = new QSpinBox(brushToolBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(80, 60, 31, 21));
        timelineWidget = new QWidget(centralWidget);
        timelineWidget->setObjectName(QStringLiteral("timelineWidget"));
        timelineWidget->setGeometry(QRect(670, 59, 120, 251));
        SpriteEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpriteEditorWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SpriteEditorWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpriteEditorWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
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
        actionSave->setText(QApplication::translate("SpriteEditorWindow", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("SpriteEditorWindow", "Save As", nullptr));
        actionOpen->setText(QApplication::translate("SpriteEditorWindow", "Open", nullptr));
        brushToolBox->setTitle(QApplication::translate("SpriteEditorWindow", "Brush Tools", nullptr));
        dotBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Dot", nullptr));
        lineBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Line", nullptr));
        rectangleBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Rectangle", nullptr));
        circleBrushButton->setText(QApplication::translate("SpriteEditorWindow", "Circle", nullptr));
        brushSizeLabel->setText(QApplication::translate("SpriteEditorWindow", "Brush Size", nullptr));
        menuFile->setTitle(QApplication::translate("SpriteEditorWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("SpriteEditorWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpriteEditorWindow: public Ui_SpriteEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITORWINDOW_H
