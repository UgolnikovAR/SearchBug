#pragma once
#include "SBScreen\SBGUIState.h"
#include "SBXMLStreamReader.h"
#include "SBScreen\SBPallete.h"
#include "SBFilter.h"
#include "SBWindow.h"
#include <QtWidgets>


//main class
class SearchBug : public QWidget
{
    Q_OBJECT

public:
    enum State_id
    {
        start_screen,
        input_screen,
        result_screen
    } id = start_screen;


private: //state variable and constants
    State_id _state_id;
    QWidget* testPanel; //developers DBG panel

    static const int MAX_STATES_ID = 2;
    constexpr static const QSize START_WINDOW_SIZE = QSize(1200, 800);
    QString defaultPath {"fT.xml"};


private: //data
    QVector<SBGUIState*> state;

    SBXMLStreamReader* pXML_Module = nullptr;
    SBTable* table;
    SBWindow* window;
    QScrollArea* master;


public:
    SearchBug();
    virtual ~SearchBug();
    void setState(int);
    void initXmlModule(QString& path, QString& tableName, SBFilter&);

    virtual void resizeEvent(QResizeEvent*);
    void changeScreen(State_id);

private:
    QString windowQSS();

public slots:
    void slotStartScreen();
    void slotInputScreen();
    void slotResultScreen();


private:// flags
    bool isXmlModuleInit = false;
};

