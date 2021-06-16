#pragma once

#include "SBGraphic/SBGraphicElement.h"
#include <QWidget>

/* class SBSubTable
 * that class need be to create objects containers
 * that contain any SBGraphicElements.
 *
 * For simple, it is a set of lines.
*/
class SBSubTable
{
    using SubTable = QVector<SBGraphicElement>;

    SubTable table;
    int height_ = 0;
public:
    static const int shift = 10; //расстояние между строками

    SBSubTable(){};
    SBSubTable(const SBSubTable&);
    virtual ~SBSubTable(){}

    void operator=(const SBSubTable&);
    void add(SBGraphicElement el) {table.push_back(el);}

    void draw(QPoint& offset, QWidget* context, QPainter& p);
    void initImages();

    int  height()           {return height_;}
    void setHeight(int a)   {height_ = a;}
    int  calculateHeight(int shift);
    void formatTable();

    SubTable::iterator begin() {return SubTable::iterator (table.begin());}
    SubTable::iterator end()   {return SubTable::iterator (table.end());  }

private:
    static const int subtable_margin = 12;
};


/* class SBTable
 * that class need be to create objects containers
 * that contain any SBSubTables.
 *
 * For simple, it is a set of tables,
 * that contain result data from search operation.
*/
class SBTable
{
    QVector<SBSubTable> table;
public:
    static const int shift = 45;
    void add(SBSubTable t) {table.push_back(t);}

    void draw(QPoint& offset, QWidget* context, QPainter& p);
    void initImages();
    int calculateHeight(int shift);
    virtual ~SBTable(){}

    void setDrawed(bool s) {drawed = s;}
    void formatTable();

private:
    bool drawed = false;
    static const int table_margin = 45;
};
