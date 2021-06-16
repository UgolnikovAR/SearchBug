#pragma once

#include <QBrush>
#include <QPen>

static QBrush brush_master_background(QColor(175, 215, 181));
static QPen   pen_master_background  (QColor(175, 215, 181));

static QBrush SBT_brush_table_background(QColor(47, 173, 102));
static QPen   SBT_pen_table_background  (QColor(47, 173, 102));


class SBGraphicImageFormat
{
    QBrush _brush;
    QPen   _pen;
    QSize  _imgSize;
    QRect  _rect;
    bool isPictogramm = true;

public:
    static const int Radius = 4;
    static const int imagesHeight = 22;
    static const int rectsHeight = imagesHeight -3;

private:
    static const int _radius = Radius;
public:
    SBGraphicImageFormat(){};
    SBGraphicImageFormat(QBrush br, QPen p, QSize s, QRect r)
        :_brush(br),
         _pen(p),
         _imgSize(s),
         _rect(r)
    { isPictogramm = false; }

    int     radius() {return _radius;}
    QBrush& brush()  {return _brush;}
    QPen&   pen()    {return _pen;}
    QSize&  size()   {return _imgSize;}
    QRect&  rect()   {return _rect;}
    bool    skip()   {return isPictogramm;}
};

#define ZERO 0,0

//GraphicElements
static SBGraphicImageFormat format_random_Tag
(
    QBrush(SBT_brush_table_background),
    QPen  (QColorConstants::White),
    QSize (120, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 120, SBGraphicImageFormat::rectsHeight)
);
/*
SBGraphicImageFormat format_random_Content
{
    QBrush(brush_master_background),
    QPen  (QColorConstants::White),
    QSize (120, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 120, SBGraphicImageFormat::rectsHeight)
};

SBGraphicImageFormat format_random_Pictogramm;



SBGraphicImageFormat format_name_StandartTag
{
    QBrush(brush_master_background),
    QPen  (QColorConstants::White),
    QSize (85, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 85, SBGraphicImageFormat::rectsHeight)
};

SBGraphicImageFormat format_name_StandartContent
{
    QBrush(brush_master_background),
    QPen  (QColorConstants::White),
    QSize (110, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 110, SBGraphicImageFormat::rectsHeight)
};



SBGraphicImageFormat format_bank_filial_id_Tag
{
    QBrush(brush_master_background),
    QPen  (QColorConstants::White),
    QSize (130, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 130, SBGraphicImageFormat::rectsHeight)
};

SBGraphicImageFormat format_bank_filial_id_Content
{
    QBrush(brush_master_background),
    QPen  (QColorConstants::White),
    QSize (40, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 40, SBGraphicImageFormat::rectsHeight)
};

SBGraphicImageFormat format_bank_filial_id_Pictogramm;



SBGraphicImageFormat format_personal_account_Tag
{
    QBrush(brush_master_background),
    QPen  (QColorConstants::White),
    QSize (100, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 100, SBGraphicImageFormat::rectsHeight)
};

SBGraphicImageFormat format_personal_account_Content
{
    QBrush(brush_master_background),
    QPen  (QColorConstants::White),
    QSize (100, SBGraphicImageFormat::imagesHeight),
    QRect (ZERO, 100, SBGraphicImageFormat::rectsHeight)
};
*/


#include <QFont>
static const int SBFont_size = 11;
static const QFont SBFont_text("Qanelas", SBFont_size, QFont::Normal);
