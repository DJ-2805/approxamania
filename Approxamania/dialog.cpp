#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);

    QPixmap background_picture (":/img/img/bluegrid.jpg");
    background_picture = background_picture.scaled(this ->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background_picture);
    this->setPalette(palette);

    this -> setWindowTitle("Approxamania");

// widget one
    QWidget * firstPage = new QWidget;
    QLabel * welcome_label = new QLabel ("<h2>Welcome to</h2> <h1>Approxamania!</h1>");
    QLabel * instruction_label = new QLabel ("Select the power of the polynomial you'd like to approximate:");
    QSpinBox * poly_order = new QSpinBox;
    poly_order -> setRange(1,4);
    diff_1 = new QRadioButton("Simple");
    diff_1 -> setStyleSheet("background-color: black");

    diff_2 = new QRadioButton("Intermediate");
    diff_2 -> setStyleSheet("background-color: black");
    diff_3 = new QRadioButton("Difficult");
    diff_3 -> setStyleSheet("background-color: black");

    QPushButton * page2PushButton = new QPushButton("Graph Polynomial");
    QPushButton * homeToHelpButton = new QPushButton("Help");

    QVBoxLayout *firstPageLayout = new QVBoxLayout(firstPage);

    firstPageLayout-> addWidget(welcome_label);
    firstPageLayout-> addWidget(instruction_label);
    firstPageLayout-> addWidget(poly_order);
    firstPageLayout-> addWidget(diff_1);
    firstPageLayout-> addWidget(diff_2);
    firstPageLayout-> addWidget(diff_3);
    firstPageLayout -> addWidget(page2PushButton);
    firstPageLayout -> addWidget(homeToHelpButton);

// widget two
    QWidget * secondPage = new QWidget;
    heart_pic_label1 = new QLabel ;
    QPixmap heart_lives_picture1 (":/img/img/heart3d.png");
    heart_pic_label1 -> setPixmap( heart_lives_picture1);
    heart_pic_label1 -> setScaledContents(true);
    heart_pic_label1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label2 = new QLabel ;
    QPixmap heart_lives_picture2 (":/img/img/heart3d.png");
    heart_pic_label2 -> setPixmap( heart_lives_picture1);
    heart_pic_label2 -> setScaledContents(true);
    heart_pic_label2 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label3 = new QLabel ;
    QPixmap heart_lives_picture3 (":/img/img/heart3d.png");
    heart_pic_label3 -> setPixmap( heart_lives_picture1);
    heart_pic_label3 -> setScaledContents(true);
    heart_pic_label3 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    hearts_layout = new QHBoxLayout;

    QLabel * page2_label = new QLabel ("page 2 : where graph would go");

    QPushButton * page2ToHomeButton = new QPushButton ("Reset");
    QPushButton * page2ToHelpButton = new QPushButton ("Help");

    QGridLayout *secondPageLayout = new QGridLayout(secondPage);

    secondPageLayout -> addWidget(page2_label, 3, 3);
    secondPageLayout -> addLayout(hearts_layout, 0, 5);
    secondPageLayout -> addWidget(page2ToHomeButton, 4, 0, 1, 6);
    secondPageLayout -> addWidget(page2ToHelpButton, 5, 0, 1, 6);

