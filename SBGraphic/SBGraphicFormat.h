#pragma once
#include "SBScreen\SBPallete.h"
#include <QtWidgets>

/* ContentType is a group of tag identifiers,
 * which are realized in the programm.
 *
 * Here are could be included new identifiers.
*/
enum ContentType
{
    random,
    name,
    bank_filial_id,
    personal_account,
    amount_of_money
};

/* StaticImages_id is a group of tag identifiers,
 * which are created by the programm.
 *
 * Here are could be included new identifiers.
 *
 * name style is (snake low case ContentType)_(camel upper case image class)
*/
enum StaticImages_id
{
    random_Tag,
    random_Content,
    random_Pictogramm,

    name_StandartTag,
    name_StandartContent,

    bank_filial_id_Tag,
    bank_filial_id_Content,
    bank_filial_id_Pictogramm,

    personal_account_Tag,
    personal_account_Content,
    personal_account_Pictogramm,

    amount_of_money_Tag,
    amount_of_money_Content,
    amount_of_money_Pictogramm,

//max value, that using in cicles
    maximum
};


class SBGraphicFormat: public QObject
{
    Q_OBJECT

private:
    static QVector<QImage> img;
    static const QString space;
    static const QVector<QString> stringFormat;

private:
    ContentType type;

    QImage _tagImg;
    QImage _contentImg;

public:
    SBGraphicFormat(){} // for testing. It needs to delete far.
    SBGraphicFormat(ContentType type);
    SBGraphicFormat(const QString& tag);
    SBGraphicFormat(const SBGraphicFormat&);
    SBGraphicFormat& operator=(const SBGraphicFormat&);
    virtual ~SBGraphicFormat(){}

    void initImages(QString&, QString&);
    static QImage drawStaticImage(SBGraphicImageFormat&);

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

    void formatString(QString&);


private://sub-procedures
    void loadPictogramm(ContentType t);
    void init_imgTag(QString&);
    void init_imgContent(QString&);

private://flags
    bool formatted = false;

};

