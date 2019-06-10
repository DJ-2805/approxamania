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
    QLabel * welcome_label = new QLabel ("<h5>Welcome to</h5> <h2>Approxamania</h2>");
    welcome_label ->setAlignment(Qt::AlignCenter);
    welcome_label -> setStyleSheet("font: 80pt;"
                                   "color: darkMagenta;"
                                   "background-color: rgba(255, 255, 255, 150);");



    QLabel * instruction_label = new QLabel ("<h3>Select the power of the polynomial you'd like to approximate.</h3>"
                                             "\n<h4>Once you've chosen a degree and a difficulty, <font color=\"green\">'Graph Polynomial'</font> will generate polynomials of different degrees with randonmly generated coeffecients: </h4<");
    instruction_label -> setAlignment(Qt::AlignCenter);

    poly_order = new QSpinBox;
    poly_order -> setRange(1,4);

    diff_1 = new QRadioButton("Simple");
//    diff_1 -> setStyleSheet("background-color: cyan");
    diff_2 = new QRadioButton("Intermediate");
//    diff_2 -> setStyleSheet("background-color: cyan");
    diff_3 = new QRadioButton("Difficult");
//    diff_3 -> setStyleSheet("background-color: cyan");

    QGroupBox * groupBox = new QGroupBox("Select Difficulty");
    QVBoxLayout * difficulty_layout  = new QVBoxLayout;
    difficulty_layout -> addWidget(diff_1);
    difficulty_layout -> addWidget(diff_2);
    difficulty_layout -> addWidget(diff_3);
    groupBox -> setLayout(difficulty_layout);
    groupBox -> setStyleSheet("background-color: black;");


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

    game_changer1 = new QRadioButton("Guess the Graph");
//    game_changer1 -> setStyleSheet("background-color: purple");
    game_changer2 = new QRadioButton("Guess the Zeroes");
//    game_changer2 -> setStyleSheet("background-color: purple");

    QGroupBox * groupBox1 = new QGroupBox ("Select Game");
    QVBoxLayout * game_choice_layout = new QVBoxLayout;
    game_choice_layout -> addWidget(game_changer1);
    game_choice_layout -> addWidget(game_changer2);

    groupBox1 -> setLayout(game_choice_layout);
    groupBox1 -> setStyleSheet("background-color: black;");

    firstPageLayout-> addWidget(welcome_label);
    firstPageLayout-> addWidget(instruction_label);
    firstPageLayout-> addWidget(poly_order);
    firstPageLayout-> addWidget(groupBox1);

    firstPageLayout-> addWidget(groupBox);

    firstPageLayout -> addWidget(page2PushButton);
    firstPageLayout -> addLayout(help_and_muteLayout);

