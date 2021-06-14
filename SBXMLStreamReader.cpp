#include "SBXMLStreamReader.h"
#include "SBGraphic/SBGraphicElement.h"
#include "SBTable.h"
#include <QLabel>
#include <QPainter>
#include <QtWidgets>

SBXMLStreamReader::SBXMLStreamReader(QString path,
                                     QString& tableName,
                                     SBFilter& filter,
                                     SBTable* table)
    : path(path), Ttable(*table)
{
    QFile file(path);

    if(file.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader sr(&file);
        do
        {
            SBSubTable subTable;
            sr.readNext();
            QString test = sr.name().toString();
        //Read whole structure named (tableName)
            if(sr.name().toString() == tableName)
            {
                sr.readNext(); //read tag

                while(sr.readNext(), sr.name().toString() != tableName)
                {
                    QString name("~"), text("~");
                    static SBGraphicElement current;

                    name = sr.name().toString();
                    text = sr.readElementText();

                    qDebug() << "Line-> " << name << text; //old DBG
                    current.setTag(name);
                    current.setContent(text);
                    subTable.add(current);

                    sr.readNext(); //skip spaces
                }

            //filter cheks the subTable for filter matching
                if(filter.filter(subTable))
                    table->add(subTable);
                //else continue
            }
        } while(!sr.atEnd());
    }
    else qDebug() << "File was not opened\n";
    file.close();

    this->resize(2000, 3000);
}


SBXMLStreamReader::~SBXMLStreamReader(){}
