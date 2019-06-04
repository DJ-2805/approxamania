#include "dialog.h"
#include "ui_dialog.h"
#include "Function.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui ->setupUi(this);

    this -> setFixedSize(1250,750);

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
    QLabel * instruction_label = new QLabel ("<h3>Select the power of the polynomial you'd like to approximate:</h3>");

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

    page2_label = new QLabel;

    QLabel * guess_label1 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                      "\nPush 'Choose Graph' button once you've made your choice");

    guess_button1 = new QPushButton("Choose Graph");

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

    SimplePageLayout = new QGridLayout(simplePage);

    SimplePageLayout -> addWidget(page2_label, 2, 6, 1, 3);
    SimplePageLayout -> addWidget(heart_pic_label11, 0, 6);
    SimplePageLayout -> addWidget(heart_pic_label21, 0, 7);
    SimplePageLayout -> addWidget(heart_pic_label31, 0, 8);
    SimplePageLayout -> addWidget(guess_label1, 3,6,2, 3 );
    SimplePageLayout -> addWidget(guess_button1, 5,6,2, 3);
    SimplePageLayout -> addWidget(ui->graph1, 0, 0, 6, 6);
    SimplePageLayout -> addWidget(page2ToHomeButton, 6, 0, 1, 6);
    SimplePageLayout -> addLayout(help_and_muteLayout2, 7, 0, 1, 6);

// widget three - intermediate
    QWidget * IntermediatePage= new QWidget;
    IntermediatePageLayout = new QGridLayout(IntermediatePage);

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

    page3_label = new QLabel;

    QLabel * guess_label2 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                      "\nPush 'Choose Graph' button once you've made your choice");

    guess_button2 = new QPushButton("Choose Graph");

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
    IntermediatePageLayout -> addWidget(heart_pic_label12, 0, 6);
    IntermediatePageLayout -> addWidget(heart_pic_label22, 0, 7);
    IntermediatePageLayout -> addWidget(guess_label2, 3,6,2, 3 );
    IntermediatePageLayout -> addWidget(guess_button2, 5,6,2, 3);
    IntermediatePageLayout -> addWidget(ui->graph2, 0, 0, 6, 6);
    IntermediatePageLayout -> addWidget(page3ToHomeButton, 6, 0, 1, 6);
    IntermediatePageLayout -> addLayout(help_and_muteLayout3, 7, 0, 1, 6);

// widget four - difficult
    QWidget * DifficultPage = new QWidget;
    DifficultPageLayout = new QGridLayout (DifficultPage);
    heart_pic_label13 = new QLabel ;
    QPixmap heart_lives_picture13 (":/img/img/heart3d.png");
    heart_pic_label13 -> setPixmap( heart_lives_picture1);
    heart_pic_label13 -> setScaledContents(true);
    heart_pic_label13 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    page4_label = new QLabel;

    QLabel * guess_label3 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                      "\nPush 'Choose Graph' button once you've made your choice");

    guess_button3 = new QPushButton("Choose Graph");


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
    DifficultPageLayout -> addWidget(heart_pic_label13, 0, 6);
    DifficultPageLayout -> addWidget(guess_label3, 3,6,2, 3 );
    DifficultPageLayout -> addWidget(guess_button3, 5,6,2, 3);
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
    QLabel * helpPage_descript1 = new QLabel ("Approxamania is an educational game of guessing. The user must first enter the power");
        helpPage_descript1->setWordWrap(true);
    QLabel * helpPage_descript2 = new QLabel ("of the polynomial they would like to graph (between 1 and 4):");
        QLabel * helpPage_descript3 = new QLabel ("- 1 being a linear function of the form f(x) = ax + b");
        QLabel * helpPage_descript4 = new QLabel ("- 4 being a polynomial of the form f(x) = ax<sup>4</sup>+bx<sup>3</sup>+cx<sup>2</sup>+dx+e");
        QLabel * helpPage_descript5 = new QLabel ("After choosing a power, the user then selects a difficulty which dictates how");
        QLabel * helpPage_descript6 = new QLabel ("many graphs will be plotted and alongside the one they chose.");
        QLabel * helpPage_descript7 = new QLabel ("The goal of the user is to select the curve they chose before running out lives.");
        QLabel * helpPage_descript8 = new QLabel ("Each incorrect guess will cost them a life, but will also delete a curve off the plot.");
        QLabel * helpPage_descript9 = new QLabel ("Through this process the user will be aquainted with different power polynomials and learn their patterns.");
        QLabel * helpPage_descript10 = new QLabel ("");
        QLabel * helpPage_descript11 = new QLabel ("");

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

