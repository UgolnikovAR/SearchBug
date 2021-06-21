#pragma once
#include "SBXMLStreamReader.h"
#include "SBGUIState.h"
#include "SearchBug.h"
#include <QWidget>
#include <QScrollArea>


class SBResultScreen : public SBGUIState
{

private:
    QScrollArea* master = nullptr;
    SBTable* Ttable;


public:
    SBResultScreen(QScrollArea* master);
    virtual ~SBResultScreen(){}

    void paintEvent(QPaintEvent*);
    void setTable(SBTable* t) {Ttable = t;};
    void imageReset() {Ttable->setDrawed(false);}

private:
    QPoint center_align();
    void draw_contain(QPoint&, QPainter&);
    void draw_logo(QPoint&, QPainter&);

private: //images
    QImage smallLogo;
};