// widget two - simple difficulty
    QWidget * simplePage = new QWidget;

    QLabel * livesLabel1 = new QLabel ("Lives Remaining");
    QFont f1 = livesLabel1 -> font();
    f1.setUnderline(true);
    livesLabel1 -> setFont(f1);
    livesLabel1 -> setAlignment(Qt::AlignCenter);
    livesLabel1 -> setStyleSheet("font: 30pt;");

    heart_pic_label_1_1 = new QLabel ;
    QPixmap heart_lives_picture_1_1 (":/img/img/heart3d.png");
    heart_pic_label_1_1 -> setPixmap( heart_lives_picture_1_1);
    heart_pic_label_1_1 -> setScaledContents(true);
    heart_pic_label_1_1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label_1_2 = new QLabel ;
    QPixmap heart_lives_picture_1_2 (":/img/img/heart3d.png");
    heart_pic_label_1_2 -> setPixmap( heart_lives_picture_1_2);
    heart_pic_label_1_2 -> setScaledContents(true);
    heart_pic_label_1_2 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label_1_3 = new QLabel ;
    QPixmap heart_lives_picture_1_3 (":/img/img/heart3d.png");
    heart_pic_label_1_3 -> setPixmap( heart_lives_picture_1_3);
    heart_pic_label_1_3 -> setScaledContents(true);
    heart_pic_label_1_3 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    page2_label = new QLabel;

    QLabel * guess_label1 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                      "\nPush 'Choose Graph' button once you've made your choice");

    guess_label1 -> setAlignment(Qt::AlignCenter);
    guess_label1 -> setStyleSheet("color: darkGreen;"
                "background-color: rgba(255, 255, 255, 200);");
    guess_button1 = new QPushButton("Choose Graph");

    QPushButton * page2ToHomeButton = new QPushButton ("Reset");
    QPushButton * page2MuteButton = new QPushButton("Mute music");
    QPushButton * page2UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout2 = new QHBoxLayout;
    mute_options_layout2 -> addWidget(page2MuteButton);
    mute_options_layout2 -> addWidget(page2UnmuteButton);

    SimplePageLayoutG = new QGridLayout(simplePage);

    page2_label -> setStyleSheet("font: 30pt;");

    SimplePageLayoutG -> addWidget(page2_label, 3, 6, 1, 3);
    SimplePageLayoutG -> addWidget(livesLabel1,0,6,1, 3 );
    SimplePageLayoutG -> addWidget(heart_pic_label_1_1, 1, 6);
    SimplePageLayoutG -> addWidget(heart_pic_label_1_2, 1, 7);
    SimplePageLayoutG -> addWidget(heart_pic_label_1_3, 1, 8);
    SimplePageLayoutG -> addWidget(guess_label1, 6,6,2, 3 );
    SimplePageLayoutG -> addWidget(guess_button1, 7, 2, 1, 4);
    SimplePageLayoutG -> addWidget(ui->graph1, 0, 0, 6, 6);
    SimplePageLayoutG -> addWidget(page2ToHomeButton, 6, 0, 1, 6);
    SimplePageLayoutG -> addLayout(mute_options_layout2, 7, 0, 1,2);

// widget three - intermediate
    QWidget * IntermediatePage= new QWidget;
    QLabel * livesLabel2 = new QLabel ("Lives Remaining");
    QFont f2 = livesLabel2 -> font();
    f2.setUnderline(true);
    livesLabel2-> setFont(f2);
    livesLabel2-> setAlignment(Qt::AlignCenter);
    livesLabel2-> setStyleSheet("font: 30pt;");
    IntermediatePageLayoutG = new QGridLayout(IntermediatePage);

    heart_pic_label_2_1 = new QLabel ;
    QPixmap heart_lives_picture_2_1 (":/img/img/heart3d.png");
    heart_pic_label_2_1 -> setPixmap( heart_lives_picture_2_1);
    heart_pic_label_2_1 -> setScaledContents(true);
    heart_pic_label_2_1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );
    heart_pic_label_2_2 = new QLabel ;
    QPixmap heart_lives_picture_2_2 (":/img/img/heart3d.png");
    heart_pic_label_2_2 -> setPixmap( heart_lives_picture_2_2);
    heart_pic_label_2_2 -> setScaledContents(true);
    heart_pic_label_2_2 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    page3_label = new QLabel;
    page3_label -> setStyleSheet("font: 30pt;");

    QLabel * guess_label2 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                      "\nPush 'Choose Graph' button once you've made your choice");

    guess_label2 -> setAlignment(Qt::AlignCenter);
    guess_label2 -> setStyleSheet("color: darkGreen;"
                "background-color: rgba(255, 255, 255, 200);");

    guess_button2 = new QPushButton("Choose Graph");

    QPushButton * page3ToHomeButton = new QPushButton ("Reset");
    QPushButton * page3MuteButton = new QPushButton("Mute music");
    QPushButton * page3UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout3 = new QHBoxLayout;
    mute_options_layout3 -> addWidget(page3MuteButton);
    mute_options_layout3 -> addWidget(page3UnmuteButton);

    IntermediatePageLayoutG -> addWidget(page3_label, 2, 6, 1, 3);
    IntermediatePageLayoutG -> addWidget(livesLabel2,0,6,1, 3 );
    IntermediatePageLayoutG -> addWidget(heart_pic_label_2_1, 1, 6);
    IntermediatePageLayoutG -> addWidget(heart_pic_label_2_2, 1, 7);
    IntermediatePageLayoutG -> addWidget(guess_label2, 5,6,2, 3 );
    IntermediatePageLayoutG -> addWidget(guess_button2, 7,2,1, 4);
    IntermediatePageLayoutG -> addWidget(ui->graph2, 0, 0, 6, 6);
    IntermediatePageLayoutG -> addWidget(page3ToHomeButton, 6, 0, 1, 6);
    IntermediatePageLayoutG -> addLayout(mute_options_layout3, 7, 0, 1, 2);