// widget six - winning page - more levels to advance
    QWidget * winPage = new QWidget;
    QLabel * congrats_label = new QLabel ("<h1> Congratulations, you won!");

    QHBoxLayout * restart_and_exitLayout1 = new QHBoxLayout;
    QPushButton * restartButton1 = new QPushButton("Restart game");
    QPushButton * exitButton1 = new QPushButton("Exit game");

    restart_and_exitLayout1 -> addWidget(restartButton1);
    restart_and_exitLayout1 -> addWidget(exitButton1);

    QVBoxLayout * winPageLayout = new QVBoxLayout(winPage);
    winPageLayout -> addWidget(congrats_label);
    winPageLayout -> addLayout(restart_and_exitLayout1);


// widget seven - out of lives page
    QWidget * losePage = new QWidget;
    QLabel * lose_label = new QLabel ("<h1>Sorry, you lost.");
    QHBoxLayout * restart_and_exitLayout2 = new QHBoxLayout;
    QPushButton * restartButton2 = new QPushButton("Restart game");
    QPushButton * exitButton2 = new QPushButton("Exit game");

    restart_and_exitLayout2 -> addWidget(restartButton2);
    restart_and_exitLayout2 -> addWidget(exitButton2);

    QVBoxLayout *losePageLayout = new QVBoxLayout(losePage);
    losePageLayout -> addWidget(lose_label);
    losePageLayout -> addLayout(restart_and_exitLayout2);


// stack
    _stackedWidget = new QStackedWidget;
    _stackedWidget -> addWidget(firstPage);
    _stackedWidget -> addWidget(simplePage);
    _stackedWidget -> addWidget(IntermediatePage);
    _stackedWidget -> addWidget(DifficultPage);
    _stackedWidget -> addWidget(helpPage);
    _stackedWidget -> addWidget(winPage);
    _stackedWidget -> addWidget(losePage);


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

    // graph interaction

    connect(guess_button1, SIGNAL(clicked()), this, SLOT(graph_clicked1()));
    connect(guess_button2, SIGNAL(clicked()), this, SLOT(graph_clicked2()));
    connect(guess_button3, SIGNAL(clicked()), this, SLOT(graph_clicked3()));

    //post-game connections
    connect(restartButton1, SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(restartButton2, SIGNAL(clicked()), this, SLOT(goToHome()));

}

