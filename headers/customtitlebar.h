#ifndef CUSTOMTITLEBAR_H
#define CUSTOMTITLEBAR_H

#include <QWidget>

namespace Ui {
class customTitleBar;
}

class customTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit customTitleBar(QWidget *parent = nullptr);
    ~customTitleBar();

private:
    Ui::customTitleBar *ui;
};

#endif // CUSTOMTITLEBAR_H