// widget four - difficult
    QWidget * DifficultPage = new QWidget;

    QLabel * livesLabel3 = new QLabel ("Lives Remaining");
    QFont f3 = livesLabel3 -> font();
    f3.setUnderline(true);
    livesLabel3-> setFont(f3);
    livesLabel3-> setAlignment(Qt::AlignCenter);
    livesLabel3-> setStyleSheet("font: 30pt;");
    DifficultPageLayoutG = new QGridLayout (DifficultPage);
    heart_pic_label_3_1 = new QLabel ;
    QPixmap heart_lives_picture_3_1 (":/img/img/heart3d.png");
    heart_pic_label_3_1 -> setPixmap( heart_lives_picture_3_1);
    heart_pic_label_3_1 -> setScaledContents(true);
    heart_pic_label_3_1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    page4_label = new QLabel;
    page4_label -> setStyleSheet("font: 30pt;");


    QLabel * guess_label3 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                      "\nPush 'Choose Graph' button once you've made your choice");
    guess_label3 -> setAlignment(Qt::AlignCenter);
    guess_label3 -> setStyleSheet("color: darkGreen;"
                "background-color: rgba(255, 255, 255, 200);");

    guess_button3 = new QPushButton("Choose Graph");

    QPushButton * page4ToHomeButton = new QPushButton ("Reset");
    QPushButton * page4MuteButton = new QPushButton("Mute music");
    QPushButton * page4UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout4 = new QHBoxLayout;
    mute_options_layout4 -> addWidget(page4MuteButton);
    mute_options_layout4 -> addWidget(page4UnmuteButton);

    DifficultPageLayoutG -> addWidget(page4_label, 3, 6, 1, 3);
    DifficultPageLayoutG -> addWidget(livesLabel3, 0, 6, 1, 3);
    DifficultPageLayoutG -> addWidget(heart_pic_label_3_1, 1, 6);
    DifficultPageLayoutG -> addWidget(guess_label3, 5,6,2, 3 );
    DifficultPageLayoutG -> addWidget(guess_button3, 7,2,1,4);
    DifficultPageLayoutG -> addWidget(ui->graph3, 0, 0, 6, 6);
    DifficultPageLayoutG -> addWidget(page4ToHomeButton, 6, 0, 1, 6);
    DifficultPageLayoutG -> addLayout(mute_options_layout4, 7, 0, 1, 2);

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

    QLabel * congrats_label1 = new QLabel ("<h1> Congratulations, you have beaten this difficulty!</h1> \nKeep going by pushing 'Continue'");
    congrats_label1 -> setAlignment(Qt::AlignCenter);

    next_levelButton = new QPushButton ("Continue");

    restart_and_exitLayout1 = new QHBoxLayout;
    QPushButton * restartButton1 = new QPushButton("Restart game");
    QPushButton * exitButton1 = new QPushButton("Exit game");

    restart_and_exitLayout1 -> addWidget(restartButton1);
    restart_and_exitLayout1 -> addWidget(exitButton1);

    winPageLayout = new QGridLayout(winPage);
    winPageLayout -> addWidget(congrats_label1, 1, 0);
    winPageLayout -> addWidget(next_levelButton, 2,0 );
    winPageLayout -> addLayout(restart_and_exitLayout1, 3,0 );


// widget seven - out of lives page
    QWidget * losePage = new QWidget;
    QLabel * lose_label = new QLabel ("<h1>Sorry, you lost.");
    lose_label -> setAlignment(Qt::AlignCenter);

    lose_info_label = new QLabel ;
    lose_info_label -> setAlignment(Qt::AlignCenter);
    lose_info_label -> setStyleSheet("font: 30px;");

    restart_and_exitLayout2 = new QHBoxLayout;
    QPushButton * restartButton2 = new QPushButton("Restart game");
    QPushButton * exitButton2 = new QPushButton("Exit game");

    restart_and_exitLayout2 -> addWidget(restartButton2);
    restart_and_exitLayout2 -> addWidget(exitButton2);

    losePageLayout = new QGridLayout(losePage);
    losePageLayout -> addWidget(lose_label,0,0);
    losePageLayout -> addWidget(lose_info_label, 1, 0);
    losePageLayout -> addLayout(restart_and_exitLayout2, 2,0);

