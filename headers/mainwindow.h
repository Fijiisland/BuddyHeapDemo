#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "_utility.h"

namespace Ui {
class mainwindow;
}

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
protected:
      virtual void mousePressEvent(QMouseEvent *event);

      virtual void mouseMoveEvent(QMouseEvent *event);

      virtual void mouseReleaseEvent(QMouseEvent *event);
private slots:
    void start_fade_animation();

    void show_modules();

    void on_pushBtn_mini_clicked();

    void on_pushBtn_close_clicked();

    void on_pushBtn_work_clicked(bool checked);

    void on_pushBtn_visualize_clicked(bool checked);

    void on_pushBtn_others_clicked(bool checked);

    void on_pushBtn_start_clicked();

    void on_pushButton_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_5_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_7_clicked(bool checked);

    void on_pushButton_8_clicked(bool checked);

private:
    Ui::mainwindow         *ui;
    QMovie                 *loading_mov;
    QTimer                 *launcher_timer;
    QTimer                 *show_timer;
    QGraphicsOpacityEffect *fade_effect_GPE;
    QPropertyAnimation     *fade_effect_PA;
    QPoint                 m_startPoint;
    QPoint                 m_windowPoint;
    bool                   m_move;
    QPainter               *painter;
    const QString          STYLESHEETSPATH;
    const QString          FONTSPATH;
    const QString          IMAGESPATH;
private:
    void hide_modules();
    void setAllVisiualizeBtnsUnchecked();
    void setModulesStyle();
    void setAnimation();
    void startWorkPageAnimation();
    void startOthersPageAnimation();
};

#endif // MAINWINDOW_H
