#pragma once

#include <QPushButton>

#include <QDebug>

#include <QLabel>

#include <QMovie>

#include <QFontDatabase>

#include <QDesktopServices>

#include <QUrl>

#include <QTimer>

#include <QMouseEvent>

#include <QGraphicsOpacityEffect>

#include <QPropertyAnimation>

#include <QPainter>

#include <QFile>

#include <QColor>

#include <QList>

#include <QVariant>

#include <QPoint>

#include <ctime>

static const QPoint menuStartPoint(1, 700);
static const QPoint menuEndPoint(1, 111);
static const QList<QColor> THEME_COLORS({QColor(255,165,0), QColor(30,144,255), QColor(0,250,0), QColor(130,130,130),
                                  QColor(36,41,46), QColor(255,62,150), QColor(255,215,0), QColor(148,0,211)});
static const QList<QColor> BORDER_COLORS({QColor(30,144,255), QColor(0, 0, 0)});
static const QString STYLESHEETSPATH(":/styleSheets/share/styleSheets/");
static const QString FONTSPATH(":/fonts/share/fonts/");
static const QString IMAGESPATH(":/images/share/images/");
enum THEME_COLOR_TYPE{T_COLOR1, T_COLOR2, T_COLOR3, T_COLOR4,
                 T_COLOR5, T_COLOR6, T_COLOR7, T_COLOR8};
enum BORDER_COLOR_TYPE{B_COLOR1, B_COLOR2};
enum FADE_TYPE{IN, OUT};




