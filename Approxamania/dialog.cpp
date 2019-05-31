#include "dialog.h"
#include "ui_dialog.h"
#include "Function.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui ->setupUi(this);

    //song
    music = new QMediaPlayer();

    music->setMedia(QUrl("qrc:/img/img/Waves.mp3"));

    music->play();

    //background
    QPixmap background_picture (":/img/img/bluegrid.jpg");
    background_picture = background_picture.scaled(this ->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background_picture);
    this->setPalette(palette);

    //title
    this -> setWindowTitle("Approxamania");

// widget one
    QWidget * firstPage = new QWidget;
    QLabel * welcome_label = new QLabel ("<h2>Welcome to</h2> <h1>Approxamania!</h1>");
    QLabel * instruction_label = new QLabel ("Select the power of the polynomial you'd like to approximate:");

    poly_order = new QSpinBox;
    poly_order -> setRange(1,4);
    diff_1 = new QRadioButton("Simple");
    diff_1 -> setStyleSheet("background-color: black");

    diff_2 = new QRadioButton("Intermediate");
    diff_2 -> setStyleSheet("background-color: black");
    diff_3 = new QRadioButton("Difficult");
    diff_3 -> setStyleSheet("background-color: black");

    QPushButton * page2PushButton = new QPushButton("Graph Polynomial");
    QPushButton * homeToHelpButton = new QPushButton("Help");
    QPushButton * MuteButton = new QPushButton ("Mute music");
    QPushButton * UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * help_and_muteLayout = new QHBoxLayout;
    QHBoxLayout * mute_options_layout = new QHBoxLayout;

    mute_options_layout -> addWidget(MuteButton);
    mute_options_layout -> addWidget(UnmuteButton);

    help_and_muteLayout -> addWidget(homeToHelpButton);
    help_and_muteLayout -> addLayout(mute_options_layout);
    QVBoxLayout *firstPageLayout = new QVBoxLayout(firstPage);

    firstPageLayout-> addWidget(welcome_label);
    firstPageLayout-> addWidget(instruction_label);
    firstPageLayout-> addWidget(poly_order);
    firstPageLayout-> addWidget(diff_1);
    firstPageLayout-> addWidget(diff_2);
    firstPageLayout-> addWidget(diff_3);
    firstPageLayout -> addWidget(page2PushButton);
    firstPageLayout -> addLayout(help_and_muteLayout);

// widget two - simple difficulty
    QWidget * simplePage = new QWidget;

    heart_pic_label11 = new QLabel ;
    QPixmap heart_lives_picture1 (":/img/img/heart3d.png");
    heart_pic_label11 -> setPixmap( heart_lives_picture1);
    heart_pic_label11 -> setScaledContents(true);
    heart_pic_label11 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label21 = new QLabel ;
    QPixmap heart_lives_picture2 (":/img/img/heart3d.png");
    heart_pic_label21 -> setPixmap( heart_lives_picture1);
    heart_pic_label21 -> setScaledContents(true);
    heart_pic_label21 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label31 = new QLabel ;
    QPixmap heart_lives_picture3 (":/img/img/heart3d.png");
    heart_pic_label31 -> setPixmap( heart_lives_picture1);
    heart_pic_label31 -> setScaledContents(true);
    heart_pic_label31 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    hearts_layout1 = new QHBoxLayout;
    hearts_layout1 -> addWidget(heart_pic_label11);
    hearts_layout1 -> addWidget(heart_pic_label21);
    hearts_layout1 -> addWidget(heart_pic_label31);

    page2_label = new QLabel;

    QPushButton * show_graph1 = new QPushButton("Show Graph");
    QPushButton * hide_graph1 = new QPushButton("Hide Graph");

    graph_display = new QVBoxLayout;
    graph_display -> addWidget(show_graph1);
    graph_display -> addWidget(hide_graph1);

    QPushButton * page2ToHomeButton = new QPushButton ("Reset");
    QPushButton * page2ToHelpButton = new QPushButton ("Help");
    QPushButton * page2MuteButton = new QPushButton("Mute music");
    QPushButton * page2UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout2 = new QHBoxLayout;
    mute_options_layout2 -> addWidget(page2MuteButton);
    mute_options_layout2 -> addWidget(page2UnmuteButton);

    QHBoxLayout * help_and_muteLayout2 = new QHBoxLayout;
    help_and_muteLayout2 -> addWidget(page2ToHelpButton);
    help_and_muteLayout2 -> addLayout(mute_options_layout2);

    QGridLayout *secondPageLayout = new QGridLayout(simplePage);

    secondPageLayout -> addWidget(page2_label, 2, 6, 1, 3);
    secondPageLayout -> addLayout(graph_display, 6, 6, 2, 3);
    secondPageLayout -> addLayout(hearts_layout1, 0, 6, 1, 3);
    secondPageLayout -> addWidget(ui->graph1, 0, 0, 6, 6);
    secondPageLayout -> addWidget(page2ToHomeButton, 6, 0, 1, 6);
    secondPageLayout -> addLayout(help_and_muteLayout2, 7, 0, 1, 6);

