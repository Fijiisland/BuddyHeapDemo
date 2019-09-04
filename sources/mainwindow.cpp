#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow),
    STYLESHEETSPATH(":/styleSheets/share/styleSheets/"),
    FONTSPATH(":/fonts/share/fonts/"),
    IMAGESPATH(":/images/share/images/"),
    themes{"theme1.qss","theme2.qss","theme3.qss","theme4.qss","theme5.qss","theme6.qss","theme7.qss","theme8.qss",},
    currentThemeType(THEME_TYPE::THEME1)
{
    ui->setupUi(this);
    setModulesStyle();
    setAnimation();
    hide_modules();
}

mainwindow::~mainwindow()
{
    delete ui;
}
/*
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
*/
void mainwindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        m_move = true;
        m_startPoint = event->globalPos();
        m_windowPoint = this->frameGeometry().topLeft();
    }
}

void mainwindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        QPoint relativePos = event->globalPos() - m_startPoint;
        this->move(m_windowPoint + relativePos );
    }
}

void mainwindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        m_move = false;
    }
}

void mainwindow::start_fade_animation()
{
    launcher_timer->stop();
    propertyAnimation->setStartValue(1);
    propertyAnimation->setEndValue(0);
    propertyAnimation->start(QAbstractAnimation::KeepWhenStopped);
    show_timer = new QTimer;
    show_timer->start(1000);
    connect(show_timer, SIGNAL(timeout()), this, SLOT(show_modules()));
}

void mainwindow::show_modules()
{
    loading_mov->stop();
    ui->widget_2->hide();
    ui->line_4->show();
    ui->pushBtn_work->show();
    ui->pushBtn_visualize->show();
    ui->line_6->show();
    ui->frame_2->show();
    ui->line_7->show();
    ui->frame_3->show();
    ui->pushBtn_others->show();
    ui->line_9->show();
}

void mainwindow::on_pushBtn_mini_clicked()
{
    if(this->windowState() != Qt::WindowMinimized)
        this->setWindowState(Qt::WindowMinimized);    // 在macOS下有bug
}

void mainwindow::on_pushBtn_close_clicked()
{
    this->close();
}

void mainwindow::hide_modules()
{
    ui->frame_3->hide();
    ui->widget_3->hide();
    ui->widget_4->hide();
    ui->widget_5->hide();
    ui->line_4->hide();
    ui->line_6->hide();
    ui->pushBtn_work->hide();
    ui->pushBtn_visualize->hide();
    ui->frame_2->hide();
    ui->line_7->hide();
    ui->pushBtn_others->hide();
    ui->line_9->hide();
}

void mainwindow::setAllVisiualizeBtnsUnchecked()
{
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->pushButton_6->setChecked(false);
    ui->pushButton_7->setChecked(false);
    ui->pushButton_8->setChecked(false);
}