// widget eight - final win page
    QWidget * finalwinPage = new QWidget;

    QLabel * congrats_label2 = new QLabel ("<h1> Congratulations, you won!</h1>");
    congrats_label2 -> setAlignment(Qt::AlignCenter);

    QPushButton * next_degreeButton = new QPushButton ("Play again with Higher Degree");

    restart_and_exitLayout3 = new QHBoxLayout;
    QPushButton * restartButton3 = new QPushButton("Restart game");
    QPushButton * exitButton3 = new QPushButton("Exit game");

    restart_and_exitLayout3 -> addWidget(restartButton3);
    restart_and_exitLayout3 -> addWidget(exitButton3);

    finalwinPageLayout = new QGridLayout(finalwinPage);
    finalwinPageLayout -> addWidget(congrats_label2, 1, 0);
    finalwinPageLayout -> addWidget(next_degreeButton, 2, 0);
    finalwinPageLayout -> addLayout(restart_and_exitLayout3, 3,0 );


// widget 9 - guess zero page
    QWidget * guesszeroPage_S = new QWidget;

    QLabel * livesLabel4 = new QLabel ("Lives Remaining");
    QFont f4 = livesLabel4 -> font();
    f4.setUnderline(true);
    livesLabel4 -> setFont(f4);
    livesLabel4 -> setAlignment(Qt::AlignCenter);
    livesLabel4 -> setStyleSheet("font: 30pt;");

    heart_pic_label_4_1 = new QLabel ;
    QPixmap heart_lives_picture_4_1 (":/img/img/heart3d.png");
    heart_pic_label_4_1 -> setPixmap( heart_lives_picture_4_1);
    heart_pic_label_4_1 -> setScaledContents(true);
    heart_pic_label_4_1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label_4_2= new QLabel ;
    QPixmap heart_lives_picture_4_2 (":/img/img/heart3d.png");
    heart_pic_label_4_2 -> setPixmap( heart_lives_picture_4_2);
    heart_pic_label_4_2 -> setScaledContents(true);
    heart_pic_label_4_2 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label_4_3 = new QLabel ;
    QPixmap heart_lives_picture_4_3 (":/img/img/heart3d.png");
    heart_pic_label_4_3 -> setPixmap( heart_lives_picture_4_3);
    heart_pic_label_4_3 -> setScaledContents(true);
    heart_pic_label_4_3 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    QLineEdit * number_of_zeroes_input1 = new QLineEdit();
    number_of_zeroes_input1->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);

    QPushButton * page9ToHomeButton = new QPushButton ("Reset");
    QPushButton * page9MuteButton = new QPushButton("Mute music");
    QPushButton * page9UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout9 = new QHBoxLayout;
    mute_options_layout9 -> addWidget(page9MuteButton);
    mute_options_layout9 -> addWidget(page9UnmuteButton);

    SimplePageLayoutZ = new QGridLayout(guesszeroPage_S);

    SimplePageLayoutZ -> addWidget(ui->graph4, 0, 0, 6, 6);
    SimplePageLayoutZ -> addWidget(livesLabel4, 0, 6, 1, 3);
    SimplePageLayoutZ -> addWidget(heart_pic_label_4_1, 1, 6);
    SimplePageLayoutZ -> addWidget(heart_pic_label_4_2, 1, 7);
    SimplePageLayoutZ -> addWidget(heart_pic_label_4_3, 1, 8);
    SimplePageLayoutZ -> addWidget(number_of_zeroes_input1, 2, 7, 1, 1);

    SimplePageLayoutZ -> addWidget(page9ToHomeButton, 6, 0, 1, 6);
    SimplePageLayoutZ -> addLayout(mute_options_layout9, 7, 0, 1, 2);



