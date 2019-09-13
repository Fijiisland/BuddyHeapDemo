#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow),
    popUpMenuIsAvaliable(false),
    currentThemeColorType(THEME_COLOR_TYPE::T_COLOR1)
{
    ui->setupUi(this);
    bHeap = new BuddyHeap;
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
    if (event->button() == Qt::LeftButton && event->y() <= 40){
        m_move = true;
        m_startPoint = event->globalPos();
        m_windowPoint = this->frameGeometry().topLeft();
    }
}

void mainwindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_move && event->buttons() & Qt::LeftButton){
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

void mainwindow::setMainMemoryCapacity(int v)
{
    ui->label_memCapacity->setText(QString::number(ui->horizontalSlider->value()) + QStringLiteral("KB"));
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
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setMainMemoryCapacity(int)));

    ui->horizontalSlider->setValue(BuddyHeap::DEFAULT_MEMORY_CAPACITY);
    styleSheetLoader = new QFile;
    ui->pushBtn_visualize->setEnabled(false);
    ui->pushBtn_others->setEnabled(false);
    ui->pushButton->setChecked(true);
    QFrame *parent_frame = ui->frame_3;
    ui->widget_3->setParent(parent_frame);
    ui->widget_4->setParent(parent_frame);
    ui->widget_5->setParent(parent_frame);
    ui->pushBtn_zoom->setEnabled(false);
    ui->pushBtn_setmem->setEnabled(false);
    ui->pushBtn_addjob->setEnabled(false);
    ui->pushBtn_reset->setEnabled(false);
    // Styles
    ui->frame->setStyleSheet(QStringLiteral("#frame{border:1.4px solid #24292E}#background-color:#FFFFFF"));
    int fontID1 = QFontDatabase::addApplicationFont(FONTSPATH+QStringLiteral("SF-Pro-Display-Ultralight.otf"));
    int fontID2 = QFontDatabase::addApplicationFont(FONTSPATH+QStringLiteral("SF-Pro-Display-Regular.otf"));
    QString SP_Ultralight = QFontDatabase::applicationFontFamilies(fontID1).at(0);
    QString SP_Regular = QFontDatabase::applicationFontFamilies(fontID2).at(0);
    ui->label_launcher->setFont(QFont(SP_Ultralight, 22));
    ui->label_headline->setFont(QFont(QStringLiteral("Segoe UI"), 9));
    ui->label_headline->setStyleSheet(QStringLiteral("color:#FFFFFF;"));

    setMyStyleSheet(QStringLiteral("mainSetmem.qss"));
    ui->pushBtn_setmem->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("mainAddJob.qss"));
    ui->pushBtn_addjob->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("mainClose.qss"));
    ui->pushBtn_close->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("mainMini.qss"));
    ui->pushBtn_mini->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("mainWork.qss"));
    ui->pushBtn_work->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("mainVisualize.qss"));
    ui->pushBtn_visualize->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("mainOthers.qss"));
    ui->pushBtn_others->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("mainReset.qss"));
    ui->pushBtn_reset->setStyleSheet(myStyleSheet);

    ui->label_welcome->setFont(QFont(QStringLiteral("微软雅黑 Light"), 30));
    ui->label_welcome->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_12->setFont(QFont(QStringLiteral("微软雅黑 Light"), 30));
    ui->label_12->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_13->setFont(QFont(QStringLiteral("微软雅黑 Light"), 15));
    ui->label_13->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_14->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_14->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_15->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_15->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_16->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_16->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_17->setFont(QFont(QStringLiteral("微软雅黑 Light"), 15));
    ui->label_17->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_18->setFont(QFont(QStringLiteral("微软雅黑 Light"), 15));
    ui->label_18->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_19->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_19->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_20->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_20->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_21->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_21->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_22->setFont(QFont(SP_Ultralight, 32));
    ui->label_22->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_23->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_23->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_7->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_7->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_memCapacity->setFont(QFont(QStringLiteral("微软雅黑"), 9));
    ui->label_memCapacity->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_3->setFont(QFont(QStringLiteral("微软雅黑 Light"), 30));
    ui->label_3->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_4->setFont(QFont(QStringLiteral("微软雅黑"), 9));
    ui->label_4->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_hint->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    ui->label_hint->setStyleSheet(QStringLiteral("Color:#708090;"));

//  Work page ruler's serial number
    ui->label_5->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_5->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_6->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_6->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_8->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_8->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_24->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_24->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_25->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_25->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_26->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_26->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_27->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_27->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_28->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_28->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_29->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_29->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_30->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_30->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_31->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_31->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_32->setFont(QFont(QStringLiteral("Courier Prime"), 10));
    ui->label_32->setStyleSheet(QStringLiteral("Color:#708090;"));
