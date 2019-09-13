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
    void setMainMemoryCapacity(int v);

    void startFadeAnimation();

    void showModules();

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

    void on_pushButton_9_clicked();

    void on_pushBtn_setmem_clicked();

    void on_pushBtn_addjob_clicked();

    void on_pushBtn_reset_clicked();

private:
    Ui::mainwindow        *ui;
    QMovie                *loading_mov;
    QTimer                *launcher_timer;
    QTimer                *show_timer;
    QGraphicsOpacityEffect*opacityEffect;
    QPropertyAnimation    *propertyAnimation;
    QPoint                 m_startPoint;
    QPoint                 m_windowPoint;
    bool                   m_move;
    bool                   popUpMenuIsAvaliable;
    QPainter              *painter;
    THEME_COLOR_TYPE      currentThemeColorType;
    QFile                 *styleSheetLoader;
    QString                myStyleSheet;
    BuddyHeap             *bHeap;
private:
    void                   setTheme(QString target);
    void                   setWorkPageBtnAbledOrNot(bool e);
    void                   popUpMenu();
    void                   setPropertyAnimation(QByteArray, QVariant, QVariant, int,
                                                  QEasingCurve, QWidget*, QGraphicsEffect*, QWidget*);
    void                   setFadeInOrOutAnimation(QWidget*, QWidget*, int, FADE_TYPE);
    void                   setWidget7StyleSheet(QString name);
    void                   setMyStyleSheet(QString name);
    void                   hideModules();
    void                   setAllVisiualizeBtnsUnchecked();
    void                   setModulesStyleNFunctions();
    void                   setStartUpAnimation();
    void                   startWorkPageAnimation();
    void                   startOthersPageAnimation();
  //void                   themeSetNStartAnimation(COLOR_TYPE startColor, COLOR_TYPE endColor);
};

#endif // MAINWINDOW_H