// widget three - intermediate
    QWidget * IntermediatePage= new QWidget;
    QGridLayout * IntermediatePageLayout = new QGridLayout(IntermediatePage);

    hearts_layout2 = new QHBoxLayout;
    heart_pic_label12 = new QLabel ;
    QPixmap heart_lives_picture12 (":/img/img/heart3d.png");
    heart_pic_label12 -> setPixmap( heart_lives_picture1);
    heart_pic_label12 -> setScaledContents(true);
    heart_pic_label12 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );
    heart_pic_label22 = new QLabel ;
    QPixmap heart_lives_picture22 (":/img/img/heart3d.png");
    heart_pic_label22 -> setPixmap( heart_lives_picture1);
    heart_pic_label22 -> setScaledContents(true);
    heart_pic_label22 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    hearts_layout2 -> addWidget(heart_pic_label12);
    hearts_layout2 -> addWidget(heart_pic_label22);

    page3_label = new QLabel;

    QPushButton * show_graph2 = new QPushButton("Show Graph");
    QPushButton * hide_graph2 = new QPushButton("Hide Graph");

    QVBoxLayout * graph_display2 = new QVBoxLayout;
    graph_display2 -> addWidget(show_graph2);
    graph_display2 -> addWidget(hide_graph2);

    QPushButton * page3ToHomeButton = new QPushButton ("Reset");
    QPushButton * page3ToHelpButton = new QPushButton ("Help");
    QPushButton * page3MuteButton = new QPushButton("Mute music");
    QPushButton * page3UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout3 = new QHBoxLayout;
    mute_options_layout3 -> addWidget(page3MuteButton);
    mute_options_layout3 -> addWidget(page3UnmuteButton);

    QHBoxLayout * help_and_muteLayout3 = new QHBoxLayout;
    help_and_muteLayout3 -> addWidget(page3ToHelpButton);
    help_and_muteLayout3 -> addLayout(mute_options_layout3);

    IntermediatePageLayout -> addWidget(page3_label, 1, 6, 1, 3);
    IntermediatePageLayout -> addLayout(graph_display2, 6, 6, 2, 3);
    IntermediatePageLayout -> addLayout(hearts_layout2, 0, 6, 1, 2);
    IntermediatePageLayout -> addWidget(ui->graph2, 0, 0, 6, 6);
    IntermediatePageLayout -> addWidget(page3ToHomeButton, 6, 0, 1, 6);
    IntermediatePageLayout -> addLayout(help_and_muteLayout3, 7, 0, 1, 6);

// widget four - difficult
    QWidget * DifficultPage = new QWidget;
    QGridLayout * DifficultPageLayout = new QGridLayout (DifficultPage);
    hearts_layout3 = new QHBoxLayout;
    heart_pic_label13 = new QLabel ;
    QPixmap heart_lives_picture13 (":/img/img/heart3d.png");
    heart_pic_label13 -> setPixmap( heart_lives_picture1);
    heart_pic_label13 -> setScaledContents(true);
    heart_pic_label13 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    hearts_layout3 -> addWidget(heart_pic_label13);

    page4_label = new QLabel;

    QPushButton * show_graph3 = new QPushButton("Show Graph");
    QPushButton * hide_graph3 = new QPushButton("Hide Graph");

    QVBoxLayout * graph_display3 = new QVBoxLayout;
    graph_display3 -> addWidget(show_graph3);
    graph_display3 -> addWidget(hide_graph3);

    QPushButton * page4ToHomeButton = new QPushButton ("Reset");
    QPushButton * page4ToHelpButton = new QPushButton ("Help");
    QPushButton * page4MuteButton = new QPushButton("Mute music");
    QPushButton * page4UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout4 = new QHBoxLayout;
    mute_options_layout4 -> addWidget(page4MuteButton);
    mute_options_layout4 -> addWidget(page4UnmuteButton);

    QHBoxLayout * help_and_muteLayout4 = new QHBoxLayout;
    help_and_muteLayout4 -> addWidget(page4ToHelpButton);
    help_and_muteLayout4 -> addLayout(mute_options_layout4);

    DifficultPageLayout -> addWidget(page4_label, 1, 6, 1, 3);
    DifficultPageLayout -> addLayout(graph_display3, 6, 6, 2, 3);
    DifficultPageLayout -> addLayout(hearts_layout3, 0, 6, 1, 1);
    DifficultPageLayout -> addWidget(ui->graph3, 0, 0, 6, 6);
    DifficultPageLayout -> addWidget(page4ToHomeButton, 6, 0, 1, 6);
    DifficultPageLayout -> addLayout(help_and_muteLayout4, 7, 0, 1, 6);

