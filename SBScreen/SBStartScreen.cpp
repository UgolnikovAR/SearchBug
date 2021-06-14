#include "SBStartScreen.h"

SBStartScreen::SBStartScreen(QWidget* m)
    : SBGUIState(nullptr),
      master(m),
      logo(":/images/mainLogo")
{
    this->resize(2000, 3000);
}


QPoint SBStartScreen::center_align()
{
    QRect r(master->rect());
    QPoint p;
    p.setX(r.width()/2);
    p.setY(r.height()/2);

    return p;
}


void SBStartScreen::paintEvent(QPaintEvent*)
{
    QPoint point(center_align()); //(x, y) - position for paint output image

    static QWidget* master = this;

    QPainter painter(master);
    painter.begin(master);
    painter.fillRect(master->rect(), brush_master_background);

    draw_contain(point, painter);

    painter.end();

//test
    //static int testi=0;
    //qDebug() << "Frame I_Scr: "<< ++testi << master->rect(); //olds DBG
}


void SBStartScreen::draw_contain(QPoint& p, QPainter& painter)
{
    painter.drawImage(p+logo_offset(), logo);
}


QPoint SBStartScreen::logo_offset()
{
    return QPoint(-197, -173);
}