void Dialog::goToPage2(){

    //easy
    if(diff_1 ->isChecked()){

        polynomial_order = poly_order ->value();
        std::vector <int> all_other_degrees;
        for (int i = 1; i < 5; i++) {
            if(i != polynomial_order){
                all_other_degrees.push_back(i);
            }
        }

        Function * easy_graph_2 = new Function (all_other_degrees[0], "simple");

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

       // real graph

       ui -> graph1 -> setInteraction(QCP::iSelectPlottables);
       ui -> graph1 ->addGraph();
       ui -> graph1 -> graph(0) -> setData(graph->getX(), graph->getY());
       // insert fake graphs
       ui -> graph1 ->addGraph();
       ui -> graph1 -> graph(1) -> setData(easy_graph_2->getX(), easy_graph_2->getY());

           // give the axes some labels:
           ui -> graph1 ->xAxis->setLabel("x");
           ui -> graph1 ->yAxis->setLabel("y");
           // set axes ranges, so we see all data:
           ui->graph1->xAxis->setRange(-20, 20);
           ui->graph1->yAxis->setRange(-50, 50);

           //randonmly assign color
           int j = rand() % 2;

           int k = rand() % 2;
           while(k==j){k = rand() % 2;}

           ui -> graph1 -> graph(j)->setPen(QPen(Qt::cyan));
           ui -> graph1 -> graph(k)->setPen(QPen(Qt::red));
           ui->graph1->replot();
    }

    //intermediate
    if(diff_2 ->isChecked()){
        polynomial_order = poly_order ->value();


      std::vector <int> all_other_degrees;
      for (int i = 1; i < 5; i++) {
          if(i != polynomial_order){
              all_other_degrees.push_back(i);
          }
      }


      // should be a random index
      Function * inter_graph_2 = new Function (all_other_degrees[0], "intermediate");
      Function * inter_graph_3 = new Function (all_other_degrees[1], "intermediate");

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

      //real graph
      ui -> graph2 -> setInteraction(QCP::iSelectPlottables);
      ui -> graph2 ->addGraph();
      ui -> graph2 -> graph(0) -> setData(graph->getX(), graph->getY());


      //add fake graphs
      ui -> graph2 ->addGraph();
      ui -> graph2 -> graph(1) -> setData(inter_graph_2->getX(), inter_graph_2->getY());

      ui -> graph2 ->addGraph();
      ui -> graph2 -> graph(2) -> setData(inter_graph_3->getX(), inter_graph_3->getY());

      // give the axes some labels:
      ui -> graph2 ->xAxis->setLabel("x");
      ui -> graph2 ->yAxis->setLabel("y");
      // set axes ranges, so we see all data:
      ui->graph2->xAxis->setRange(-20, 20);
      ui->graph2->yAxis->setRange(-40, 40);

      //randonmly assign graph color
      int j = rand() % 3;

      int k = rand() % 3;
      while(k==j){k = rand() % 3;}

      int l = rand() % 3;
      while(l==j || l==k){l = rand() % 3;}

      ui -> graph2 -> graph(j)->setPen(QPen(Qt::cyan));
      ui -> graph2 -> graph(k)->setPen(QPen(Qt::red));
      ui -> graph2 -> graph(l)->setPen(QPen(Qt::green));

      ui->graph2->replot();

    }

    //difficult
    if(diff_3 ->isChecked()){
        polynomial_order = poly_order ->value();
        std::vector <int> all_other_degrees;
        for (int i = 1; i < 5; i++) {
            if(i != polynomial_order){
                all_other_degrees.push_back(i);
            }
        }

        _stackedWidget -> setCurrentIndex(3);
        graph = new Function(polynomial_order, "difficult");

        Function * diff_graph_2 = new Function (all_other_degrees[0], "difficult");
        Function * diff_graph_3 = new Function (all_other_degrees[1], "difficult");
        Function * diff_graph_4 = new Function (all_other_degrees[2], "difficult");

        // read function into stringstream from print function
        std::stringstream func_reader ;
        func_reader << "Function:\n";
        graph -> printFunc(func_reader); // func_reader now holds output from print function
        func_reader << "\n\nZero:\n";
        func_reader << std::to_string(graph -> getZero());
        std::string s = func_reader.str(); // string is given all stringstream content
        page4_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

        //real graph
        ui -> graph3 ->addGraph();
        ui -> graph3 -> graph(0) -> setData(graph->getX(), graph->getY());
        ui -> graph3 -> setInteraction(QCP::iSelectPlottables);

        //insert fake graphs
        ui -> graph3 ->addGraph();
        ui -> graph3 -> graph(1) -> setData(diff_graph_2->getX(), diff_graph_2->getY());

        ui -> graph3 ->addGraph();
        ui -> graph3 -> graph(2) -> setData(diff_graph_3->getX(), diff_graph_3->getY());

        ui -> graph3 ->addGraph();
        ui -> graph3 -> graph(3) -> setData(diff_graph_4->getX(), diff_graph_4->getY());

        // give the axes some labels:
        ui -> graph3 ->xAxis->setLabel("x");
        ui -> graph3 ->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui->graph3->xAxis->setRange(-20, 20);
        ui->graph3->yAxis->setRange(-40, 40);

        //randonmly assign color
           int j = rand() % 4;

           int k = rand() % 4;
           while(k==j){k = rand() % 4;}

           int l = rand() % 4;
           while(l==j || l==k){l = rand() % 4;}


           int m = rand() % 4;
           while (m ==j || m==k || m==l){m = rand() % 4;}


           ui -> graph3 -> graph(j)->setPen(QPen(Qt::magenta));
           ui -> graph3 -> graph(k)->setPen(QPen(Qt::red));
           ui -> graph3 -> graph(l)->setPen(QPen(Qt::green));
           ui -> graph3 -> graph(m)->setPen(QPen(Qt::cyan));


        ui->graph3->replot();
    }

}

