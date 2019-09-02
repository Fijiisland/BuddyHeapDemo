#include "customtitlebar.h"
#include "ui_customtitlebar.h"

customTitleBar::customTitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customTitleBar)
{
    ui->setupUi(this);
}

customTitleBar::~customTitleBar()
{
    delete ui;
}