// widget 10 - guess zero page
    QWidget * guesszeroPage_I = new QWidget;

    QLabel * livesLabel5 = new QLabel ("Lives Remaining");
    QFont f5 = livesLabel5 -> font();
    f5.setUnderline(true);
    livesLabel5 -> setFont(f5);
    livesLabel5 -> setAlignment(Qt::AlignCenter);
    livesLabel5 -> setStyleSheet("font: 30pt;");

    heart_pic_label_5_1 = new QLabel ;
    QPixmap heart_lives_picture_5_1 (":/img/img/heart3d.png");
    heart_pic_label_5_1 -> setPixmap( heart_lives_picture_5_1);
    heart_pic_label_5_1 -> setScaledContents(true);
    heart_pic_label_5_1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    heart_pic_label_5_2= new QLabel ;
    QPixmap heart_lives_picture_5_2 (":/img/img/heart3d.png");
    heart_pic_label_5_2 -> setPixmap( heart_lives_picture_5_2);
    heart_pic_label_5_2 -> setScaledContents(true);
    heart_pic_label_5_2 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    QPushButton * page10ToHomeButton = new QPushButton ("Reset");
    QPushButton * page10MuteButton = new QPushButton("Mute music");
    QPushButton * page10UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout10 = new QHBoxLayout;
    mute_options_layout10 -> addWidget(page9MuteButton);
    mute_options_layout10 -> addWidget(page9UnmuteButton);

    QLineEdit * number_of_zeroes_input2 = new QLineEdit();
    number_of_zeroes_input2->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);

    IntermediatePageLayoutZ = new QGridLayout(guesszeroPage_I);

    IntermediatePageLayoutZ -> addWidget(ui->graph5, 0, 0, 6, 6);
    IntermediatePageLayoutZ -> addWidget(livesLabel5, 0, 6, 1, 3);
    IntermediatePageLayoutZ -> addWidget(heart_pic_label_5_1, 1, 6);
    IntermediatePageLayoutZ -> addWidget(heart_pic_label_5_2, 1, 7);
    IntermediatePageLayoutZ -> addWidget(number_of_zeroes_input2, 2, 7, 1, 1);
    IntermediatePageLayoutZ -> addWidget(page10ToHomeButton, 6, 0, 1, 6);
    IntermediatePageLayoutZ -> addLayout(mute_options_layout10, 7, 0, 1, 2);


// widget 11 - guess zero page
    QWidget * guesszeroPage_D = new QWidget;

    QLabel * livesLabel6 = new QLabel ("Lives Remaining");
    QFont f6 = livesLabel6 -> font();
    f6.setUnderline(true);
    livesLabel6 -> setFont(f6);
    livesLabel6 -> setAlignment(Qt::AlignCenter);
    livesLabel6 -> setStyleSheet("font: 30pt;");

    heart_pic_label_6_1 = new QLabel ;
    QPixmap heart_lives_picture_6_1 (":/img/img/heart3d.png");
    heart_pic_label_6_1 -> setPixmap( heart_lives_picture_6_1);
    heart_pic_label_6_1 -> setScaledContents(true);
    heart_pic_label_6_1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    QPushButton * page11ToHomeButton = new QPushButton ("Reset");
    QPushButton * page11MuteButton = new QPushButton("Mute music");
    QPushButton * page11UnmuteButton = new QPushButton ("Unmute music");

    QHBoxLayout * mute_options_layout11 = new QHBoxLayout;
    mute_options_layout11 -> addWidget(page9MuteButton);
    mute_options_layout11 -> addWidget(page9UnmuteButton);

    QLineEdit * number_of_zeroes_input3 = new QLineEdit();
    number_of_zeroes_input3->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);

    DifficultPageLayoutZ = new QGridLayout(guesszeroPage_D);

    DifficultPageLayoutZ -> addWidget(ui->graph6, 0, 0, 6, 6);
    DifficultPageLayoutZ -> addWidget(livesLabel6, 0, 6, 1, 3);
    DifficultPageLayoutZ -> addWidget(heart_pic_label_6_1, 1, 6);
    DifficultPageLayoutZ -> addWidget(number_of_zeroes_input3, 2, 7, 1, 1);
    DifficultPageLayoutZ -> addWidget(page11ToHomeButton, 6, 0, 1, 6);
    DifficultPageLayoutZ -> addLayout(mute_options_layout11, 7, 0, 1, 2);

