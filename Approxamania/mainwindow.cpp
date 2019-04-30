#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QSpinBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    firstPage = new QWidget;
    welcome_label = new QLabel ("Welcome to Approxamania!");
    instruction_label = new QLabel ("Select the order polynomial you'd like to approximate");
    qDebug() << "Made labels";
    poly_order = new QSpinBox;
    poly_order -> setRange(0,5);
    qDebug() << "made spinbox";
    diff_1 = new QRadioButton("simple");
    diff_2 = new QRadioButton("intermediate");
    diff_3 = new QRadioButton("difficult");
    qDebug() << "made buttons";
    diff_layout = new QVBoxLayout;
    diff_layout -> addWidget(diff_1);
    diff_layout -> addWidget(diff_2);
    diff_layout -> addWidget(diff_3);

    qDebug() <<  "made difficulty layout";

    page2PushButton = new QPushButton("click for page 2");

    main_window_layout = new QHBoxLayout(firstPage);

    main_window_layout -> addWidget(welcome_label);
    main_window_layout -> addWidget(instruction_label);
    main_window_layout -> addWidget(poly_order);
    main_window_layout -> addLayout(diff_layout);
    main_window_layout -> addWidget(page2PushButton);

    qDebug() <<   "main window";

    secondPage = new QWidget;
    secondpage_label = new QLabel("page 2");
    second_window_layout = new QHBoxLayout(secondPage);

    second_window_layout -> addWidget(secondpage_label);


    _stackedWidget = new QStackedWidget;
    _stackedWidget -> addWidget(firstPage);
    _stackedWidget -> addWidget(secondPage);

    central_layout = new QVBoxLayout;
    central_layout -> addWidget(_stackedWidget);
    this -> setCentralWidget(firstPage);

    setLayout(central_layout);

    connect(page2PushButton, SIGNAL(clicked()), this, SLOT(goToPage2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToPage2(){
   _stackedWidget -> setCurrentIndex(1);
}
