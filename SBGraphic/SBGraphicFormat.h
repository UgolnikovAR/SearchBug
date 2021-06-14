#pragma once
#include "SBScreen\SBPallete.h"
#include <QtWidgets>

/* ContentType is a group of tag identifiers,
 * which are realized in the programm.
 *
 * Here are could be included new identifiers.
 *
 * All identifiers is need to be writen in format.dat.
*/
enum ContentType
{
    random,
    name,
    bank_filial_id,
    personal_account,
    amount_of_money
};


class SBGraphicFormat: public QObject
{
    Q_OBJECT

private:
    static const QVector<QString> stringFormat;
    static const QImage background_tag_lastname;
    //static const QImage pictogramm;
    ContentType type;


public:
    SBGraphicFormat(){} // for testing. It needs to delete far.
    SBGraphicFormat(ContentType type);
    SBGraphicFormat(const QString& tag);
    SBGraphicFormat(const SBGraphicFormat&);
    SBGraphicFormat& operator=(const SBGraphicFormat&);
    virtual ~SBGraphicFormat(){}

/* definiteType
 * Method, that is defining format code for tag.*/
    ContentType definiteType(const QString& tag);

/* tag
 * Method, that is defining background image for tag by format code.*/
    const QImage& tagImg();

/* content
 * Method, that is defining background image for content by format code.*/
    const QImage& contentImg();

    QSize getSize();
    QPoint posText();
    QPoint posContentBackground();
    int height();


private://sub-procedures
    void loadPictogramm(ContentType t);
};

