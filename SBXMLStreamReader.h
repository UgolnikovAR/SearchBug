#pragma once
#include "SBTable.h"
#include "SBFilter.h"

#include <QtXml>
#include <QWidget>
#include <QScrollArea>

class SBXMLStreamReader : public QWidget
{
    Q_OBJECT
    QWidget* master;
    QString path;

public:
    SBXMLStreamReader(QString path,
                      QString& tableName,
                      SBFilter& filter,
                      SBTable* table);
    ~SBXMLStreamReader();
    SBTable& table() {return Ttable;}

private:
    SBTable& Ttable;

private: //filters
    bool filter(SBSubTable&, SBFilter&);


};
