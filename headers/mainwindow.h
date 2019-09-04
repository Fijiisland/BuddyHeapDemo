#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "_utility.h"

enum THEME_TYPE{THEME1, THEME2, THEME3, THEME4,
                 THEME5, THEME6, THEME7, THEME8};

namespace Ui {
class mainwindow;
}

class mainwindow : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString styleSheet READ getStyleSheet WRITE setStyleSheet)

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
    QGraphicsOpacityEffect *opacityEffect;
    QPropertyAnimation     *propertyAnimation;
    QPoint                 m_startPoint;
    QPoint                 m_windowPoint;
    bool                   m_move;
    QPainter               *painter;
    const QString          STYLESHEETSPATH;
    const QString          FONTSPATH;
    const QString          IMAGESPATH;
    const QString          themes[8];
    THEME_TYPE             currentThemeType;
    QString                targetStyleSheet;
private:
    QString getStyleSheet();
    void          setStyleSheet(const QString styleSheet);
    void          hide_modules();
    void          setAllVisiualizeBtnsUnchecked();
    void          setModulesStyle();
    void          setAnimation();
    void          startWorkPageAnimation();
    void          startOthersPageAnimation();
    void          themeSetNStartAnimation(THEME_TYPE startType, THEME_TYPE endType);
};

#endif // MAINWINDOW_H
