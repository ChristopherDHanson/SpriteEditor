#include "sizeselectionwindow.h"
#include "ui_sizeselectionwindow.h"

sizeSelectionWindow::sizeSelectionWindow(SpriteEditorWindow* seParent, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sizeSelectionWindow)
{
    ui->setupUi(this);

    theWindow = seParent;

    connect(ui->acceptButton, &QPushButton::pressed,
            this, &sizeSelectionWindow::enableAndSendDimensions);
}

sizeSelectionWindow::~sizeSelectionWindow()
{
    delete ui;
}

void sizeSelectionWindow::enableAndSendDimensions() {
    theWindow->setDimensions(ui->plainTextEdit->toPlainText().toInt());
    theWindow->setEnabled(true);
    theWindow->centralWidget()->setEnabled(true);
    this->destroy();
}
