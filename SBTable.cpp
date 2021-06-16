#include "SBTable.h"
#include "SBScreen/SBPallete.h"


SBSubTable::SBSubTable(const SBSubTable& t)
{
    for(auto& x: t.table)
        table.push_back(x);
    //qDebug() << "ref constructor\n";
}


void SBSubTable::operator=(const SBSubTable& t)
{
    for(auto& x: t.table)
        table.push_back(x);
    //qDebug() << "operator=\n";
}


void SBSubTable::draw(QPoint& offset, QWidget* context, QPainter& p)
{
    //Вычисление QPoint - позиция относительно базового элемента.

    static int height = 0; //предварительная высота таблицы


    if (static bool first = true; first){
        height = calculateHeight(shift);
        first = false;
    }


//Отрисовка прямоугольника со скругленными углами

    static const int rect_width = 450;
    QRect rectangle(offset.x(), offset.y(), rect_width, height + subtable_margin);

    p.setPen(pen_master_background);
    p.setBrush(brush_master_background);

    static const int radius = 7;
    p.drawRoundedRect(rectangle, radius, radius);

    QPoint subPos(offset);
    subPos.setX(subPos.x() + subtable_margin);
    subPos.setY(subPos.y() + subtable_margin);

    for(auto& x: table)
    {
        x.draw(subPos, context, p);
        offset.setY(subPos.y());
        subPos.setY(subPos.y()+shift);
    }

    setHeight(height);

    if(table.empty())
    qDebug() << "Table Empty\n";
}

void SBSubTable::initImages()
{
    for(auto& x: table) x.initImages();
}


int SBSubTable::calculateHeight(int shift)
{
    int height = 0;
    for(auto& x: table)
    {
        height += x.height() + subtable_margin;
    }

    return height;
}


void SBSubTable::formatTable()
{
    for(auto& x: table) x.formatElement();
}



void SBTable::draw(QPoint& offset, QWidget* context, QPainter& p)
{
    //if(drawed) return; //newest
    static int height = 0;

    if (!drawed){
        height = calculateHeight(shift);
        if(height > context->size().height()) {
            context->resize(context->size().width(), height);
        }

        //drawed = false; olds
    }

    static const int rect_width = 540;
    static const int padding    = 12;
    QRect rectangle(offset.x(), offset.y(), rect_width, height + padding);

    p.setPen(SBT_pen_table_background);
    p.setBrush(SBT_brush_table_background);

    static const int radius = 12;
    p.drawRoundedRect(rectangle, radius, radius);

    QPoint subPos(offset);
    subPos.setX(subPos.x()+table_margin);
    subPos.setY(subPos.y()+table_margin);

    for(auto& x :table)
    {
        x.draw(subPos, context, p);
        offset.setY(subPos.y());
        subPos.setY(subPos.y()+shift); //расстояние между таблицами
    }

    setDrawed(true);
}


void SBTable::initImages()
{
    for(auto& x: table) x.initImages();
}


int SBTable::calculateHeight(int shift)
{
    int height = 0;
    for(auto& x: table)
    {
        height += x.calculateHeight(x.shift) + table_margin;
    }
    height += shift; //bottom margin

    return height;
}


void SBTable::formatTable()
{
    for(auto& x: table) x.formatTable();
}