// widget five
// help page
    // description
    //difficulty is about amount of lives and amount of error allowed
    QWidget * helpPage = new QWidget;
    QLabel * helpPage_label = new QLabel ("<h1>Help Page</h1>");
    helpPage_label -> setAlignment(Qt::AlignCenter);
    QPushButton * helpToHomeButton = new QPushButton("Return to Home Screen");
    QLabel * helpPage_descript1 = new QLabel ("Approxamania is a game of guessing. The user must first enter the power");
    helpPage_descript1->setWordWrap(true);
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
    _stackedWidget -> addWidget(simplePage);
    _stackedWidget -> addWidget(IntermediatePage);
    _stackedWidget -> addWidget(DifficultPage);
    _stackedWidget -> addWidget(helpPage);


// layout
    QVBoxLayout * centrallayout = new QVBoxLayout;
    centrallayout -> addWidget(_stackedWidget);
    setLayout(centrallayout);

// connect push button
    // page 2 varies on selected difficulty
    connect(page2PushButton, SIGNAL(clicked()), this , SLOT(goToPage2()));
    connect(helpToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(homeToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));

    connect(page2ToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));
    connect(page3ToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));
    connect(page4ToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));

    connect(page2ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(page3ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(page4ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));

    connect (MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page2MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page3MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page4MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));

    connect(UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));
    connect(page2UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));
    connect(page3UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));
    connect(page4UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));

    // graph show/hide
    connect(show_graph1, SIGNAL(clicked()), this, SLOT(show_graph_data(Function * graph)));
    connect(hide_graph1, SIGNAL(clicked()), this, SLOT(hide_graph_data(Function * graph)));

    connect(show_graph2, SIGNAL(clicked()), this, SLOT(show_graph_data(Function * graph)));
    connect(hide_graph2, SIGNAL(clicked()), this, SLOT(hide_graph_data(Function * graph)));

    connect(show_graph3, SIGNAL(clicked()), this, SLOT(show_graph_data(Function * graph)));
    connect(hide_graph3, SIGNAL(clicked()), this, SLOT(hide_graph_data(Function * graph)));


}

void Dialog::goToPage2(){

    //easy
    if(diff_1 ->isChecked()){
        polynomial_order = poly_order ->value();
       _stackedWidget -> setCurrentIndex(1);
       graph = new Function(polynomial_order, "simple");

       // read function into stringstream from print function
       std::stringstream func_reader ;
       func_reader << "Function:\n";
       graph -> printFunc(func_reader); // func_reader now holds output from print function
       func_reader << "\n\nZero:\n";
       func_reader << std::to_string(graph -> getZero());

       std::string s = func_reader.str(); // string is given all stringstream content
       page2_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

       ui -> graph1 ->addGraph();
       ui -> graph1 -> graph(0) -> setData(graph->getX(), graph->getY());
       // give the axes some labels:
       ui -> graph1 ->xAxis->setLabel("x");
       ui -> graph1 ->yAxis->setLabel("y");
       // set axes ranges, so we see all data:
       ui->graph1->xAxis->setRange(-10, 10);
       ui->graph1->yAxis->setRange(-10, 10);
       ui->graph1->replot();

    }

    //intermediate
    if(diff_2 ->isChecked()){
        polynomial_order = poly_order ->value();
      _stackedWidget -> setCurrentIndex(2);
      graph = new Function(polynomial_order, "intermediate");

      // read function into stringstream from print function
      std::stringstream func_reader ;
      func_reader << "Function:\n";
      graph -> printFunc(func_reader); // func_reader now holds output from print function
      func_reader << "\n\nZero:\n";
      func_reader << std::to_string(graph -> getZero());
      std::string s = func_reader.str(); // string is given all stringstream content
      page3_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

      ui -> graph2 ->addGraph();
      ui -> graph2 -> graph(0) -> setData(graph->getX(), graph->getY());
      // give the axes some labels:
      ui -> graph2 ->xAxis->setLabel("x");
      ui -> graph2 ->yAxis->setLabel("y");
      // set axes ranges, so we see all data:
      ui->graph2->xAxis->setRange(-10, 10);
      ui->graph2->yAxis->setRange(-10, 10);
      ui->graph2->replot();
    }

    //difficult
    if(diff_3 ->isChecked()){
        polynomial_order = poly_order ->value();
        _stackedWidget -> setCurrentIndex(3);
        graph = new Function(polynomial_order, "difficult");

        // read function into stringstream from print function
        std::stringstream func_reader ;
        func_reader << "Function:\n";
        graph -> printFunc(func_reader); // func_reader now holds output from print function
        func_reader << "\n\nZero:\n";
        func_reader << std::to_string(graph -> getZero());
        std::string s = func_reader.str(); // string is given all stringstream content
        page4_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

        ui -> graph3 ->addGraph();
        ui -> graph3 -> graph(0) -> setData(graph->getX(), graph->getY());
        // give the axes some labels:
        ui -> graph3 ->xAxis->setLabel("x");
        ui -> graph3 ->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui->graph3->xAxis->setRange(-10, 10);
        ui->graph3->yAxis->setRange(-10, 10);
        ui->graph3->replot();
    }

}

