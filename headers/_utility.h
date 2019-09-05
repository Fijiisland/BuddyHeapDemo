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

static const QList<QColor> COLORS({QColor(255,165,0), QColor(30,144,255), QColor(0,250,0), QColor(130,130,130),
                                  QColor(36,41,46), QColor(255,62,150), QColor(255,215,0), QColor(148,0,211)});
static const QString STYLESHEETSPATH(":/styleSheets/share/styleSheets/");
static const QString FONTSPATH(":/fonts/share/fonts/");
static const QString IMAGESPATH(":/images/share/images/");
enum COLOR_TYPE{COLOR1, COLOR2, COLOR3, COLOR4,
                 COLOR5, COLOR6, COLOR7, COLOR8};
enum FADE_TYPE{IN, OUT};




