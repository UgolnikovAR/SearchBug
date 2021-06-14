#include "SBGraphicElement.h"
#include "SBScreen/SBPallete.h"

SBGraphicElement::SBGraphicElement()
{
    //qDebug() << "->SBGraphicElement() here";
}


SBGraphicElement::SBGraphicElement(const SBGraphicElement& el)
    : //resultImg(el.resultImg),
      format(el.tag),
      tag(el.tag),
      content(el.content)
{}


SBGraphicElement::SBGraphicElement(QString& tag, QString& content)
    : format(content),
      tag(tag),
      content(content)
{
    //qDebug() << "->SBGraphicElement (full construct) here";
}


SBGraphicElement& SBGraphicElement::operator=(const SBGraphicElement& el)
{
    //resultImg = el.resultImg;  //old's delete then
    tag = el.tag;
    content = el.content;
    format = el.format;
    return *this;
}


void SBGraphicElement::draw(QPoint& offset, QWidget* context, QPainter& p)
{
//(Вычисление QPoint - позиция относительно базового элемента.)
    drawTag(offset, tag, format, context, p);
    drawContent(offset, content, format, context, p);
    drawPictogramm(offset, format, context, p);

  //смещение указателя offset
    offset.setY(offset.y() + format.getSize().height());
}


void SBGraphicElement::drawTag(QPoint offset,
                               QString tag,
                               SBGraphicFormat& format,
                               QWidget* context,
                               QPainter& p)
{

//Painting proccess    
  //размещение фона
    p.drawImage(offset, format.tagImg());


    p.setPen(QPen(QColorConstants::White));

    p.setFont(SBFont_text);
  //разместить текст тега
    p.drawText(offset + format.posText(), tag);
}


void SBGraphicElement::drawContent(QPoint offset,
                                   QString content,
                                   SBGraphicFormat& format,
                                   QWidget* context,
                                   QPainter& p)
{
//shift cursor offset
    offset = offset + format.posContentBackground();

//Painting proccess
  //размещение фона
    p.drawImage(offset, format.contentImg());

    p.setPen(QPen(QColorConstants::White));
    p.setFont(SBFont_text);
  //разместить текст тега
    p.drawText(offset + format.posText(), content);

}


void SBGraphicElement::drawPictogramm(QPoint offset,
                                      SBGraphicFormat& format,
                                      QWidget* context,
                                      QPainter& p)
{
    //Вычисление QPoint - позиция относительно базового элемента.
    //qDebug() << "Pict drawed\n";
    /*some operations to draw pictogramm*/
}
