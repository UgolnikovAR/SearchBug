#pragma once
#include "SBOutputGroupWidget.h"

#include <QScrollArea>
#include <QPainter>

class SBResultScreen : public QScrollArea
{
    Q_OBJECT
private:
    QWidget* parent;

    QImage logo;
    QPoint logoPos;
    QImage resultImage;
    QPoint resultImagePos;

    SBOutputGroupWidget* pOWgt;

public:
    SBResultScreen(QWidget* parent);
    SBResultScreen(const QImage& logo);
    virtual ~SBResultScreen() override;

    QPoint getLogoPos() const {return logoPos;}
    QImage getLogo() const {return logo;}

    QImage drawResultImage();
    QPoint getResultImagePos() const {return resultImagePos;}

private:
    void imagesReplace();
};