void Dialog::goToHome(){
    _stackedWidget -> setCurrentIndex(0);
    heart_pic_label11 -> setVisible(true);
    heart_pic_label21 -> setVisible(true);
    heart_pic_label31 -> setVisible(true);
    hearts = {1,2,3};
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

void Dialog::graph_clicked1(){

qDebug() << "graph click registered";

    bool continuing_to_guess_wrong = true;

    graphs_list = ui -> graph1 -> selectedGraphs();

    qDebug() << "list of graphs initialized";

    bool selected_right_graph = graphs_list.contains(ui -> graph1 -> graph(0));

    while(continuing_to_guess_wrong){

        if(!selected_right_graph && hearts.size()==3){
            qDebug() << "no graph removed - clicked on wrong graph - 3";
            heart_pic_label31 -> setVisible(false);
            qDebug() << "heart removed from heart_layout";
            hearts.pop_back();
            qDebug() << "vector size updated";
            continuing_to_guess_wrong =false;
            qDebug() << "bool set false ";
        }

        else if(!selected_right_graph && hearts.size()==2){
            qDebug() << " no graph removed - clicked on wrong graph - 2\n";
            heart_pic_label21 -> setVisible(false);
            qDebug() << "heart removed from heart_layout\n";
            hearts.pop_back();
            continuing_to_guess_wrong =false;
        }

        else if(!selected_right_graph && hearts.size()==1){
            qDebug() << " no graph removed - clicked on wrong graph - 1\n";
            heart_pic_label11 -> setVisible(false);
            qDebug() << "heart removed from heart_layout\n";
            hearts.pop_back();
            _stackedWidget -> setCurrentIndex(6);
            continuing_to_guess_wrong =false;
        }

        if(selected_right_graph){
            qDebug() << "right graph selected";

            ui -> graph1 -> removeGraph(0);
            qDebug() << "real graph removed";
            ui -> graph1 -> replot();
            qDebug() << "replotted";

            _stackedWidget -> setCurrentIndex(5);
            continuing_to_guess_wrong =false;
        }

  }

}

void Dialog::graph_clicked2(){

    qDebug() << "graph click registered";

        bool continuing_to_guess_wrong = true;

        graphs_list = ui -> graph2 -> selectedGraphs();

        qDebug() << "list of graphs initialized";

        bool selected_right_graph = graphs_list.contains(ui -> graph2 -> graph(0));

        while(continuing_to_guess_wrong){

            if(!selected_right_graph && hearts.size()==3){
                qDebug() << "no graph removed - clicked on wrong graph - 3";
                heart_pic_label22 -> setVisible(false);
                qDebug() << "heart removed from heart_layout";
                hearts.pop_back();
                qDebug() << "vector size updated";
                continuing_to_guess_wrong =false;
                qDebug() << "bool set false ";
            }

            else if(!selected_right_graph && hearts.size()==2){
                qDebug() << " no graph removed - clicked on wrong graph - 2\n";
                heart_pic_label12 -> setVisible(false);
                qDebug() << "heart removed from heart_layout\n";
                hearts.pop_back();
                _stackedWidget -> setCurrentIndex(6);
                continuing_to_guess_wrong =false;
            }

            if(selected_right_graph){
                qDebug() << "right graph selected";

                ui -> graph2 -> removeGraph(0);
                qDebug() << "real graph removed";
                ui -> graph2 -> replot();
                qDebug() << "replotted";

                _stackedWidget -> setCurrentIndex(5);
                continuing_to_guess_wrong =false;
            }

      }

    }

void Dialog::graph_clicked3(){
    qDebug() << "graph click registered";

        bool continuing_to_guess_wrong = true;

        graphs_list = ui -> graph3 -> selectedGraphs();

        qDebug() << "list of graphs initialized";

        bool selected_right_graph = graphs_list.contains(ui -> graph3 -> graph(0));

        while(continuing_to_guess_wrong){

            if(!selected_right_graph && hearts.size()==3){
                qDebug() << "no graph removed - clicked on wrong graph - 3";
                heart_pic_label13 -> setVisible(false);
                qDebug() << "heart removed from heart_layout";
                hearts.pop_back();
                qDebug() << "vector size updated";
                _stackedWidget -> setCurrentIndex(6);
                continuing_to_guess_wrong =false;
                qDebug() << "bool set false ";
            }

            }

            if(selected_right_graph){
                qDebug() << "right graph selected";

                ui -> graph3 -> removeGraph(0);
                qDebug() << "real graph removed";
                ui -> graph3 -> replot();
                qDebug() << "replotted";

                _stackedWidget -> setCurrentIndex(5);
                continuing_to_guess_wrong =false;
            }

      }

Dialog::~Dialog()
{
    delete ui;
}
