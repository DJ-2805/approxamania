#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);

    this -> setWindowTitle("Approxamania");

// widget one
    QWidget * firstPage = new QWidget;
    QLabel * welcome_label = new QLabel ("Welcome to Approxamania!");
    QLabel * instruction_label = new QLabel ("Select the order polynomial you'd like to approximate:");
    QSpinBox * poly_order = new QSpinBox;
    poly_order -> setRange(0,5);
    QRadioButton * diff_1 = new QRadioButton("Simple");
    QRadioButton * diff_2 = new QRadioButton("Intermediate");
    QRadioButton * diff_3 = new QRadioButton("Difficult");
    QPushButton * page2PushButton = new QPushButton("Graph Polynomial");

    QVBoxLayout *firstPageLayout = new QVBoxLayout(firstPage);

    firstPageLayout-> addWidget(welcome_label);
    firstPageLayout-> addWidget(instruction_label);
    firstPageLayout-> addWidget(poly_order);
    firstPageLayout-> addWidget(diff_1);
    firstPageLayout-> addWidget(diff_2);
    firstPageLayout-> addWidget(diff_3);
    firstPageLayout -> addWidget(page2PushButton);

// widge two
    QWidget * secondPage = new QWidget;
    QLabel * page2_label = new QLabel ("page 2");
    QVBoxLayout *secondPageLayout = new QVBoxLayout(secondPage);
    secondPageLayout -> addWidget(page2_label);

// stack
    _stackedWidget = new QStackedWidget;
    _stackedWidget -> addWidget(firstPage);
    _stackedWidget -> addWidget(secondPage);


// layout
QVBoxLayout * centrallayout = new QVBoxLayout;
centrallayout -> addWidget(_stackedWidget);
setLayout(centrallayout);


// connect push button
connect(page2PushButton, SIGNAL(clicked()), this , SLOT(goToPage2()));

}

void Dialog::goToPage2(){
    _stackedWidget -> setCurrentIndex(1);
}

Dialog::~Dialog()
{
    delete ui;
}