void mainwindow::setModulesStyle()
{
    ui->frame->setStyleSheet("#frame{border:1.4px solid #BEBEBE}#background-color:#D3D3D3");
    this->setWindowFlags(Qt::FramelessWindowHint);
    int fontID1 = QFontDatabase::addApplicationFont(FONTSPATH+"SF-Pro-Display-Ultralight.otf");
    int fontID2 = QFontDatabase::addApplicationFont(FONTSPATH+"SF-Pro-Display-Regular.otf");
    QString SP_Ultralight = QFontDatabase::applicationFontFamilies(fontID1).at(0);
    QString SP_Regular = QFontDatabase::applicationFontFamilies(fontID2).at(0);
    ui->label_launcher->setFont(QFont(SP_Ultralight, 22));
    ui->label_headline->setFont(QFont("Segoe UI", 9));
    ui->label_headline->setStyleSheet("color:#FFFFFF;");
    ui->pushBtn_setmem->setStyleSheet("QPushButton{border-image: url("+IMAGESPATH+"setmem_regular.png);}"
                                      "QPushButton:hover{border-image: url("+IMAGESPATH+"setmem_hover.png);}"
                                      "QPushButton:pressed{border-image: url("+IMAGESPATH+"setmem_press.png);}");
    ui->pushBtn_addjob->setStyleSheet("QPushButton{border-image: url("+IMAGESPATH+"addjob_regular.png);}"
                                      "QPushButton:hover{border-image: url("+IMAGESPATH+"addjob_hover.png);}"
                                      "QPushButton:pressed{border-image: url("+IMAGESPATH+"addjob_press.png);}");
    ui->pushBtn_zoom->setEnabled(false);
    ui->pushBtn_close->setStyleSheet("QPushButton{border-image: url("+IMAGESPATH+"close1.png);}"
                                     "QPushButton:hover{border-image: url("+IMAGESPATH+"close.png);}"
                                     "QPushButton:pressed{border-image: url("+IMAGESPATH+"close-1.png);}");
    ui->pushBtn_mini->setStyleSheet("QPushButton{border-image: url("+IMAGESPATH+"mini1.png);}"
                                    "QPushButton:hover{border-image: url("+IMAGESPATH+"mini.png);}"
                                    "QPushButton:pressed{border-image: url("+IMAGESPATH+"mini-1.png);}");
    ui->pushBtn_work->setStyleSheet("QPushButton{border-image: url("+IMAGESPATH+"work1.png);}"
                                     "QPushButton:hover{border-image: url("+IMAGESPATH+"work.png);}"
                                     "QPushButton:checked{border-image: url("+IMAGESPATH+"work-1.png);}");
    ui->pushBtn_visualize->setStyleSheet("QPushButton{border-image: url("+IMAGESPATH+"visualize1.png);}"
                                         "QPushButton:hover{border-image: url("+IMAGESPATH+"visualize.png);}"
                                         "QPushButton:checked{border-image: url("+IMAGESPATH+"visualize-1.png);}");
    ui->pushBtn_others->setStyleSheet("QPushButton{border-image: url("+IMAGESPATH+"others1.png);}"
                                      "QPushButton:hover{border-image: url("+IMAGESPATH+"others.png);}"
                                      "QPushButton:checked{border-image: url("+IMAGESPATH+"others-1.png);}");
    ui->label_welcome->setFont(QFont("微软雅黑 Light", 30));
    ui->label_welcome->setStyleSheet("Color:#708090;");
    ui->label_12->setFont(QFont("微软雅黑 Light", 30));
    ui->label_12->setStyleSheet("Color:#708090;");
    ui->label_13->setFont(QFont("微软雅黑 Light", 15));
    ui->label_13->setStyleSheet("Color:#708090;");
    ui->label_14->setFont(QFont("微软雅黑", 10));
    ui->label_14->setStyleSheet("Color:#708090;");
    ui->label_15->setFont(QFont("微软雅黑", 10));
    ui->label_15->setStyleSheet("Color:#708090;");
    ui->label_16->setFont(QFont("微软雅黑", 10));
    ui->label_16->setStyleSheet("Color:#708090;");
    ui->label_17->setFont(QFont("微软雅黑 Light", 15));
    ui->label_17->setStyleSheet("Color:#708090;");
    ui->label_18->setFont(QFont("微软雅黑 Light", 15));
    ui->label_18->setStyleSheet("Color:#708090;");
    ui->label_19->setFont(QFont("微软雅黑", 10));
    ui->label_19->setStyleSheet("Color:#708090;");
    ui->label_20->setFont(QFont("微软雅黑", 10));
    ui->label_20->setStyleSheet("Color:#708090;");
    ui->label_21->setFont(QFont("微软雅黑", 10));
    ui->label_21->setStyleSheet("Color:#708090;");
    ui->label_22->setFont(QFont(SP_Ultralight, 32));
    ui->label_22->setStyleSheet("Color:#708090;");
    ui->label_23->setFont(QFont("微软雅黑", 10));
    ui->label_23->setStyleSheet("Color:#708090;");
    ui->label_7->setFont(QFont("微软雅黑", 10));
    ui->label_7->setStyleSheet("Color:#708090;");
    ui->label_3->setFont(QFont("微软雅黑 Light", 30));
    ui->label_3->setStyleSheet("Color:#708090;");
    ui->label_4->setFont(QFont("微软雅黑", 9));
    ui->label_4->setStyleSheet("Color:#708090;");
    ui->label_hint->setFont(QFont("微软雅黑", 10));
    ui->label_hint->setStyleSheet("Color:#708090;");
    ui->pushBtn_visualize->setEnabled(false);
    ui->pushBtn_others->setEnabled(false);
    ui->pushButton->setChecked(true);
    ui->pushButton->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(255,165,0);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(255,165,0);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");
    ui->pushButton_2->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(30,144,255);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");
    ui->pushButton_3->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(0,205,0);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(0,205,0);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");
    ui->pushButton_4->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(130,130,130);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(130,130,130);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");
    ui->pushButton_5->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(36,41,46);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(36,41,46);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");
    ui->pushButton_6->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(255,62,150);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(255,62,150);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");
    ui->pushButton_7->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(255,215,0);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(255,215,0);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");
    ui->pushButton_8->setStyleSheet(
                "QPushButton{"
                "background-color:rgb(148,0,211);"
                "border-radius:9px;"
                "}"
                "QPushButton:checked{"
                "background-color:rgb(148,0,211);"
                "border-style:outset;"
                "border-width:3px;"
                "border-color:rgb(30,144,255);"
                "border-radius:9px;"
                "}");

    ui->pushBtn_start->setStyleSheet(
                "QPushButton{"
                "background-color:rgba(255,255,255,100);"
                "border-style:inset;"
                "border-width:1px;"
                "border-color:rgb(36,41,46);"
                "border-radius:10px;"
                "}"
                "QPushButton:hover{"
                "background-color:rgba(36,41,46,100);"
                "border-style:inset;"
                "border-width:1px;"
                "border-color:rgb(36,41,46);"
                "border-radius:10px;"
                "}"
                "QPushButton:pressed{"
                "background-color:rgba(5, 5, 5);"
                "border-style:inset;"
                "border-width:1px;"
                "border-color:rgb(36,41,46);"
                "border-radius:10px;"
                "}");
    ui->pushBtn_start->setFont(QFont("微软雅黑", 10));
    QFrame *parent_frame = ui->frame_3;
    ui->widget_3->setParent(parent_frame);
    ui->widget_4->setParent(parent_frame);
    ui->widget_5->setParent(parent_frame);
    QFile styleLoader(STYLESHEETSPATH+"theme1.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme1 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme1);
}

void mainwindow::setAnimation()
{
    loading_mov = new QMovie(IMAGESPATH+"loading.gif");
    loading_mov->setSpeed(150);
    ui->label_loading->setMovie(loading_mov);
    loading_mov->start();

    opacityEffect = new QGraphicsOpacityEffect(ui->widget_2);
    opacityEffect->setOpacity(1);
    ui->widget_2->setGraphicsEffect(opacityEffect);
    propertyAnimation = new QPropertyAnimation(opacityEffect, "opacity", this);
    propertyAnimation->setEasingCurve(QEasingCurve::Linear);
    propertyAnimation->setDuration(250);
    launcher_timer = new QTimer;
    launcher_timer->start(4000);
    connect(launcher_timer, SIGNAL(timeout()), this, SLOT(start_fade_animation()));
}

void mainwindow::startWorkPageAnimation()
{
    opacityEffect = new QGraphicsOpacityEffect(ui->label_7);
    opacityEffect->setOpacity(0);
    ui->label_7->setGraphicsEffect(opacityEffect);
    propertyAnimation = new QPropertyAnimation(opacityEffect, "opacity",ui->widget_3);
    propertyAnimation->setEasingCurve(QEasingCurve::Linear);
    propertyAnimation->setDuration(500);
    propertyAnimation->setStartValue(0);
    propertyAnimation->setEndValue(1);
    propertyAnimation->start(QAbstractAnimation::KeepWhenStopped);
}
static bool othersPageAnimationShowed = false;
void mainwindow::startOthersPageAnimation()
{
    if(!othersPageAnimationShowed){
        othersPageAnimationShowed = true;
        opacityEffect = new QGraphicsOpacityEffect;
        opacityEffect->setOpacity(0);
        ui->label_22->setGraphicsEffect(opacityEffect);
        propertyAnimation = new QPropertyAnimation(opacityEffect, "opacity",ui->widget_5);
        propertyAnimation->setEasingCurve(QEasingCurve::Linear);
        propertyAnimation->setDuration(2000);
        propertyAnimation->setStartValue(0);
        propertyAnimation->setEndValue(1);
        propertyAnimation->start(QAbstractAnimation::KeepWhenStopped);
    }
}

void mainwindow::themeSetNStartAnimation(THEME_TYPE startType, THEME_TYPE endType)
{
    propertyAnimation = new QPropertyAnimation(ui->widget_7, "styleSheet");
    propertyAnimation->setDuration(1500);

    QFile styleLoader(STYLESHEETSPATH+themes[startType]);
    styleLoader.open(QFile::ReadOnly);
    targetStyleSheet = tr(styleLoader.readAll());
    styleLoader.close();
    propertyAnimation->setStartValue(getStyleSheet());

    QFile styleLoader2(STYLESHEETSPATH+themes[endType]);
    styleLoader2.open(QFile::ReadOnly);
    targetStyleSheet = tr(styleLoader2.readAll());
    styleLoader2.close();
    propertyAnimation->setEndValue(getStyleSheet());

    propertyAnimation->setEasingCurve(QEasingCurve::OutCubic);
    propertyAnimation->start(QAbstractAnimation::KeepWhenStopped);
}

void mainwindow::on_pushBtn_work_clicked(bool checked)
{
    ui->pushBtn_visualize->setChecked(false);
    ui->pushBtn_others->setChecked(false);
    ui->widget_4->hide();
    ui->widget_5->hide();
    ui->widget_3->show();
}


void mainwindow::on_pushBtn_visualize_clicked(bool checked)
{
    ui->pushBtn_work->setChecked(false);
    ui->pushBtn_others->setChecked(false);
    ui->widget_3->hide();
    ui->widget_5->hide();
    ui->widget_4->show();
}

void mainwindow::on_pushBtn_others_clicked(bool checked)
{
    ui->pushBtn_visualize->setChecked(false);
    ui->pushBtn_work->setChecked(false);
    ui->widget_3->hide();
    ui->widget_4->hide();
    ui->widget_5->show();
    startOthersPageAnimation();
}

void mainwindow::on_pushBtn_start_clicked()
{
    ui->pushBtn_visualize->setEnabled(true);
    ui->pushBtn_others->setEnabled(true);
    ui->widget_3->show();
    startWorkPageAnimation();
}

void mainwindow::on_pushButton_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton->setChecked(true);
    /*
    QFile styleLoader(STYLESHEETSPATH+"theme1.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme1 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme1);
    */
    themeSetNStartAnimation(currentThemeType, THEME_TYPE::THEME1);
    currentThemeType = THEME_TYPE::THEME1;
}

