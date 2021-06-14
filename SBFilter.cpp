#include "SBFilter.h"



SBFilter::SBFilter(QString& fn, SBFilter::Action act,
         QString& vall, QString valr)
    : action(act), fieldName(fn),
      value_l(vall), value_r(valr)
{}


/* Filter methods group
 * That functions returns true if they find required values in SubTables.
 * Else they returns false.
 *
 * SBFilter::filter - its a hub-shell for another filter-methods.
*/
bool SBFilter::filter(SBSubTable& st)
{
    switch(action)
    {
    case more_than: return _more_than(st); break;
    case less_than: return _less_than(st); break;
    case in_range : return _in_range(st) ; break;

    case undefined: qDebug() << "Filter returns undefined";
        return true;

    default: qDebug() << "Filter returns default";
        return true;
    }

}


bool SBFilter::_more_than(SBSubTable& obj)
{
//find for the required values
    for(auto x: obj)
    {
        if(x.getTag() == fieldName)
            if(x.getContent().toDouble() > value_l.toDouble())
                return true;
    }

//if nothing
    return false;
}


bool SBFilter::_less_than(SBSubTable& obj)
{
    /*difine later. In next live*/
}


bool SBFilter::_in_range(SBSubTable& obj)
{
    /*difine later. In next live*/
}
