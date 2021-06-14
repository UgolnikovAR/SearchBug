#include "SBXMLStreamReader.h"
#include "SBTable.h"
#include "SearchBug.h"
#include "SBScreen\SBResultScreen.h"

#include <QApplication>
#include <QtWidgets>
#include <QLabel>
#include <QScrollArea>
#include <QPainter>
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    SearchBug sb_app;
    sb_app.move(400, 100);

    return a.exec();
}
