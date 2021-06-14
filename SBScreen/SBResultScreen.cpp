#include "SBResultScreen.h"
#include "SBTable.h"
#include <QPainter>

SBResultScreen::SBResultScreen(QScrollArea* sb_app)
    : SBGUIState(nullptr),
      master(sb_app),
      smallLogo(":/images/smallLogo")
{
    this->resize(2000, 3000);


    master->resize(1200, 800);
    master->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    master->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //sa.setMinimumWidth(1000); //then set it later
    //sa.setMinimumHeight(800);



}


QPoint SBResultScreen::center_align()
{
    QRect r(master->rect());
    QPoint p;
    p.setX(r.width()/2 - 540/2);
    p.setY(r.height()/8);

    return p;
}


void SBResultScreen::paintEvent(QPaintEvent*)
{
    QPoint point(center_align()); //(x, y) - position for paint output image


    static QWidget* master = this; //master - widget that is general screen

    QPainter painter(master);
    painter.begin(master);

    //if(static int first = true; first){
        painter.fillRect(master->rect(), brush_master_background);

        draw_contain(point, painter); //containment, that is images
        Ttable->draw(point, master, painter);
        //first = false;
    //}

    painter.end();

//test
    //static int testi=0;
    //qDebug() << "Frame R_Scr: "<< ++testi << master->rect(); //olds DBG
}


void SBResultScreen::draw_contain(QPoint& p, QPainter& painter)
{
    draw_logo(p, painter);
}


void SBResultScreen::draw_logo(QPoint& p, QPainter& painter)
{
//centralize picture in master screen
    QPoint pos(p);
    const int half_master_width = master->size().width()/2;
    static const int half_logo_width = smallLogo.size().width()/2;
    pos.setX(half_master_width - half_logo_width);

    painter.drawImage(pos, smallLogo);
    p.setY(p.y() + smallLogo.size().height());
}
