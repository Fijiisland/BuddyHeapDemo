#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow),
    currentThemeColorType(COLOR_TYPE::COLOR1)
{
    ui->setupUi(this);
    styleSheetLoader = new QFile;
    setModulesStyleNFunctions();
    setStartUpAnimation();
    hideModules();
}

mainwindow::~mainwindow()
{
    delete ui;
}

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

void mainwindow::startFadeAnimation()
{
    launcher_timer->stop();
    setFadeInOrOutAnimation(ui->widget_2, this, 250, FADE_TYPE::OUT);
    show_timer = new QTimer;
    show_timer->start(1000);
    connect(show_timer, SIGNAL(timeout()), this, SLOT(showModules()));
}

void mainwindow::showModules()
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

void mainwindow::hideModules()
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

void mainwindow::setModulesStyleNFunctions()
{
    // Functions
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pushBtn_visualize->setEnabled(false);
    ui->pushBtn_others->setEnabled(false);
    ui->pushButton->setChecked(true);
    QFrame *parent_frame = ui->frame_3;
    ui->widget_3->setParent(parent_frame);
    ui->widget_4->setParent(parent_frame);
    ui->widget_5->setParent(parent_frame);
    ui->pushBtn_zoom->setEnabled(false);
    // Styles
    ui->frame->setStyleSheet("#frame{border:1.4px solid #BEBEBE}#background-color:#FFFFFF");
    int fontID1 = QFontDatabase::addApplicationFont(FONTSPATH+"SF-Pro-Display-Ultralight.otf");
    int fontID2 = QFontDatabase::addApplicationFont(FONTSPATH+"SF-Pro-Display-Regular.otf");
    QString SP_Ultralight = QFontDatabase::applicationFontFamilies(fontID1).at(0);
    QString SP_Regular = QFontDatabase::applicationFontFamilies(fontID2).at(0);
    ui->label_launcher->setFont(QFont(SP_Ultralight, 22));
    ui->label_headline->setFont(QFont("Segoe UI", 9));
    ui->label_headline->setStyleSheet("color:#FFFFFF;");

    setMyStyleSheet("mainSetmem.qss");
    ui->pushBtn_setmem->setStyleSheet(myStyleSheet);
    setMyStyleSheet("mainAddJob.qss");
    ui->pushBtn_addjob->setStyleSheet(myStyleSheet);
    setMyStyleSheet("mainClose.qss");
    ui->pushBtn_close->setStyleSheet(myStyleSheet);
    setMyStyleSheet("mainMini.qss");
    ui->pushBtn_mini->setStyleSheet(myStyleSheet);
    setMyStyleSheet("mainWork.qss");
    ui->pushBtn_work->setStyleSheet(myStyleSheet);
    setMyStyleSheet("mainVisualize.qss");
    ui->pushBtn_visualize->setStyleSheet(myStyleSheet);
    setMyStyleSheet("mainOthers.qss");
    ui->pushBtn_others->setStyleSheet(myStyleSheet);

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
    ui->label_memCapacity->setFont(QFont("微软雅黑", 9));
    ui->label_memCapacity->setStyleSheet("Color:#708090;");
    ui->label_3->setFont(QFont("微软雅黑 Light", 30));
    ui->label_3->setStyleSheet("Color:#708090;");
    ui->label_4->setFont(QFont("微软雅黑", 9));
    ui->label_4->setStyleSheet("Color:#708090;");
    ui->label_hint->setFont(QFont("微软雅黑", 10));
    ui->label_hint->setStyleSheet("Color:#708090;");

//  Work page ruler's serial number
    ui->label_5->setFont(QFont("Courier Prime", 10));
    ui->label_5->setStyleSheet("Color:#708090;");
    ui->label_6->setFont(QFont("Courier Prime", 10));
    ui->label_6->setStyleSheet("Color:#708090;");
    ui->label_8->setFont(QFont("Courier Prime", 10));
    ui->label_8->setStyleSheet("Color:#708090;");
    ui->label_24->setFont(QFont("Courier Prime", 10));
    ui->label_24->setStyleSheet("Color:#708090;");
    ui->label_25->setFont(QFont("Courier Prime", 10));
    ui->label_25->setStyleSheet("Color:#708090;");
    ui->label_26->setFont(QFont("Courier Prime", 10));
    ui->label_26->setStyleSheet("Color:#708090;");
    ui->label_27->setFont(QFont("Courier Prime", 10));
    ui->label_27->setStyleSheet("Color:#708090;");
    ui->label_28->setFont(QFont("Courier Prime", 10));
    ui->label_28->setStyleSheet("Color:#708090;");
    ui->label_29->setFont(QFont("Courier Prime", 10));
    ui->label_29->setStyleSheet("Color:#708090;");
    ui->label_30->setFont(QFont("Courier Prime", 10));
    ui->label_30->setStyleSheet("Color:#708090;");
    ui->label_31->setFont(QFont("Courier Prime", 10));
    ui->label_31->setStyleSheet("Color:#708090;");
    ui->label_32->setFont(QFont("Courier Prime", 10));
    ui->label_32->setStyleSheet("Color:#708090;");
//  Work page ruler's serial number

    setMyStyleSheet("VisualBtn1.qss");
    ui->pushButton->setStyleSheet(myStyleSheet);
    setMyStyleSheet("VisualBtn2.qss");
    ui->pushButton_2->setStyleSheet(myStyleSheet);
    setMyStyleSheet("VisualBtn3.qss");
    ui->pushButton_3->setStyleSheet(myStyleSheet);
    setMyStyleSheet("VisualBtn4.qss");
    ui->pushButton_4->setStyleSheet(myStyleSheet);
    setMyStyleSheet("VisualBtn5.qss");
    ui->pushButton_5->setStyleSheet(myStyleSheet);
    setMyStyleSheet("VisualBtn6.qss");
    ui->pushButton_6->setStyleSheet(myStyleSheet);
    setMyStyleSheet("VisualBtn7.qss");
    ui->pushButton_7->setStyleSheet(myStyleSheet);
    setMyStyleSheet("VisualBtn8.qss");
    ui->pushButton_8->setStyleSheet(myStyleSheet);
    setMyStyleSheet("WelcomeBtnStart.qss");
    ui->pushBtn_start->setStyleSheet(myStyleSheet);
    ui->pushBtn_start->setFont(QFont("微软雅黑", 10));
    setMyStyleSheet("theme1.qss");
    ui->widget_7->setStyleSheet(myStyleSheet);
}

