#pragma once

#include <QWidget>

class SBInputGroupWidget : public QWidget
{
    Q_OBJECT
private:
    QPoint offset;

public:
    SBInputGroupWidget(QWidget *parent = nullptr);
    virtual ~SBInputGroupWidget() override {}

    QPoint getOffset() const;
};

