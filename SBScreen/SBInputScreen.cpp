#include "SBInputScreen.h"
#include "SBFilter.h"

#include <QFile>

SBInputScreen::SBInputScreen(QString p, QWidget* m, SearchBug* parent)
    : SBGUIState(nullptr),
      parent(parent),
      master(m),
      defaultPath(p),
      cat(":/images/cat")
{
    this->resize(2000, 3000);
    groupInputWidget = new QWidget(this);
    groupInputWidget->resize(giw_width, giw_height);
    groupInputWidget->move(giw_offset());

    giw_init();
    groupInputWidget->show();
}


QString SBInputScreen::path()
{
    return {};
}
QString SBInputScreen::tag()
{
    return {};
}
QString SBInputScreen::fieldName()
{
    return {};
}
QString SBInputScreen::value()
{
    return {};
}


QPoint SBInputScreen::center_align()
{
    QRect r(master->rect());
    QPoint p;
    p.setX(r.width()/2);
    p.setY(r.height()/2);

    return p;
}


void SBInputScreen::paintEvent(QPaintEvent*)
{
    QPoint point(center_align()); //(x, y) - position for paint output image

    static QWidget* master = this;

    QPainter painter(master);
    painter.begin(master);
    painter.fillRect(master->rect(), brush_master_background);

    draw_contain(point, painter);

    painter.end();

//test
    //static int testi=0;
    //qDebug() << "Frame I_Scr: "<< ++testi << master->rect(); //olds DBG
}


void SBInputScreen::resizeEvent(QResizeEvent* re)
{
    static const QPoint giw_offset(- giw_width/2, - giw_height/2);
    groupInputWidget->move(center_align() + giw_offset);

    qDebug() << "resizeEvent with size -> " << re->size();
}


void SBInputScreen::draw_contain(QPoint& p, QPainter& painter)
{
    //static const QPoint cat_offset (- 541/2, - 605/2); olds
    //painter.drawImage(p + cat_offset, cat); olds
    p.setY(p.y() + cat.size().height());
}


void SBInputScreen::giw_init()
{
    static const QPoint shift(0, 50); //расстояние между линиями giw
    static const int secondColumnOffsetX = 400; //отступ колонки lineEdit'ов от правого края

//init QSS from files
    //label style
        QFile SS_fileL("style/SS_SBLabel.qss");
        SS_fileL.open(QFile::ReadOnly);
        QString SS_SBLabel = QLatin1String(SS_fileL.readAll());
        SS_fileL.close();

    //input line style
        QFile SS_fileIW("style/SS_SBInputWidget.qss");
        QString SS_SBInputLine;
        SS_fileIW.open(QFile::ReadOnly);
        SS_SBInputLine = QLatin1String(SS_fileIW.readAll());
        SS_fileIW.close();


//init giw lines
        QPoint giw_label_pos(0, 0);
        QPoint giw_lineEdit_pos(secondColumnOffsetX, 0);


    //1st line
        l_path = new QLabel("Path", groupInputWidget);
        l_path ->setStyleSheet(SS_SBLabel);
        l_path ->move(giw_label_pos);
        l_path ->show();

        le_path = new QLineEdit(defaultPath, groupInputWidget);
        le_path ->move(giw_lineEdit_pos);
        le_path ->setStyleSheet(SS_SBInputLine);
        le_path ->show();

        giw_label_pos    += shift;
        giw_lineEdit_pos += shift;


    //2nd line
        l_table_name = new QLabel("Table name", groupInputWidget);
        l_table_name ->setStyleSheet(SS_SBLabel);
        l_table_name ->move(giw_label_pos);
        l_table_name ->show();

        le_table_name = new QLineEdit(defaultTableName, groupInputWidget);
        le_table_name ->move(giw_lineEdit_pos);
        le_table_name ->setStyleSheet(SS_SBInputLine);
        le_table_name ->show();

        giw_label_pos    += shift;
        giw_lineEdit_pos += shift;


    //3rd line
        l_field_name = new QLabel("Field name", groupInputWidget);
        l_field_name ->setStyleSheet(SS_SBLabel);
        l_field_name  ->move(giw_label_pos);
        l_field_name ->show();

        le_element = new QLineEdit(defaultFieldName, groupInputWidget);
        le_element ->move(giw_lineEdit_pos);
        le_element ->setStyleSheet(SS_SBInputLine);
        le_element ->show();

        giw_label_pos    += shift;
        giw_lineEdit_pos += shift;

    //4th line
        l_value = new QLabel("Value", groupInputWidget);
        l_value ->setStyleSheet(SS_SBLabel);
        l_value ->move(giw_label_pos);
        l_value ->show();

        le_element_value = new QLineEdit(defaultValue, groupInputWidget);
        le_element_value ->move(giw_lineEdit_pos);
        le_element_value->setStyleSheet(SS_SBInputLine);
        le_element_value->show();



    //Getting style sheet from file
        QFile file1("style/SS_SBQPushButton.qss");
        file1.open(QFile::ReadOnly);
        QString SS_SBQPushButton = QLatin1String(file1.readAll());
        file1.close();

        QPoint giw_button_pos = giw_label_pos + shift;
        QPushButton* pcmdFind = new QPushButton("FIND", groupInputWidget);

        pcmdFind ->setStyleSheet(SS_SBQPushButton);
        pcmdFind ->move(giw_button_pos);
        pcmdFind ->show();

        QObject::connect(pcmdFind, SIGNAL(clicked()), this, SLOT(slotSetGiw()));

//Define giw size parameters
    int giw_padding = 60;

    giw_height = giw_button_pos.y()
                + pcmdFind->size().height()
                + giw_padding;

    giw_width  = giw_lineEdit_pos.x()
                + le_path->size().width()
                + giw_padding;
}


void SBInputScreen::initXmlModule()
{
    using Action = SBFilter::Action;
    Action action = Action::more_than;


    QString path        = le_path->text();
    QString tableName   = le_table_name->text();
    QString fieldName   = le_element->text();
    QString value       = le_element_value->text();

    SBFilter filter (fieldName, action, value);

    parent->initXmlModule(path,
                          tableName,
                          filter);
}


QPoint SBInputScreen::giw_offset()
{
//set left-up position in centre of master screen
    QPoint position = center_align();

    //static QRect giw_rect(position, QSize(giw_width, giw_height));

//centralize centre of giw in master screen centre
    static const QPoint giw_offset(- giw_width/2, - giw_height/2);
    position += giw_offset;

    return position;
}

void SBInputScreen::slotSetGiw()
{
    initXmlModule();
    qDebug() << "slotSetPath";
    parent->changeScreen(SearchBug::State_id::result_screen);
}
