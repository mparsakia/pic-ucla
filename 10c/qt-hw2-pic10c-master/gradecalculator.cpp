#include "gradecalculator.h"
#include "ui_gradecalculator.h"

GradeCalculator::GradeCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeCalculator)
{
    ui->setupUi(this);

    // This block makes it so when any slider/spinbox is changed, the calculations update
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_3,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_4,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_5,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_6,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_7,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_8,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_9,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_10,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));
    QObject::connect(ui->spinBox_11,SIGNAL(valueChanged(int)),this,SLOT(compute_scores(int)));

    // This line makes it so that you do not need to update the slider/spinbox when changing between courses
    QObject::connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(compute_scores(int)));

}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}


void GradeCalculator::compute_scores(int unused) const{

if(ui->comboBox->currentIndex() == 0){   // Should be first option in the box "Pic10B"

    int s1 = ui->spinBox->value();      // S1 - S8 = HW Assignments
    int s2 = ui->spinBox_2->value();
    int s3 = ui->spinBox_3->value();
    int s4 = ui->spinBox_4->value();
    int s5 = ui->spinBox_5->value();
    int s6 = ui->spinBox_6->value();
    int s7 = ui->spinBox_7->value();
    int s8 = ui->spinBox_8->value();

    int s10 = ui->spinBox_9->value();   // int s10 = Midterm 1
    int s11 = ui->spinBox_10->value();  // int s11 = Midterm 2
    int s12 = ui->spinBox_11->value();  // int s12 = Final


    // Calculations for grading scheme A
    double hw = ((s1+s2+s3+s4+s5+s6+s7+s8) / 8) * 0.25;
    double mta1 = s10 * 0.20;
    double mta2 = s11 * 0.20;
    double finala = s12 * 0.35;

    double agrade = hw+mta1+mta2+finala;



    //Calculations for grading scheme B
    double bgrade = 0.0;

    if (mta1>mta2){

        bgrade = hw+(s10*0.35)+(s12*0.44);

    }
    else {

        bgrade = hw+(s11*0.35)+(s12*0.44);

    }

    ui->label_14->setText(QString::number(agrade));
    ui->label_18->setText(QString::number(bgrade));

}


if(ui->comboBox->currentIndex() == 1){  // For second item in combo box "Pic 10c" -- grade calculation is wrong, just multiplies some by 5 for proof of concept.

    int s1 = ui->spinBox->value();      // S1 - S8 = HW Assignments
    int s2 = ui->spinBox_2->value();
    int s3 = ui->spinBox_3->value();
    int s4 = ui->spinBox_4->value();
    int s5 = ui->spinBox_5->value();
    int s6 = ui->spinBox_6->value();
    int s7 = ui->spinBox_7->value();
    int s8 = ui->spinBox_8->value();

    int s10 = ui->spinBox_9->value();   // int s10 = Midterm 1
    int s11 = ui->spinBox_10->value();  // int s11 = Midterm 2
    int s12 = ui->spinBox_11->value();  // int s12 = Final


    // Calculations for grading scheme A
    double hw = ((s1+s2+s3+s4+s5+s6+s7+s8) / 8) * 0.25 * 5;
    double mta1 = s10 * 0.20 * 5;
    double mta2 = s11 * 0.20 * 5;
    double finala = s12 * 0.35 * 5;

    double agrade = hw+mta1+mta2+finala;



    //Calculations for grading scheme B
    double bgrade = 0.0;

    if (mta1>mta2){

        bgrade = hw+(s10*0.35)+(s12*0.44);

    }
    else {

        bgrade = hw+(s11*0.35)+(s12*0.44);

    }

    ui->label_14->setText(QString::number(agrade));
    ui->label_18->setText(QString::number(bgrade));

}



return;
}


