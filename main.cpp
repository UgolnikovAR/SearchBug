/*SearchBug programm
 * That programm will write out a list of objects from xls.
 *
 * This feautures are included:
 *  1-st screen:
 *      1 - resizeble background-picture;
 *      2 - logo-picture that dynamicly pointed from other objects;
 *      3 - editable text-line that will get path of xls-file;       (":/sbrf/f8611083.xml")
 *      4 - fields names of data structures;                         ("—ÛÏÏ‡")
 *  2-nd screen:
 *      1 - editable text-line that will get path for out text-file; ("inform.txt")
 *      2 - fields with finded data-structures.
*/

#include <QApplication>
#include <QtWidgets>

#include "SearchBug.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SearchBug SBug;

    SBug.setWindowTitle("SearchBug | A. Ugolnikov, A. Pavlov");
    SBug.resize(800, 600);

    SBug.show();


    return app.exec();
}