//  Work page ruler's serial number

    ui->label_33->setFont(QFont(QStringLiteral("微软雅黑 Light"), 25));
    ui->label_33->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_34->setFont(QFont(QStringLiteral("Courier Prime"), 8));
    ui->label_34->setStyleSheet(QStringLiteral("Color:#708090;"));
    ui->label_35->setFont(QFont(QStringLiteral("Courier Prime"), 8));
    ui->label_35->setStyleSheet(QStringLiteral("Color:#708090;"));

    setMyStyleSheet(QStringLiteral("VisualBtn1.qss"));
    ui->pushButton->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("VisualBtn2.qss"));
    ui->pushButton_2->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("VisualBtn3.qss"));
    ui->pushButton_3->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("VisualBtn4.qss"));
    ui->pushButton_4->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("VisualBtn5.qss"));
    ui->pushButton_5->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("VisualBtn6.qss"));
    ui->pushButton_6->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("VisualBtn7.qss"));
    ui->pushButton_7->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("VisualBtn8.qss"));
    ui->pushButton_8->setStyleSheet(myStyleSheet);
    setMyStyleSheet(QStringLiteral("WelcomeBtnStart.qss"));
    ui->pushBtn_start->setStyleSheet(myStyleSheet);
    ui->pushBtn_start->setFont(QFont(QStringLiteral("微软雅黑"), 10));
    setMyStyleSheet(QStringLiteral("theme1.qss"));
    ui->widget_7->setStyleSheet(myStyleSheet);
}

void mainwindow::setStartUpAnimation()
{
    loading_mov = new QMovie(IMAGESPATH+QStringLiteral("loading.gif"));
    loading_mov->setSpeed(150);
    ui->label_loading->setMovie(loading_mov);
    loading_mov->start();

    launcher_timer = new QTimer;
    launcher_timer->start(3500);
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
    setWorkPageBtnAbledOrNot(true);
    ui->pushBtn_visualize->setChecked(false);
    ui->pushBtn_others->setChecked(false);
    ui->widget_4->hide();
    ui->widget_5->hide();
    ui->widget_3->show();
}


void mainwindow::on_pushBtn_visualize_clicked(bool checked)
{
    setWorkPageBtnAbledOrNot(false);
    ui->pushBtn_work->setChecked(false);
    ui->pushBtn_others->setChecked(false);
    ui->widget_3->hide();
    ui->widget_5->hide();
    ui->widget_4->show();
}

void mainwindow::on_pushBtn_others_clicked(bool checked)
{
    setWorkPageBtnAbledOrNot(false);
    ui->pushBtn_visualize->setChecked(false);
    ui->pushBtn_work->setChecked(false);
    ui->widget_3->hide();
    ui->widget_4->hide();
    ui->widget_5->show();
    startOthersPageAnimation();
}

void mainwindow::on_pushBtn_start_clicked()
{
    ui->pushBtn_addjob->setEnabled(true);
    ui->pushBtn_setmem->setEnabled(true);
    ui->pushBtn_reset->setEnabled(true);
    ui->pushBtn_visualize->setEnabled(true);
    ui->pushBtn_others->setEnabled(true);
    ui->widget_3->show();
    startWorkPageAnimation();
}

void mainwindow::on_pushButton_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme1.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR1);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR1;
}

void mainwindow::on_pushButton_3_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_3->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme3.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR3);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR3;
}

void mainwindow::on_pushButton_4_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_4->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme4.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR4);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR4;
}

void mainwindow::on_pushButton_5_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_5->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme5.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR5);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR5;
}

void mainwindow::on_pushButton_2_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_2->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme2.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR2);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR2;
}

void mainwindow::on_pushButton_6_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_6->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme6.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR6);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR6;
}

void mainwindow::on_pushButton_7_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_7->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme7.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR7);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR7;
}

void mainwindow::on_pushButton_8_clicked(bool checked)
{
    setAllVisiualizeBtnsUnchecked();
    ui->pushButton_8->setChecked(true);
    setWidget7StyleSheet(QStringLiteral("theme8.qss"));
    //themeSetNStartAnimation(currentThemeColorType, COLOR_TYPE::COLOR8);
    currentThemeColorType = THEME_COLOR_TYPE::T_COLOR8;
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

void mainwindow::on_pushBtn_setmem_clicked()
{
    ui->label_33->setText("主存");
    ui->horizontalSlider->show();
    ui->label_34->show();
    ui->label_35->show();
    if(!popUpMenuIsAvaliable)
        popUpMenu();
}

void mainwindow::setWorkPageBtnAbledOrNot(bool e)
{
    ui->pushBtn_setmem->setEnabled(e);
    ui->pushBtn_addjob->setEnabled(e);
    ui->pushBtn_reset->setEnabled(e);
}

void mainwindow::on_pushButton_9_clicked()
{
    popUpMenu();
}

void mainwindow::popUpMenu()
{
    if(!popUpMenuIsAvaliable){
        setPropertyAnimation("pos", ui->widget_21->pos(),
                              menuEndPoint, 500,
                             QEasingCurve::InOutCubic, ui->widget_21, nullptr, nullptr);
        popUpMenuIsAvaliable = true;
    }else{
        setPropertyAnimation("pos", ui->widget_21->pos(),
                              menuStartPoint, 500,
                             QEasingCurve::InOutCubic, ui->widget_21, nullptr, nullptr);
        popUpMenuIsAvaliable = false;
    }
}

void mainwindow::on_pushBtn_addjob_clicked()
{
    ui->label_33->setText("添加");
    ui->horizontalSlider->hide();
    ui->label_34->hide();
    ui->label_35->hide();
    if(!popUpMenuIsAvaliable)
        popUpMenu();
}

void mainwindow::on_pushBtn_reset_clicked()
{
    ui->label_memCapacity->setText(QString::number(BuddyHeap::DEFAULT_MEMORY_CAPACITY));
    ui->horizontalSlider->setValue(BuddyHeap::DEFAULT_MEMORY_CAPACITY);
}
