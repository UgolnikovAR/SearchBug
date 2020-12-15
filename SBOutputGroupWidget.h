#pragma once

#include <QWidget>

class SBOutputGroupWidget : public QWidget
{
    Q_OBJECT
private:
    QPoint offset;

//properties
    static const int RoundedRectangle_width = 650;
    static const int RoundedRectangle_height = 280;
    static const int RoundedRectangle_radius = 12;

public:
    SBOutputGroupWidget(QWidget *parent = nullptr, QPoint offset = {0, 100});
    virtual ~SBOutputGroupWidget() override;

    QPoint getOffset() const;
    QImage drawOutputWgt(QPainter* p);
    void drawBackground(QPainter* p, int height = RoundedRectangle_height);
};
