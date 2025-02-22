#include "simplewindow.h"

#include <QApplication>

// Рассмотреть:
// - Приведение типов
// - Приведение типов между объектами родственных классов
// - Приведения в С++


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleWindow w;
    w.show();
    return a.exec();
}
