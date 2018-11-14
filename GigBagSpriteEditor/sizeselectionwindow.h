#ifndef SIZESELECTIONWINDOW_H
#define SIZESELECTIONWINDOW_H

#include <QDialog>
#include "spriteeditorwindow.h"

namespace Ui {
class sizeSelectionWindow;
}

class sizeSelectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit sizeSelectionWindow(SpriteEditorWindow* seParent, QWidget *parent = nullptr);
    ~sizeSelectionWindow();

private:
    Ui::sizeSelectionWindow *ui;
    SpriteEditorWindow* theWindow;

private slots:
    void enableAndSendDimensions();
};

#endif // SIZESELECTIONWINDOW_H