void mainwindow::on_pushButton_3_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_3->setChecked(true);
    /*
    QFile styleLoader(STYLESHEETSPATH+"theme3.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme3 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme3);
    */
    themeSetNStartAnimation(currentThemeType, THEME_TYPE::THEME3);
    currentThemeType = THEME_TYPE::THEME3;
}

void mainwindow::on_pushButton_4_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_4->setChecked(true);
    QFile styleLoader(STYLESHEETSPATH+"theme4.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme4 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme4);
}

void mainwindow::on_pushButton_5_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_5->setChecked(true);
    QFile styleLoader(STYLESHEETSPATH+"theme5.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme5 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme5);
}

void mainwindow::on_pushButton_2_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_2->setChecked(true);
    QFile styleLoader(STYLESHEETSPATH+"theme2.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme2 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme2);
}

void mainwindow::on_pushButton_6_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_6->setChecked(true);
    QFile styleLoader(STYLESHEETSPATH+"theme6.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme6 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme6);
}

void mainwindow::on_pushButton_7_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_7->setChecked(true);
    QFile styleLoader(STYLESHEETSPATH+"theme7.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme7 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme7);
}

void mainwindow::on_pushButton_8_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_8->setChecked(true);
    QFile styleLoader(STYLESHEETSPATH+"theme8.qss");
    styleLoader.open(QFile::ReadOnly);
    QString theme8 = tr(styleLoader.readAll());
    styleLoader.close();
    ui->widget_7->setStyleSheet(theme8);
}

QString mainwindow::getStyleSheet()
{
    return targetStyleSheet;
}

void mainwindow::setStyleSheet(QString styleSheet)
{
    ui->widget_7->setStyleSheet(styleSheet);
}