// widget three
// help page
    // description
    //difficulty is about amount of lives and amount of error allowed
    QWidget * helpPage = new QWidget;
    QLabel * helpPage_label = new QLabel ("<h1>Help Page</h1>");
    helpPage_label -> setAlignment(Qt::AlignCenter);
    QPushButton * helpToHomeButton = new QPushButton("Return to Home Screen");
    QLabel * helpPage_descript1 = new QLabel ("Approxamania is a game of guessing. The user must first enter the power");
    QLabel * helpPage_descript2 = new QLabel ("of the polynomial they would like to graph (between 1 and 4):");
    QLabel * helpPage_descript3 = new QLabel ("- 1 being a linear function of the form f(x) = ax + b");
    QLabel * helpPage_descript4 = new QLabel ("- 4 being a polynomial of the form f(x) = ax<sup>4</sup>+bx<sup>3</sup>+cx<sup>2</sup>+dx+e");
    QLabel * helpPage_descript5 = new QLabel ("After selecting order, user then selects a difficulty which dictates how");
    QLabel * helpPage_descript6 = new QLabel ("many chances they get to guess as well as how large of an error bound");
    QLabel * helpPage_descript7 = new QLabel ("they will be allowed. User then can push 'Graph Polynomial' button and");
    QLabel * helpPage_descript8 = new QLabel ("will be give chances to click (on blank grid) on where they believe the");
    QLabel * helpPage_descript9 = new QLabel ("zeroes of the graphs are (the values of x such that f(x) = 0). ");
    QLabel * helpPage_descript10 = new QLabel ("If user can guess a zero under the constraints of their selected");
    QLabel * helpPage_descript11 = new QLabel ("difficulty, they will be prompted with a game right on their graph.");

//    QVBoxLayout *

    QGridLayout * helpPageLayout = new QGridLayout(helpPage);

    helpPageLayout -> addWidget(helpPage_label);
    helpPageLayout -> addWidget(helpPage_descript1);
    helpPageLayout -> addWidget(helpPage_descript2);
    helpPageLayout -> addWidget(helpPage_descript3);
    helpPageLayout -> addWidget(helpPage_descript4);
    helpPageLayout -> addWidget(helpPage_descript5);
    helpPageLayout -> addWidget(helpPage_descript6);
    helpPageLayout -> addWidget(helpPage_descript7);
    helpPageLayout -> addWidget(helpPage_descript8);
    helpPageLayout -> addWidget(helpPage_descript9);
    helpPageLayout -> addWidget(helpPage_descript10);
    helpPageLayout -> addWidget(helpPage_descript11);
    helpPageLayout-> addWidget(helpToHomeButton);

// stack
    _stackedWidget = new QStackedWidget;
    _stackedWidget -> addWidget(firstPage);
    _stackedWidget -> addWidget(secondPage);
    _stackedWidget -> addWidget(helpPage);


// layout
    QVBoxLayout * centrallayout = new QVBoxLayout;
    centrallayout -> addWidget(_stackedWidget);
    setLayout(centrallayout);

// connect push button
    connect(page2PushButton, SIGNAL(clicked()), this , SLOT(goToPage2()));
    connect(helpToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(homeToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));
    connect(page2ToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));
    connect(page2ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));

}

void Dialog::goToPage2(){
    _stackedWidget -> setCurrentIndex(1);

    if(diff_1 ->isChecked()){
        x = 1;
        hearts_layout -> addWidget(heart_pic_label1);
        hearts_layout -> addWidget(heart_pic_label2);
        hearts_layout -> addWidget(heart_pic_label3);
    }

    if(diff_2 ->isChecked()){
        x = 2;
        hearts_layout -> addWidget(heart_pic_label1);
        hearts_layout -> addWidget(heart_pic_label2);
    }

    if(diff_3 ->isChecked()){
        x = 3;
        hearts_layout -> addWidget(heart_pic_label1);

    }

}

void Dialog::goToHome(){
    _stackedWidget -> setCurrentIndex(0);
//    if(x == 1){
//        hearts_layout -> removeWidget(heart_pic_label1);
//        delete heart_pic_label1;
//        hearts_layout -> removeWidget(heart_pic_label2);
//        delete  heart_pic_label2;
//        hearts_layout -> removeWidget(heart_pic_label3);
//        delete heart_pic_label3;
//    }
//    if (x == 2){
//        hearts_layout -> removeWidget(heart_pic_label1);
//        delete heart_pic_label1;
//        hearts_layout -> removeWidget(heart_pic_label2);
//        delete heart_pic_label2;
//    }

//    if (x==3){
//        hearts_layout -> removeWidget(heart_pic_label1);
//        delete heart_pic_label1;
//    }

}

void Dialog::goToHelpPage(){
    _stackedWidget -> setCurrentIndex(2);

}

Dialog::~Dialog()
{
    delete ui;
}
