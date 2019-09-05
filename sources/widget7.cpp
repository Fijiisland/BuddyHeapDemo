#include "widget7.h"
#include "ui_widget7.h"

widget7::widget7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget7)
{
    ui->setupUi(this);
    currentColor = QColor(255, 165, 0);
    QFile styleLoader(STYLESHEETSPATH+"theme1.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme1 = tr(styleLoader.readAll());
    styleLoader.close();
    setStyleSheet(theme1);
}

widget7::~widget7()
{
    delete ui;
}

void widget7::setColor(const QColor targtetColor){
    currentColor = targtetColor;
    QString style = QString("QWidget{"
                            "background-color:rgb(%1, %2, %3);"
                            "border-style:inset;"
                            "border-width:3px;"
                            "border-color:rgb(30,144,255);"
                            "}"
                            ).arg(targtetColor.red(),targtetColor.green(),targtetColor.blue());
    setStyleSheet(style);
}

QColor widget7::getColor() const
{
    return currentColor;
}