void mainwindow::setStartUpAnimation()
{
    loading_mov = new QMovie(IMAGESPATH+"loading.gif");
    loading_mov->setSpeed(150);
    ui->label_loading->setMovie(loading_mov);
    loading_mov->start();

    launcher_timer = new QTimer;
    launcher_timer->start(4000);
    connect(launcher_timer, SIGNAL(timeout()), this, SLOT(startFadeAnimation()));
}

void mainwindow::startWorkPageAnimation()
{
    setFadeInOrOutAnimation(ui->label_7, ui->widget_3, 500, FADE_TYPE::IN);
    setFadeInOrOutAnimation(ui->label_memCapacity, ui->widget_3, 500, FADE_TYPE::IN);
    setPropertyAnimation("size", ui->widget_8->size(),
                         QSize(900, ui->widget_8->size().height()), 1000,
                         QEasingCurve::InOutCirc, ui->widget_8, nullptr, nullptr);
}

static
bool othersPageAnimationShowed = false;
void mainwindow::startOthersPageAnimation()
{
    if(!othersPageAnimationShowed){
        othersPageAnimationShowed = true;
        setFadeInOrOutAnimation(ui->label_22, ui->widget_5, 2000, FADE_TYPE::IN);
    }
}
/*
void mainwindow::themeSetNStartAnimation(COLOR_TYPE startColor, COLOR_TYPE endColor)
{
    setPropertyAnimation("color", COLORS[startColor],COLORS[endColor],
                         1500, QEasingCurve::OutCubic, ui->widget_7,
                         nullptr, nullptr);
}
*/
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
    setWidget7StyleSheet("theme1.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR1);
    currentThemeColorType = COLOR_TYPE::COLOR1;
}

void mainwindow::on_pushButton_3_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_3->setChecked(true);
    setWidget7StyleSheet("theme3.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR3);
    currentThemeColorType = COLOR_TYPE::COLOR3;
}

void mainwindow::on_pushButton_4_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_4->setChecked(true);
    setWidget7StyleSheet("theme4.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR4);
    currentThemeColorType = COLOR_TYPE::COLOR4;
}

void mainwindow::on_pushButton_5_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_5->setChecked(true);
    setWidget7StyleSheet("theme5.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR5);
    currentThemeColorType = COLOR_TYPE::COLOR5;
}

void mainwindow::on_pushButton_2_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_2->setChecked(true);
    setWidget7StyleSheet("theme2.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR2);
    currentThemeColorType = COLOR_TYPE::COLOR2;
}

void mainwindow::on_pushButton_6_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_6->setChecked(true);
    setWidget7StyleSheet("theme6.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR6);
    currentThemeColorType = COLOR_TYPE::COLOR6;
}

void mainwindow::on_pushButton_7_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_7->setChecked(true);
    setWidget7StyleSheet("theme7.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR7);
    currentThemeColorType = COLOR_TYPE::COLOR7;
}

void mainwindow::on_pushButton_8_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_8->setChecked(true);
    setWidget7StyleSheet("theme8.qss");
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR8);
    currentThemeColorType = COLOR_TYPE::COLOR8;
}

void mainwindow::setPropertyAnimation(QByteArray _property, QVariant startValue, QVariant endValue, int duration,
                                      QEasingCurve curve, QWidget *target = nullptr, QGraphicsEffect* effect = nullptr, QWidget* _parent = nullptr)
{
    if(!effect)
        propertyAnimation = new QPropertyAnimation(target, _property);
    else
        propertyAnimation = new QPropertyAnimation(effect, _property, _parent);
    propertyAnimation->setDuration(duration);
    propertyAnimation->setEasingCurve(curve);
    propertyAnimation->setStartValue(startValue);
    propertyAnimation->setEndValue(endValue);
    propertyAnimation->start(QAbstractAnimation::KeepWhenStopped);
}

void mainwindow::setFadeInOrOutAnimation(QWidget *target, QWidget *parent, int duration, FADE_TYPE type)
{
    int startValue = 0, endValue = 1;
    if(type == FADE_TYPE::OUT)
        qSwap(startValue, endValue);
    opacityEffect = new QGraphicsOpacityEffect(target);
    opacityEffect->setOpacity(startValue);
    target->setGraphicsEffect(opacityEffect);
    setPropertyAnimation("opacity", startValue, endValue, duration, QEasingCurve::Linear, nullptr, opacityEffect, parent);
}

void mainwindow::setWidget7StyleSheet(QString name)
{
    setMyStyleSheet(name);
    ui->widget_7->setStyleSheet(myStyleSheet);
}

void mainwindow::setMyStyleSheet(QString name)
{
    styleSheetLoader->setFileName(STYLESHEETSPATH+name);
    styleSheetLoader->open(QFile::ReadOnly);
    myStyleSheet = tr(styleSheetLoader->readAll());
    styleSheetLoader->close();
}
