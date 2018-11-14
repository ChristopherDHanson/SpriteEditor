/********************************************************************************
** Form generated from reading UI file 'previewwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWWINDOW_H
#define UI_PREVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewWindow
{
public:
    QPushButton *closeButton;
    QWidget *reviewWidget;
    QLabel *frameLabel;
    QSlider *fpsSlider;
    QLabel *fpsSliderLabel;
    QSpinBox *fpsSpinBox;

    void setupUi(QDialog *PreviewWindow)
    {
        if (PreviewWindow->objectName().isEmpty())
            PreviewWindow->setObjectName(QStringLiteral("PreviewWindow"));
        PreviewWindow->resize(385, 328);
        closeButton = new QPushButton(PreviewWindow);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(280, 290, 89, 25));
        reviewWidget = new QWidget(PreviewWindow);
        reviewWidget->setObjectName(QStringLiteral("reviewWidget"));
        reviewWidget->setGeometry(QRect(60, 10, 261, 231));
        frameLabel = new QLabel(reviewWidget);
        frameLabel->setObjectName(QStringLiteral("frameLabel"));
        frameLabel->setGeometry(QRect(20, 10, 211, 211));
        fpsSlider = new QSlider(PreviewWindow);
        fpsSlider->setObjectName(QStringLiteral("fpsSlider"));
        fpsSlider->setGeometry(QRect(100, 250, 161, 20));
        fpsSlider->setOrientation(Qt::Horizontal);
        fpsSliderLabel = new QLabel(PreviewWindow);
        fpsSliderLabel->setObjectName(QStringLiteral("fpsSliderLabel"));
        fpsSliderLabel->setGeometry(QRect(70, 250, 31, 17));
        fpsSpinBox = new QSpinBox(PreviewWindow);
        fpsSpinBox->setObjectName(QStringLiteral("fpsSpinBox"));
        fpsSpinBox->setGeometry(QRect(270, 245, 48, 31));

        retranslateUi(PreviewWindow);

        QMetaObject::connectSlotsByName(PreviewWindow);
    } // setupUi

    void retranslateUi(QDialog *PreviewWindow)
    {
        PreviewWindow->setWindowTitle(QApplication::translate("PreviewWindow", "Preview", nullptr));
        closeButton->setText(QApplication::translate("PreviewWindow", "Close", nullptr));
        frameLabel->setText(QApplication::translate("PreviewWindow", "TextLabel", nullptr));
        fpsSliderLabel->setText(QApplication::translate("PreviewWindow", "FPS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewWindow: public Ui_PreviewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWWINDOW_H
