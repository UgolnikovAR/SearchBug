#include "SearchBug.h"
#include "sbinputgroupwidget.h"

#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include <QPushButton>
#include <QPixmap>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

SearchBug::SearchBug(QWidget * pwgt)
    :QWidget(pwgt),
      state(STARTING_SCREEN), //"starting screen" as default state
      previos(state),         //previos state as default
      startingLogo(":/res/starting_logo.png"),         //starting logo
      logo(":/res/main_logo_sized.png"),               //logo picture
      backgroundOfInput(":/res/input_background_sized.png") // etc. picture
{   
//test buttons
    QWidget* testPanel = new QWidget;
    testPanel->setWindowTitle("Test panel");
    testPanel->move(100, 300);
    QBoxLayout* pbxLayoutTP = new QBoxLayout(QBoxLayout::TopToBottom, testPanel);

    QPushButton* pcmdTest = new QPushButton("Starting screen");
    pcmdTest->setAutoFillBackground(true);

    QPushButton* pcmdTest2 = new QPushButton("Input screen");
    pcmdTest2->setAutoFillBackground(true);

    QPushButton* pcmdTest3 = new QPushButton("Result screen");
    pcmdTest3->setAutoFillBackground(true);

    QPushButton* pcmdTest4 = new QPushButton("Exit");
    pcmdTest4->setAutoFillBackground(true);

    connect(pcmdTest, SIGNAL(clicked()), this, SLOT(stateStartingScreen()));
    connect(pcmdTest2, SIGNAL(clicked()), this, SLOT(stateInputScreen()));
    connect(pcmdTest3, SIGNAL(clicked()), this, SLOT(stateResultScreen()));
    connect(pcmdTest4, SIGNAL(clicked()), qApp, SLOT(quit()));

    pbxLayoutTP->addWidget(pcmdTest);
    pbxLayoutTP->addWidget(pcmdTest2);
    pbxLayoutTP->addWidget(pcmdTest3);
    pbxLayoutTP->addWidget(pcmdTest4);

    testPanel->setLayout(pbxLayoutTP);
    testPanel->show();

/*==========================SCREEN'S INITIATE===========================*/

//calculate positions for images
    inputScreenImagesReplace();

/*----------STARTING SCREEN------------*/
/* There is on screen showing:
 * 1) programm title bar
 * 2) background picture
 * 3) great logo
*/
    pStartingScreenWgt = new QWidget(this);          //"starting screen" layer
    QLabel* plblText1 = new QLabel("&Starting screen:", pStartingScreenWgt);
    pStartingScreenWgt->move(0, 0);
    plblText1->show();

/*----------INPUT SCREEN------------*/
/* There is on screen showing:
 * 1) programm title bar
 * 2) background picture
 * 3) tiny logo
 * 4) user input widget
 */
    pInputScreenWgt = new QWidget(this);             //"input screen" layer

//Input widgets
    pIWgt = new SBInputGroupWidget(pInputScreenWgt);
    pIWgt->setFont(QFont("QanelasRegular", 25, QFont::Normal)); //Qanelas regular font for IWgt


/*----------RESULT SCREEN------------*/
/* There is on screen showing:
 * 1) programm title bar
 * 2) background picture
 * 3) result widgets that shows results
*/
    pResultScreenWgt = new SBResultScreen(this);          //"result screen" layer
    QLabel* plbltext2 = new QLabel("&Result screen:", pResultScreenWgt);
    plbltext2->show();

    pInputScreenWgt->hide();
    pResultScreenWgt->hide();
    pStartingScreenWgt->show();
}



