#include "gradecalculator.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GradeCalculator w;
    w.show();

    return a.exec();
}
