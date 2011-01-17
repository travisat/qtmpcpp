/***************************************************************************
 *   Copyright (C) 2010 by Travis Thompson                                 *
 *   travisat@gmail.com			                                           *
 ***************************************************************************/

#include <QApplication>
#include "qtmpcpp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qtmpcpp window;
    window.showNormal();

    return a.exec();

}
