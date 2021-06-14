#pragma once

#include <QBrush>
#include <QPen>

static QBrush brush_master_background(QColor(175, 215, 181));
static QPen   pen_master_background  (QColor(175, 215, 181));

static QBrush SBT_brush_table_background(QColor(47, 173, 102));
static QPen   SBT_pen_table_background  (QColor(47, 173, 102));


#include <QFont>
static const int SBFont_size = 11;
static const QFont SBFont_text("Qanelas", SBFont_size, QFont::Normal);
