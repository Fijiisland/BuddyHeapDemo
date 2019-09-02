#include "headers/widget_3.h"
#include "ui_widget_3.h"

widget_3::widget_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_3)
{
    ui->setupUi(this);
}

widget_3::~widget_3()
{
    delete ui;
}
