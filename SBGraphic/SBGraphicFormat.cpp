#include "SBGraphicFormat.h"

const QVector<QString> SBGraphicFormat::stringFormat
{
    "Фамилия",
    "Имя",
    "Отчество",
    "ОтделениеБанка",
    "ЛицевойСчет",
    "Сумма"
};

//Initialization images
const QImage SBGraphicFormat::background_tag_lastname(":/images/background_tag_lastname");

SBGraphicFormat::SBGraphicFormat(ContentType type)
    : type(type)
{
    loadPictogramm(type);
}


SBGraphicFormat::SBGraphicFormat(const QString& tag)
{
    //qDebug() << "->SBGraphicFormat here";
    type = definiteType(tag);
    loadPictogramm(type);
}


SBGraphicFormat::SBGraphicFormat(const SBGraphicFormat& f)
    : type(f.type)
{}


SBGraphicFormat& SBGraphicFormat::operator=(const SBGraphicFormat& f)
{
    type = f.type;
    return *this;
}


/* definiteType
 * Method, that is defining format code for tag.
 * Using content string for define equal ContentType.
 * Then return it.*/
ContentType SBGraphicFormat::definiteType(const QString& t)
{
    if(t == "Фамилия")  {
        //qDebug() << "->DBG type is lastname -> " << t;
        return name;
    }
    if(t == "Имя")      {
        //qDebug() << "->DBG type is firstname -> " << t;
        return name;
    }
    if(t == "Отчество") {
        //qDebug() << "->DBG type is fathername -> " << t;
        return name;
    }
    if(t == "ОтделениеБанка") {
        //qDebug() << "->DBG type is fathername -> " << t;
        return bank_filial_id;
    }
    if(t == "ЛицевойСчет") {
        //qDebug() << "->DBG type is fathername -> " << t;
        return personal_account;
    }
    if(t == "Сумма") {
        //qDebug() << "->DBG type is fathername -> " << t;
        return amount_of_money;
    }

//Then type is undefined
    qDebug() << "->DBG type is undefined -> " << t;
    return random;
}


const QImage& SBGraphicFormat::tagImg()
{
    if(type == name)             return background_tag_lastname;
    if(type == bank_filial_id)   return background_tag_lastname;
    if(type == personal_account) return background_tag_lastname;
    if(type == amount_of_money)  return background_tag_lastname;

//else return empty image
    static const QImage img;
    return img;
}


const QImage& SBGraphicFormat::contentImg()
{
    if(type == name)             return background_tag_lastname;
    if(type == bank_filial_id)   return background_tag_lastname;
    if(type == personal_account) return background_tag_lastname;
    if(type == amount_of_money)  return background_tag_lastname;

//else return empty image
    static const QImage img;
    return img;
}


/* getSize
 * that method is defining, what the size graphicElements has.
 *
*/
QSize SBGraphicFormat::getSize()
{
    if(type == name)             return QSize(89, 20);
    if(type == bank_filial_id)   return QSize(89, 20);
    if(type == personal_account) return QSize(89, 20);
    if(type == amount_of_money)  return QSize(89, 20);

//Then nothing was catched
    qDebug() << "WARNING! Undefined size of graphicElement";
    return QSize();
}


/*SBGraphicFormat::posTagText
 * returns offset tag text from tag background image (left-down angle)
*/
QPoint SBGraphicFormat::posText()
{
    //if(type == name) return QPoint(10, 5);

    return QPoint(5, SBFont_size+4);
}


QPoint SBGraphicFormat::posContentBackground()
{
    if(type == name)             return QPoint(175, 0);
    if(type == bank_filial_id)   return QPoint(175, 0);
    if(type == personal_account) return QPoint(175, 0);
    if(type == amount_of_money)  return QPoint(175, 0);

    return QPoint(0, 0);
}


int SBGraphicFormat::height()
{
    if(type == name)             return 20;
    if(type == bank_filial_id)   return 20;
    if(type == personal_account) return 20;
    if(type == amount_of_money)  return 20;

    return 0;
}


void SBGraphicFormat::loadPictogramm(ContentType t)
{
   /*
   switch(type)
   types..: load_image("res\type.png");
   */
}
