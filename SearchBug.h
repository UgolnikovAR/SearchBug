#pragma once

#include "SBInputGroupWidget.h"
#include "SBResultScreen.h"

#include <QWidget>
#include <QPushButton>
#include <QPaintEvent>

class SearchBug : public QWidget
{
    Q_OBJECT
private:
    enum State{STARTING_SCREEN,
               INPUT_SCREEN,
               RESULT_SCREEN
              } state, previos; //keys of programm state

/*layers of programm states*/
//starting screen layer*/
    QWidget* pStartingScreenWgt;

//input screen layer
    QWidget* pInputScreenWgt;
    SBInputGroupWidget* pIWgt;

//result screen layer
    SBResultScreen* pResultScreenWgt;

//image resources
    QImage titleBar;
    QImage background;

    QImage startingLogo;
    QPoint startingLogoPos;

    QImage logo;
    QPoint logoPos;
    QImage backgroundOfInput;
    QPoint backgroungPos;

private:
    void inputScreenImagesReplace();

public:
    SearchBug(QWidget* pwgt = nullptr);
    virtual ~SearchBug() override {}

protected:
   virtual void paintEvent(QPaintEvent* pEv) override;
   virtual void resizeEvent(QResizeEvent* pEv) override;

private slots:
    void stateStartingScreen();
    void stateInputScreen();
    void stateResultScreen();
};
