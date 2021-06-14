#pragma once

#include "SBTable.h"
#include <QWidget>

/* class SBFilter
 * object, that using in mediate filter
 * between GIW and SBXMLStreamReader
*/
class SBFilter
{
public:
    enum Action{
        undefined,
        more_than,
        less_than,
        in_range
    };

private:
    Action action;

public:
    SBFilter(QString& fn, SBFilter::Action act,
             QString& vall, QString valr = "");

    QString fieldName;

    QString value_l;
    QString value_r;


    bool filter(SBSubTable&);

private: //filters
    bool _more_than(SBSubTable& object);
    bool _less_than(SBSubTable& object);
    bool _in_range(SBSubTable& object);
};
