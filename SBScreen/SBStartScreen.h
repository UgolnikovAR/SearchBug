#pragma once
#include "SBGUIState.h"
#include "SearchBug.h"

class SBStartScreen : public SBGUIState
{

    QWidget* master;

public:
    SBStartScreen(QWidget* master = nullptr);
    virtual ~SBStartScreen() {}

    void paintEvent(QPaintEvent*);

private:
    QPoint center_align();
    void draw_contain(QPoint&, QPainter&);
    QPoint logo_offset();

private: //images
        QImage logo;
};