// stack
    _stackedWidget = new QStackedWidget;
    _stackedWidget -> addWidget(firstPage);
    _stackedWidget -> addWidget(simplePage);
    _stackedWidget -> addWidget(IntermediatePage);
    _stackedWidget -> addWidget(DifficultPage);
    _stackedWidget -> addWidget(helpPage);
    _stackedWidget -> addWidget(winPage);
    _stackedWidget -> addWidget(losePage);
    _stackedWidget -> addWidget(finalwinPage);
    _stackedWidget -> addWidget(guesszeroPage_S);
    _stackedWidget -> addWidget(guesszeroPage_I);
    _stackedWidget -> addWidget(guesszeroPage_D);


// layout
    QVBoxLayout * centrallayout = new QVBoxLayout;
    centrallayout -> addWidget(_stackedWidget);
    setLayout(centrallayout);

// connect push button
    // page 2 varies on selected difficulty
    connect(page2PushButton, SIGNAL(clicked()), this , SLOT(goToPage2()));
    connect(helpToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(homeToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));

    connect(page2ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(page3ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(page4ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));

    connect(page9ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(page10ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(page11ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));

    connect (MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page2MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page3MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page4MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page9MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page10MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page11MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));

    connect(UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));
    connect(page2UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));
    connect(page3UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));
    connect(page4UnmuteButton, SIGNAL(clicked()), this, SLOT(unMuteMedia()));
    connect (page9UnmuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page10UnmuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
    connect (page11UnmuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));

    // graph interaction

    connect(guess_button1, SIGNAL(clicked()), this, SLOT(graph_clicked1()));
    connect(guess_button2, SIGNAL(clicked()), this, SLOT(graph_clicked2()));
    connect(guess_button3, SIGNAL(clicked()), this, SLOT(graph_clicked3()));

    //post-game connections
    connect(restartButton1, SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(restartButton2, SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(restartButton3, SIGNAL(clicked()), this, SLOT(goToHome()));
    connect(exitButton1,SIGNAL(clicked()), this, SLOT(ExitGame()));
    connect(exitButton2,SIGNAL(clicked()), this, SLOT(ExitGame()));
    connect(exitButton3,SIGNAL(clicked()), this, SLOT(ExitGame()));

    connect(next_levelButton, SIGNAL(clicked()), this, SLOT(goToPage2()));
    connect(next_degreeButton, SIGNAL(clicked()), this, SLOT(higherdegreeGame()));

}

void Dialog::goToPage2(){

    hearts = {1, 2, 3};
    polynomial_order = poly_order -> value();


    if(game_changer2 -> isChecked() && diff_1 -> isChecked()){
        _stackedWidget -> setCurrentIndex(8);
        graph = new Function(polynomial_order, "simple");

        ui -> graph4 -> setInteraction(QCP::iSelectPlottables);
        ui -> graph4 -> addGraph();
        ui -> graph4 -> graph(0) -> setData(graph -> getX(), graph -> getY());
        ui -> graph4 ->xAxis->setLabel("x");
        ui -> graph4 ->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui->graph4->xAxis->setRange(-20, 20);
        ui->graph4->yAxis->setRange(-50, 50);
        ui -> graph4 -> replot();
    }

    if(game_changer2 -> isChecked() && diff_2 -> isChecked()){
        _stackedWidget -> setCurrentIndex(9);
        graph = new Function(polynomial_order, "intermediate");

        ui -> graph5 -> setInteraction(QCP::iSelectPlottables);
        ui -> graph5 -> addGraph();
        ui -> graph5 -> graph(0) -> setData(graph -> getX(), graph -> getY());
        ui -> graph5 ->xAxis->setLabel("x");
        ui -> graph5 ->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui -> graph5->xAxis->setRange(-20, 20);
        ui -> graph5->yAxis->setRange(-50, 50);
        ui -> graph5 -> replot();
    }

    if(game_changer2 -> isChecked() && diff_3 -> isChecked()){
        _stackedWidget -> setCurrentIndex(10);
        graph = new Function(polynomial_order, "difficult");

        ui -> graph6 -> setInteraction(QCP::iSelectPlottables);
        ui -> graph6 -> addGraph();
        ui -> graph6 -> graph(0) -> setData(graph -> getX(), graph -> getY());
        ui -> graph6 ->xAxis->setLabel("x");
        ui -> graph6 ->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
        ui->graph6->xAxis->setRange(-20, 20);
        ui->graph6->yAxis->setRange(-50, 50);

        ui -> graph6 -> replot();

    }

    //easy
    if(game_changer1 -> isChecked() && diff_1 ->isChecked()){

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


       //lose page label text is set
       std::stringstream info_reader;
       info_reader << "Your Function: ";
       graph -> printFunc(info_reader);
       info_reader << "\n\n";
       graph -> printInfo(info_reader);
       std::string info_string = info_reader.str();
       lose_info_label -> setText(QString::fromUtf8(info_string.c_str()));

       // read function into stringstream from print function
       std::stringstream func_reader;
       func_reader << "Function:\n";
       graph -> printFunc(func_reader); // func_reader now holds output from print function
       func_reader << "\n\nZero:\n";
       func_reader << std::to_string(graph -> getZero());

       std::string s = func_reader.str(); // string is given all stringstream content
       page2_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

       // real graph

       ui -> graph1 -> setInteraction(QCP::iSelectPlottables);

       ui -> graph1 ->addGraph();
       ui -> graph1 -> graph(0) -> setData(graph -> getX(), graph -> getY());
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
    if(game_changer1 -> isChecked() && diff_2 ->isChecked()){
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

      //lose page label text is set
      std::stringstream info_reader;
      info_reader << "Your Function: ";
      graph -> printFunc(info_reader);
      info_reader << "\n\n";
      graph -> printInfo(info_reader);
      std::string info_string = info_reader.str();
      lose_info_label -> setText(QString::fromUtf8(info_string.c_str()));

      // read function into stringstream from print function
      std::stringstream func_reader;
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
    if(game_changer1 -> isChecked() && diff_3 ->isChecked()){
        polynomial_order = poly_order ->value();

        //rand here
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

        //lose page label text is set
        std::stringstream info_reader;
        info_reader << "Your Function: ";
        graph -> printFunc(info_reader);
        info_reader << "\n\n";
        graph -> printInfo(info_reader);
        std::string info_string = info_reader.str();
        lose_info_label -> setText(QString::fromUtf8(info_string.c_str()));

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

//    if(game_changer2 -> isChecked()){
//        if(diff_1->isChecked()){
//            qDebug() << "stacked widget - 8";
//            _stackedWidget -> setCurrentIndex(8);
//        }

//        if(diff_2->isChecked()){
//            qDebug() << "stacked widget - 9";

//            _stackedWidget -> setCurrentIndex(9);
//        }

//        if(diff_3->isChecked()){
//            qDebug() << "stacked widget - 10";

//            _stackedWidget -> setCurrentIndex(10);
//        }
//    }
}

void Dialog::goToHome(){


    _stackedWidget -> setCurrentIndex(0);

    // resets hidden hearts
    heart_pic_label_1_1 -> setVisible(true);
    heart_pic_label_1_2 -> setVisible(true);
    heart_pic_label_1_3 -> setVisible(true);
    heart_pic_label_2_1 -> setVisible(true);
    heart_pic_label_2_2 -> setVisible(true);
    heart_pic_label_3_1 -> setVisible(true);
    hearts = {1,2,3};

    //
    diff_1->setAutoExclusive(false);
    diff_1->setChecked(false);
    diff_1->setAutoExclusive(true);

    diff_2->setAutoExclusive(false);
    diff_2->setChecked(false);
    diff_2->setAutoExclusive(true);

    diff_3->setAutoExclusive(false);
    diff_3->setChecked(false);
    diff_3->setAutoExclusive(true);


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

        if(!selected_right_graph && hearts.size()==3 && graphs_list.size() != 0){
            qDebug() << "no graph removed - clicked on wrong graph - 3";
            heart_pic_label_1_3 -> setVisible(false);
            qDebug() << "heart removed from heart_layout";
            hearts.pop_back();
            qDebug() << "vector size updated";

           // get graphs to deselect
            qDebug() << "graphs deselected";

            continuing_to_guess_wrong =false;
            qDebug() << "bool set false ";
        }

        else if(!selected_right_graph && hearts.size()==2){
            qDebug() << " no graph removed - clicked on wrong graph - 2\n";
            heart_pic_label_1_2 -> setVisible(false);
            qDebug() << "heart removed from heart_layout\n";
            hearts.pop_back();
            qDebug() << "vector size updated";

            ui -> graph1 ->deselectAll();
            qDebug() << "graphs deselected";
            continuing_to_guess_wrong =false;
        }

        else if(!selected_right_graph && hearts.size()==1){
            qDebug() << " no graph removed - clicked on wrong graph - 1\n";
            heart_pic_label_1_1 -> setVisible(false);
            qDebug() << "heart removed from heart_layout\n";
            hearts.pop_back();
            qDebug() << "vector size updated";

            ui -> graph1 ->deselectAll();
            qDebug() << "graphs deselected";
            _stackedWidget -> setCurrentIndex(6);
            continuing_to_guess_wrong =false;
        }

        if(selected_right_graph){
            qDebug() << "right graph selected";

            ui -> graph1 -> removeGraph(0);
            qDebug() << "real graph removed";
            ui -> graph1 -> replot();
            qDebug() << "replotted";

            diff_1->setAutoExclusive(false);
            diff_1->setChecked(false);
            diff_1->setAutoExclusive(true);

            diff_2 -> setChecked(true);
            _stackedWidget -> setCurrentIndex(5);
            continuing_to_guess_wrong =false;
        }
        continuing_to_guess_wrong = false;
  }

}

void Dialog::graph_clicked2(){

    qDebug() << "graph click registered";

        bool continuing_to_guess_wrong = true;

        graphs_list = ui -> graph2 -> selectedGraphs();

        qDebug() << "list of graphs initialized";

        bool selected_right_graph = graphs_list.contains(ui -> graph2 -> graph(0));

        while(continuing_to_guess_wrong){

            if(!selected_right_graph && hearts.size()==3 && graphs_list.size() != 0){
                qDebug() << "no graph removed - clicked on wrong graph - 3";
                heart_pic_label_2_2 -> setVisible(false);
                qDebug() << "heart removed from heart_layout";
                hearts.pop_back();
                qDebug() << "vector size updated";
                continuing_to_guess_wrong =false;
                qDebug() << "bool set false ";
            }

            else if(!selected_right_graph && hearts.size()==2&& graphs_list.size() != 0){
                qDebug() << " no graph removed - clicked on wrong graph - 2\n";
                heart_pic_label_2_1 -> setVisible(false);
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

                diff_2 ->setAutoExclusive(false);
                diff_2 ->setChecked(false);
                diff_2 ->setAutoExclusive(true);

                diff_3 -> setChecked(true);

                _stackedWidget -> setCurrentIndex(5);
                continuing_to_guess_wrong =false;
            }
            continuing_to_guess_wrong = false;
      }

    }

void Dialog::graph_clicked3(){
    qDebug() << "graph click registered";

        bool continuing_to_guess_wrong = true;

        hearts = {1, 2, 3};

        graphs_list = ui -> graph3 -> selectedGraphs();

        qDebug() << "list of graphs initialized";

        bool selected_right_graph = graphs_list.contains(ui -> graph3 -> graph(0));

        while(continuing_to_guess_wrong){

            if(!selected_right_graph && hearts.size()==3  && graphs_list.size() != 0){
                qDebug() << "no graph removed - clicked on wrong graph - 3";
                heart_pic_label_3_1 -> setVisible(false);
                qDebug() << "heart removed from heart_layout";
                hearts.pop_back();
                qDebug() << "vector size updated";
                _stackedWidget -> setCurrentIndex(6);
                continuing_to_guess_wrong =false;
                qDebug() << "bool set false ";
            }

            if(selected_right_graph){

                qDebug() << "right graph selected";

                ui -> graph3 -> removeGraph(0);
                qDebug() << "real graph removed";
                ui -> graph3 -> replot();
                qDebug() << "replotted";


                // final win page
                _stackedWidget -> setCurrentIndex(7);
                continuing_to_guess_wrong =false;
            }
            continuing_to_guess_wrong = false;

      }
}

void Dialog::ExitGame(){
    exit(1);
}

// should be paired with spinbox to set the degree of next game called
void Dialog::higherdegreeGame(){
    polynomial_order = polynomial_order + 1;

}

Dialog::~Dialog()
{
    delete ui;
}