void SearchBug::paintEvent(QPaintEvent*)
{
//background
    QImage sceneImage(this->width(), this->height(), QImage::Format_ARGB32);
    sceneImage.fill(QColor(170, 213, 175));

//title bar
    QImage titleBar(this->width(), 28, QImage::Format_ARGB32);
    titleBar.fill(QColor(110, 195, 190));

    static QPainter painter(&sceneImage);

    painter.begin(&sceneImage);
    painter.drawImage(0, 0, titleBar);      //draw title bar
    painter.end();

    switch(state)
    {

    case STARTING_SCREEN:
        if(previos == INPUT_SCREEN)     pInputScreenWgt->hide();
        if(previos == RESULT_SCREEN)    pResultScreenWgt->hide();
        pStartingScreenWgt->resize(this->size());
        pStartingScreenWgt->show();
        previos = STARTING_SCREEN;

    //drawing
        painter.begin(&sceneImage);
        painter.drawImage(startingLogoPos, startingLogo); //draw logo on starting screen
        painter.end();

    //final render
        painter.begin(this);
        painter.drawImage(0, 0, sceneImage);
        painter.end();
        break;



    case INPUT_SCREEN:
        if(previos == STARTING_SCREEN)  pStartingScreenWgt->hide();
        if(previos == RESULT_SCREEN)    pResultScreenWgt->hide();

        pInputScreenWgt->resize(this->size());

    //drawing
        painter.begin(&sceneImage);
        painter.drawImage(logoPos, logo);                    //draw logo
        painter.drawImage(backgroungPos, backgroundOfInput); //draw background
        painter.end();

    //final render
        pInputScreenWgt->show();
        previos = INPUT_SCREEN;

        painter.begin(this);
        painter.drawImage(0, 0, sceneImage);
        painter.end();
        break;



    case RESULT_SCREEN:
    //final render
        if(previos == STARTING_SCREEN)  pStartingScreenWgt->hide();
        if(previos == INPUT_SCREEN)     pInputScreenWgt->hide();
        pResultScreenWgt->resize(this->size());
        pResultScreenWgt->show();
        previos = RESULT_SCREEN;

    //drawing
        painter.begin(&sceneImage);
        painter.drawImage(pResultScreenWgt->getLogoPos(),       //draw logo
                          pResultScreenWgt->getLogo());
        painter.drawImage(pResultScreenWgt->getResultImagePos(),
                          pResultScreenWgt->drawResultImage()); //draw result table
        painter.end();

        painter.begin(this);
        painter.drawImage(0, 0, sceneImage);
        painter.end();

        break;
    }
}


//-------------------------------Other Events
    void SearchBug::resizeEvent(QResizeEvent* pEv)
    {
        qDebug() << "pApp rect: " << this->rect();
        qDebug() << "pInput Screen: " << pInputScreenWgt->rect();
        qDebug() << "Input Wgt: " << pIWgt->rect();
    //resize main widget (SearchBug widget)
        resize(pEv->size());

    //calculate new positions for images
        inputScreenImagesReplace();
    //replace Input Widget(pIWgt)
        pIWgt->move(this->backgroungPos + pIWgt->getOffset());
    }

//-------------------------------SLOTS

void SearchBug::stateStartingScreen()
{
    state = STARTING_SCREEN;
    this->repaint();
}

void SearchBug::stateInputScreen()
{
    state = INPUT_SCREEN;
    this->repaint();
}

void SearchBug::stateResultScreen()
{
    state = RESULT_SCREEN;
    this->repaint();
}

void SearchBug::inputScreenImagesReplace()
{
    static bool notFirst = false;
    switch(state)
    {
    case STARTING_SCREEN:
    //starting logo
        static QPoint startingLogoPos;
        static int startingLogoWmid = startingLogo.width()/2;
        startingLogoPos.setX(this->width()/2 - startingLogoWmid);       //x - position
        startingLogoPos.setY(int(this->height()/8) + titleBar.height());//y - position
        this->startingLogoPos = startingLogoPos;
        if(notFirst) break;

    case INPUT_SCREEN:
    //logo picture
        static QPoint logoPos;
        static int logoWmid = logo.width()/2;
        logoPos.setX(this->width()/2 - logoWmid);                 //x - position
        logoPos.setY(int(this->height()/8) + titleBar.height());  //y - position
        this->logoPos = logoPos;

    //input backgroung picture
        static QPoint bgIPos (logoPos);
        static int backgroundOfInputWmid = backgroundOfInput.width()/2;
        bgIPos.setX(logoPos.x() - backgroundOfInputWmid + logoWmid);
        bgIPos.setY(logoPos.y() + logo.height());
        this->backgroungPos = bgIPos;
        if(notFirst) break;

    case RESULT_SCREEN:
        this->pResultScreenWgt->imagesReplace();
        break;
    }
}
