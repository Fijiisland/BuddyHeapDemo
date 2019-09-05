#ifndef WIDGET7_H
#define WIDGET7_H

#include <QWidget>
#include "headers/_utility.h"

namespace Ui {
class widget7;
}

class widget7 : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ getColor WRITE setColor)

public:
    explicit widget7(QWidget *parent = nullptr);
    ~widget7();

private:
    Ui::widget7           *ui;
    QColor                 currentColor;
private:
    void                   setColor(QColor);
    QColor                 getColor() const;
};

#endif // WIDGET7_H