void Dialog::goToHome(){
    _stackedWidget -> setCurrentIndex(0);
}

void Dialog::goToHelpPage(){
    _stackedWidget -> setCurrentIndex(4);
}

void Dialog::muteMedia(){

    music -> setVolume(0);
}

void Dialog::unMuteMedia(){
    music -> setVolume(100);
}

void Dialog::show_graph_data(Function * graphx){

    if (graphx -> getDiffiulty() == "simple"){

        assert((ui -> graph1 -> clearGraphs()) != 1);

        ui -> graph1 -> graph(0) -> setData(graph -> getX(),graph -> getY());
        ui -> graph1 -> replot();
        ui -> graph1 -> show();

    }

    if (graphx -> getDiffiulty() == "intermediate"){

        assert((ui -> graph2 -> clearGraphs()) != 1);

        ui -> graph2 -> graph(0) -> setData(graph -> getX(),graph -> getY());
        ui -> graph2 -> replot();
        ui -> graph2 -> show();

    }

    if (graphx -> getDiffiulty() == "difficult"){

        assert((ui -> graph3 -> clearGraphs()) != 1);

        ui -> graph3 -> graph(0) -> setData(graph -> getX(),graph -> getY());
        ui -> graph3 -> replot();
        ui -> graph3 -> show();

    }

//    if (graphx -> is_graphed()){
//        if(graphx -> getDiffiulty() == "simple"){
//            ui -> graph1 -> clearGraphs();
//            ui -> graph1 -> replot();
//        }
//        if(graphx -> getDiffiulty() == "intermediate"){
//            ui -> graph2 -> graph(0) -> setData(x_empty,y_empty);
//            ui -> graph2 ;
//        }
//        if(graphx -> getDiffiulty() == "difficult"){
//            ui -> graph3 -> graph(0) -> setData(x_empty,y_empty);
//            ui -> graph3 -> replot();
//        }
//    }
//    else {
//        if(graphx -> getDiffiulty() == "simple"){
//            ui -> graph1 -> graph(0) -> setData(graph -> getX(),graph -> getY());
//            ui -> graph1 -> replot();
//        }
//        if(graphx -> getDiffiulty() == "intermediate"){
//            ui -> graph2 -> graph(0) -> setData(graph -> getX(),graph -> getY());
//            ui -> graph2 -> replot();
//        }
//        if(graphx -> getDiffiulty() == "difficult"){
//            ui -> graph3 -> graph(0) -> setData(graph -> getX(),graph -> getY());
//            ui -> graph3 -> replot();
//        }
//    }
}


void Dialog::hide_graph_data(Function * graphx){

    if (graphx -> getDiffiulty() == "simple"){

    assert((ui -> graph1 -> clearGraphs()) >= 1);

    ui -> graph1 -> clearGraphs();
    ui -> graph1 -> replot();
    }

    if (graphx -> getDiffiulty() == "intermediate"){

    assert((ui -> graph1 -> clearGraphs()) >= 1);

        foreach(QCPGraph* gr, ui -> graph2 -> selectedGraphs()){

            gr->setVisible(false);
        }
    ui -> graph2 -> replot();
    }

    if (graphx -> getDiffiulty() == "difficult"){

    assert((ui -> graph1 -> clearGraphs()) >= 1);

        foreach(QCPGraph* gr, ui -> graph3-> selectedGraphs()){

            gr->setVisible(false);
        }
    ui -> graph3 -> replot();
    }

}
Dialog::~Dialog()
{
    delete ui;
}
