#ifndef WIDGET_3_H
#define WIDGET_3_H

#include <QWidget>
#include "_utility.h"
#include "mainwindow.h"

namespace Ui {
class widget_3;
}

class widget_3 : public QWidget
{
    Q_OBJECT

public:
    explicit widget_3(QWidget *parent = nullptr);
    ~widget_3();

private:
    Ui::widget_3 *ui;
};

extern Ui::mainwindow *ui_main;

#endif // WIDGET_3_H
