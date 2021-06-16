#pragma once
#include "SBGUIState.h"
#include "SearchBug.h"



/* SBInputScreen
 * .. ..
 * giw - is a "group input widget"
*/



class SBInputScreen : public SBGUIState
{
    Q_OBJECT
private:
    SearchBug* parent;
    QWidget* master;
    QWidget* groupInputWidget;

    int giw_width = 680;
    int giw_height = 220;

    QString defaultPath;
    QString defaultTableName {"Сотрудник"};
    QString defaultFieldName {"Сумма"};
    QString defaultValue     {"100"};

private: //Qt GUI widgets
    QLineEdit* le_path;
    QLineEdit* le_table_name; //Заменить на выпадающий список
    QLineEdit* le_element;
    QLineEdit* le_element_value;

    QLabel* l_path;
    QLabel* l_table_name;
    QLabel* l_field_name;
    QLabel* l_value;

    QPushButton* pcmdFind;

    QPoint giw_offset(); //unused, olds

public:
    SBInputScreen(QString defaultPath,
                  QWidget* master = nullptr,
                  SearchBug* parent = nullptr);
    virtual ~SBInputScreen() {}

    QString path();
    QString tag();
    QString fieldName();
    QString value();

protected:
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);

private: //sub-procedures
    QPoint center_align();
    void draw_contain(QPoint&, QPainter&);
    void giw_init();
    QSize giw_size();

    void initXmlModule();

private: //images
    QImage smallLogo;
    QImage giw_background;

public slots:
    void slotSetGiw();
};
