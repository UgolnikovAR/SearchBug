#include "SBResultScreen.h"

#include <QPainter>

SBResultScreen::SBResultScreen(QWidget* parent)
    :QScrollArea(parent),
      parent(parent)
{}

SBResultScreen::SBResultScreen(const QImage& img)
    :logo(img)
{}

void SBResultScreen::imagesReplace()
{
//logoPos
    logoPos.setX(parent->width()/2 - logo.width()/2);

    static int heightOfTitleBar = 28;   //height of title bar
    static int offsetY = 20;            //offset for Y-axis
    logoPos.setY(heightOfTitleBar + offsetY);

//resultImagePos
    QPoint ResImgPosOffset(logoPos.x() - pOWgt->width()/2,  //x - position
                           logoPos.y() + logo.height());    //y - position
    resultImagePos += ResImgPosOffset;
}

QImage SBResultScreen::drawResultImage()
{
    static QPainter painter(&resultImage);
    painter.begin(&resultImage);
    painter.drawImage(logoPos, pOWgt->drawOutputWgt(&painter));
    painter.end();

    return resultImage;
}
