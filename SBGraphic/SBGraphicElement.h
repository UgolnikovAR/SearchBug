#pragma once

#include "SBGraphicFormat.h"

#include <QImage>

/* SBGraphicElement
 * class, that draw a line:
 * (pictogram, tag, content) on resultImg.
*/
class SBGraphicElement : public QObject
{
    Q_OBJECT

private:
    SBGraphicFormat format;

    QString tag;
    QString content;

public:
    SBGraphicElement();
    SBGraphicElement(const SBGraphicElement&);
    SBGraphicElement(QString& tag, QString& content);
    SBGraphicElement& operator=(const SBGraphicElement&);
    virtual ~SBGraphicElement() {}

    void draw(QPoint& offset, QPainter& p);
    void initImages();
    void formatElement();

    void setTag(QString t)      {tag = t;}
    void setContent(QString c)  {content = c;}
    QString getTag()            {return tag;}
    QString getContent()        {return content;}
    int height()                {return format.height();}

private://sub-methods
    void drawTag       (QPoint, QString tag,      SBGraphicFormat&, QPainter& p);
    void drawContent   (QPoint, QString content,  SBGraphicFormat&, QPainter& p);
    void drawPictogramm(QPoint, SBGraphicFormat&, QPainter& p);
};
