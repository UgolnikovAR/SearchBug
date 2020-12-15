#include "sbinputgroupwidget.h"

#include <QFile>
#include <QPushButton>
#include <QtWidgets>
#include <QPushButton>

SBInputGroupWidget::SBInputGroupWidget(QWidget *parent)
    : QWidget(parent),
      offset(100, 65)
{
    QLineEdit* pSBIWgtPath = new QLineEdit(this);
    QLineEdit* pSBIWgtFieldName = new QLineEdit(this);
    QLineEdit* pSBIWgtValue = new QLineEdit(this);

    /*Getting style sheet from file*/
    QFile file("SS_SBInputLine.qss");
    file.open(QFile::ReadOnly);
    QString SS_SBInputLine = QLatin1String(file.readAll());
    file.close();

    /*Set style sheets*/
    pSBIWgtPath->setStyleSheet(SS_SBInputLine);
    pSBIWgtFieldName->setStyleSheet(SS_SBInputLine);
    pSBIWgtValue->setStyleSheet(SS_SBInputLine);

    /*Getting style sheet from file*/
    QPushButton* pcmdFind = new QPushButton("FIND");
    QFile file1("SS_SBQPushButton.qss");
    file1.open(QFile::ReadOnly);
    QString SS_SBQPushButton = QLatin1String(file1.readAll());
    file1.close();

    /*Set style sheets*/
    pcmdFind->setStyleSheet(SS_SBQPushButton);


//Labels
    QLabel* plblPath = new QLabel("Path", this);
    QLabel* plblFieldName = new QLabel("Field name", this);
    QLabel* plblValue = new QLabel("Value", this);

    /*Getting style sheet from file*/
    QFile file2("SS_SBLabel.qss");
    if(!file2.open(QFile::ReadOnly))
        qDebug() << "SS_SBLabel.qss was not open FAILURE!!!" << Qt::endl;
    else qDebug() << "SS_SBLabel.qss is ok!" << Qt::endl;
    QString SS_SBLabel = QLatin1String(file2.readAll());
    file2.close();

    /*Set style sheets*/
    plblPath->setStyleSheet(SS_SBLabel);
    plblFieldName->setStyleSheet(SS_SBLabel);
    plblValue->setStyleSheet(SS_SBLabel);

//Layouts for Input Widget
    int MaxHeightOfTextLabel = 30;
    QVBoxLayout* pvbxLayout1 = new QVBoxLayout;
    plblPath->setMaximumHeight(MaxHeightOfTextLabel);
    pvbxLayout1->addWidget(plblPath, Qt::AlignRight);
    pvbxLayout1->addSpacing(7);
    plblFieldName->setMaximumHeight(MaxHeightOfTextLabel);
    pvbxLayout1->addWidget(plblFieldName, Qt::AlignRight);
    plblValue->setMaximumHeight(MaxHeightOfTextLabel);
    pvbxLayout1->addWidget(plblValue, Qt::AlignRight);
    pvbxLayout1->setDirection(QBoxLayout::TopToBottom);
    pvbxLayout1->setContentsMargins(0, 0, 0, 0);


    QVBoxLayout* pvbxLayout2 = new QVBoxLayout;
    pvbxLayout2->addSpacing(10);
    pSBIWgtPath->setMinimumWidth(350);
    pvbxLayout2->addWidget(pSBIWgtPath, Qt::AlignRight);
    pSBIWgtFieldName->setMaximumWidth(180);
    pvbxLayout2->addSpacing(7);
    pSBIWgtFieldName->setMinimumHeight(40);
    pvbxLayout2->addWidget(pSBIWgtFieldName, Qt::AlignRight);
    pSBIWgtValue->setMaximumWidth(180);
    pSBIWgtValue->setMinimumHeight(40);
    pvbxLayout2->addWidget(pSBIWgtValue, Qt::AlignRight);
    pvbxLayout2->setContentsMargins(5, 0, 0, 5);

    pvbxLayout1->setGeometry(pvbxLayout2->geometry());


    QHBoxLayout* phbxLayout1 = new QHBoxLayout;
    phbxLayout1->addLayout(pvbxLayout1);
    phbxLayout1->addLayout(pvbxLayout2);


    QVBoxLayout* pvbxLayout3 = new QVBoxLayout;
    pvbxLayout3->addLayout(phbxLayout1);
    pvbxLayout3->setSpacing(10);
    QHBoxLayout* phbxLayout2 = new QHBoxLayout;
    phbxLayout2->setSpacing(350);
    pcmdFind->setMaximumWidth(150);                          //button width
    pcmdFind->setMinimumHeight(40);
    phbxLayout2->addWidget(pcmdFind);
    phbxLayout2->setDirection(QBoxLayout::RightToLeft);
    pvbxLayout3->addLayout(phbxLayout2);


    this->setLayout(pvbxLayout3);

    this->setStyleSheet(SS_SBLabel);

    this->resize(pvbxLayout3->minimumSize());
    this->show();
}


QPoint SBInputGroupWidget::getOffset() const
{
    return this->offset;
}

