#include "SBOutputGroupWidget.h"

#include <QPainter>

SBOutputGroupWidget::SBOutputGroupWidget(QWidget *parent, QPoint offset)
    : QWidget(parent),
      offset(offset)
{

}

/* drawOutputWgt(QPainter* p)
 * *p - is a pointer to painter object that draw on "result image" in this moment
 *
 * int height - is a dynamic parametr,
 * that is the summ of containtment objects heights
*/
QImage SBOutputGroupWidget::drawOutputWgt(QPainter* p)
{
    QImage resultImage;
//first table of result
    /*int height = obj[cur].height;*/                  //IN DEVELOPING
    drawBackground(p/*, height*/);

//other tables of result
    //for() vector, содержащий объекты информации, полученной из 123.xml

    return resultImage;
}


void SBOutputGroupWidget::drawBackground(QPainter* p, int height/* = RoundedRectangle_height*/)
{
    p->drawRoundedRect(QRect(offset.x(), offset.y(),//position
                           RoundedRectangle_width,  //width
                           height                   //height
                           ),
                     RoundedRectangle_radius,       //radius x
                     RoundedRectangle_radius        //radius y
                     );
}
