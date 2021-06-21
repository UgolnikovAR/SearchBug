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


void SBSubTable::draw(QPoint& offset, QPainter& p)
{
    //Вычисление QPoint - позиция относительно базового элемента.

    static int height = 0; //предварительная высота таблицы

    if (static bool first = true; first)
    {
        height = calculateHeight();
        setHeight(height);
        first = false;
    }

//Отрисовка фона: прямоугольника со скругленными углами

    static const int rect_width = 450;
    QRect rectangle(offset.x(), offset.y(), rect_width, height + subtable_margin);

    p.setPen(pen_master_background);
    p.setBrush(brush_master_background);

    static const int radius = 7;
    p.drawRoundedRect(rectangle, radius, radius);


    QPoint subPos(offset);

    /*//test begin
    static int id = 0;
    p.setPen(QColorConstants::White);
    p.setBrush(QColorConstants::Red);
    p.drawRect(QRect(subPos, QSize(15,15)));
    p.drawText(subPos, QString(QString::number(id++)));
    qDebug() << id << " subtable was drawed";
    */// end test

    subPos.setX(subPos.x() + subtable_margin);
    subPos.setY(subPos.y() + subtable_margin);

    for(auto& x: table)
    {
        x.draw(subPos, p);
        offset.setY(subPos.y());
        subPos.setY(subPos.y()+shift);
    }



    if(table.empty())
    qDebug() << "Table Empty\n";
}

void SBSubTable::initImages()
{
    for(auto& x: table) x.initImages();
}


int SBSubTable::calculateHeight()
{
    int height = 0;
    height += subtable_margin; //margin top
    for(auto& x: table)
    {
        height += x.height();
        height += shift;
    }
    height -= shift;
    height += subtable_margin; //margin bottom
    return height;
}


void SBSubTable::formatTable()
{
    for(auto& x: table) x.formatElement();
}



void SBTable::draw(QPoint& offset, QWidget* context, QPainter& p)
{
    static int height = 0;
    static const int rect_width = 540;
    static const int padding    = 12;

    static QImage* subImage;

//Расчет высоты таблицы и создание изображения-буфера по полученным параметрам
    if (!drawed)
    {
        height = calculateHeight();
        if(height > context->size().height()) {
            context->resize(context->size().width(), height);
        }
        subImage = new QImage(rect_width, height, QImage::Format_ARGB32);
    }

    static QPainter subPainter;
    subPainter.begin(subImage);

//Отрисовка таблицы
    if (!drawed)
    {
        QRect rectangle(0, 0, rect_width, height + padding);

        subPainter.setPen(SBT_pen_table_background);
        subPainter.setBrush(SBT_brush_table_background);

    //фон таблицы
        static const int radius = 12;
        subPainter.drawRoundedRect(rectangle, radius, radius);

        //смещение для таблиц-элементов
        QPoint subPos(0, 0);
        subPos.setX(subPos.x()+table_margin);
        subPos.setY(subPos.y()+table_margin);

    //Отрисовка таблиц-элементов
        for(auto& x :table)
        {
            x.draw(subPos, subPainter);
            subPos.setY(subPos.y()+shift); //расстояние между таблицами
        }
        setDrawed(true);
    }
    subPainter.end();

//Перенос, полученного выше, изображения на экран(master)
    p.drawImage(offset, *subImage);
    qDebug() << "ImageSize ->" << subImage->size();
}


void SBTable::initImages()
{
    for(auto& x: table) x.initImages();
}


int SBTable::calculateHeight()
{
    int height = 0;
    height += table_margin; //top margin
    for(auto& x: table)
    {
        height += x.calculateHeight();
        height += shift;
    }
    height -= shift;
    height += table_margin; //bottom margin

    return height;
}


void SBTable::formatTable()
{
    for(auto& x: table) x.formatTable();
}
