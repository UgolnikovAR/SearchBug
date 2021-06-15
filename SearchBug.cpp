#include "SearchBug.h"
#include "SBScreen\SBStartScreen.h"
#include "SBScreen\SBInputScreen.h"
#include "SBScreen\SBResultScreen.h"


SearchBug::SearchBug()
{
//init all screen widgets
//init master
    master = new QScrollArea(this);
    master->resize(START_WINDOW_SIZE);

    state.push_back(new SBStartScreen(master));
    state.push_back(new SBInputScreen(defaultPath, master, this));
    state.push_back(new SBResultScreen(master));


//create test panel (state buttons)

    testPanel = master;
    QPushButton* b1 = new QPushButton("StartScreen",  testPanel);
    QPushButton* b2 = new QPushButton("InputScreen",  testPanel);
    QPushButton* b3 = new QPushButton("ResultScreen", testPanel);

    QPoint b_pos(2, 2);
    QSize b_size(200, 40);

    b1->resize(b_size);
    b1->move(b_pos);
    b_pos.setY( b_pos.y() + b1->size().height() );
    b1->show();

    b2->resize(b_size);
    b2->move(b_pos);
    b_pos.setY( b_pos.y() + b2->size().height() );
    b2->show();

    b3->resize(b_size);
    b3->move(b_pos);
    b_pos.setY( b_pos.y() + b3->size().height() );
    b3->show();

    connect(b1, SIGNAL(clicked()), SLOT(slotStartScreen()));
    connect(b2, SIGNAL(clicked()), SLOT(slotInputScreen()));
    connect(b3, SIGNAL(clicked()), SLOT(slotResultScreen()));


    master->show();
    changeScreen(start_screen); // set "start screen" as first
    master->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->show();
}

SearchBug::~SearchBug()
{
    if(isXmlModuleInit) {
        delete table;
        delete pXML_Module;
    }
}

void SearchBug::setState(int i)
{
    if(i > MAX_STATES_ID) qDebug() << "Warning! Incorrect state " << i;
    _state_id= State_id(i);
}


/* SearchBug::initXmlModule
*/
void SearchBug::initXmlModule(QString& path, QString& tableName,
                              SBFilter& filter)
{
    table = new SBTable;
//if XML_Module was not inited
    if(pXML_Module == nullptr) {
        pXML_Module = new SBXMLStreamReader(path, tableName,
                                            filter,
                                            table);
    }
//else if this module has already been initialized
    else
    {
        delete pXML_Module;
        pXML_Module = new SBXMLStreamReader(path, tableName,
                                            filter,
                                            table);
    }

    isXmlModuleInit = true;

//set table in SBResultScreen
    SBResultScreen* pscr = dynamic_cast<SBResultScreen*> (state[State_id::result_screen]);
    pscr->setTable(table);
}


void SearchBug::resizeEvent(QResizeEvent* pe)
{
    master->resize(pe->size());

/*this states is static in master screen
 * "-2" means window border height. Up and botton.
 * Without this constant widget too large.*/
    state[State_id::start_screen]->resize(pe->size().width(), pe->size().height()-2);
    state[State_id::input_screen]->resize(pe->size().width(), pe->size().height()-2);
}


void SearchBug::changeScreen(State_id id)
{
//hide preview screen
    if(static bool isFirst = true; isFirst)
        isFirst = false;
    else
        state[_state_id] = dynamic_cast<SBGUIState*>(master->takeWidget());  //that casting is safe while this programm context

    _state_id = id;

//set current screen
    //state[_state_id]->show(); //olds
    master->setWidget(state[_state_id]);

//situative for result screen
    if(_state_id == State_id::result_screen)
        master->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}


QString SearchBug::windowQSS()
{
//init QSS from files
    //window style
        QFile SS_file("style/SS_SBWindow.qss");
        SS_file.open(QFile::ReadOnly);
        QString SS_SBLabel = QLatin1String(SS_file.readAll());
        SS_file.close();

    return SS_SBLabel;
}


void SearchBug::slotStartScreen()
{
    changeScreen(State_id::start_screen);
    qDebug() << "Current state formaly " << "S_SCR" << " showed";
    master->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
void SearchBug::slotInputScreen()
{
    changeScreen(State_id::input_screen);
    qDebug() << "Current state formaly " << "I_SCR" << " showed";
    master->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
void SearchBug::slotResultScreen()
{
    changeScreen(State_id::result_screen);
    qDebug() << "Current state formaly " << "R_SCR" << " showed";
    master->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}
