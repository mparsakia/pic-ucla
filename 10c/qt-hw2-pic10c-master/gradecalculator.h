#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H

#include <QMainWindow>

namespace Ui {
class GradeCalculator;
}

class GradeCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit GradeCalculator(QWidget *parent = nullptr);
    ~GradeCalculator();


signals:


public slots:



private:
    Ui::GradeCalculator *ui;


private slots:

void compute_scores(int unused) const;


};

#endif // GRADECALCULATOR_H
