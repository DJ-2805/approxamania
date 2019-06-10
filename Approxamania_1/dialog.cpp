#include "dialog.h"
#include "ui_dialog.h"
#include "Function.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
// ****************************************
// General Setup
// ****************************************
    // set user interface file
        ui ->setupUi(this);

    // set fixed window size
        this -> setFixedSize(1250,750);

    //initialize song
        music = new QMediaPlayer();

    // set QMediaPlayer file
        music->setMedia(QUrl("qrc:/img/img/Waves.mp3"));

    // play music
        music->play();

    //background
        QPixmap background_picture (":/img/img/bluegrid.jpg");
        background_picture = background_picture.scaled(this ->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, background_picture);
        this->setPalette(palette);

    //title
        this -> setWindowTitle("Approxamania");

// ****************************************
// Starting Page
// ****************************************
    QWidget * firstPage = new QWidget;

    // welcome label
        QLabel * welcome_label = new QLabel ("<h5>Welcome to</h5> <h2>Approxamania</h2>");
        welcome_label ->setAlignment(Qt::AlignCenter);
        welcome_label -> setStyleSheet("font: 80pt;"
                                       "color: darkMagenta;"
                                       "background-color: rgba(255, 255, 255, 150);");

    // basic instructions set in center
    // user can find further instruction on help page if needed
        QLabel * instruction_label = new QLabel ("<h3>Select the power of the polynomial you'd like to approximate.</h3>"
                                                 "\n<h4>Once you've chosen a degree and a difficulty, <font color=\"green\">'Graph Polynomial'</font> will generate polynomials of different degrees with randonmly generated coeffecients: </h4>");
        instruction_label -> setAlignment(Qt::AlignCenter);

    // initialize Spin box
        poly_order = new QSpinBox;
        // set range to all degrees we allow to graph
        poly_order -> setRange(1,4);

    // initialize Radio buttons for difficulty
        diff_1 = new QRadioButton("Simple");
        diff_1 -> setStyleSheet("background-color: black");
        diff_2 = new QRadioButton("Intermediate");
        diff_2 -> setStyleSheet("background-color: black");
        diff_3 = new QRadioButton("Difficult");
        diff_3 -> setStyleSheet("background-color: black");

    // Initialize all other buttons on page
        QPushButton * page2PushButton = new QPushButton("Graph Polynomial");
        QPushButton * homeToHelpButton = new QPushButton("Help");
        QPushButton * MuteButton = new QPushButton ("Mute music");
        QPushButton * UnmuteButton = new QPushButton ("Unmute music");

    // initialize layout that will hold mute/unmute buttons
        QHBoxLayout * mute_options_layout = new QHBoxLayout;
        mute_options_layout -> addWidget(MuteButton);
        mute_options_layout -> addWidget(UnmuteButton);

    // initialize layout that will hold help and an addition layout for mute options
        QHBoxLayout * help_and_muteLayout = new QHBoxLayout;
        help_and_muteLayout -> addWidget(homeToHelpButton);
        help_and_muteLayout -> addLayout(mute_options_layout);

    // initialize layout that will hold entire starting screen window
        QVBoxLayout *firstPageLayout = new QVBoxLayout(firstPage);

    // initialize layout that will hold axes hider button
        QHBoxLayout * axis_hiderLayout = new QHBoxLayout;
        hide_axis = new QCheckBox("Hide axes (for added difficulty)");
        hide_axis -> setStyleSheet("background-color: purple");
        axis_hiderLayout -> addWidget(hide_axis);

    // insert all widgets into layout
        firstPageLayout-> addWidget(welcome_label);
        firstPageLayout-> addWidget(instruction_label);
        firstPageLayout-> addWidget(poly_order);
        firstPageLayout-> addWidget(diff_1);
        firstPageLayout-> addWidget(diff_2);
        firstPageLayout-> addWidget(diff_3);
        firstPageLayout -> addLayout(axis_hiderLayout);
        firstPageLayout -> addWidget(page2PushButton);
        firstPageLayout -> addLayout(help_and_muteLayout);

        polynomial_order = poly_order -> value();

// ****************************************
// 'simple' difficulty
// ****************************************
    QWidget * simplePage = new QWidget;

    // initialize the page layout with the page widget
        SimplePageLayout = new QGridLayout(simplePage);

    // underlined 'Lives Remaining' label to be placed right above hearts
        QLabel * livesLabel1 = new QLabel ("Lives Remaining");
        QFont f1 = livesLabel1 -> font();
        f1.setUnderline(true);
        livesLabel1 -> setFont(f1);
        livesLabel1 -> setAlignment(Qt::AlignCenter);
        livesLabel1 -> setStyleSheet("font: 30pt;");

    // initialize QLabel's that will contain heart pictures that represent lives the user has
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

    // initialize label whose text will be set at run time
    // will contain the function and its zero printed out
        page2_label = new QLabel;
        page2_label -> setStyleSheet("font: 30pt;");

    //initialize label whose text will be set at run time
    // will contain the current difficulty
        difficulty_label1 = new QLabel;
        difficulty_label1 -> setAlignment(Qt::AlignCenter);
        difficulty_label1 -> setStyleSheet("font: 35pt");

    // initialize label to instruct user how to submit their guess
        QLabel * guess_label1 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                          "\nPush 'Choose Graph' button once you've made your choice");
        guess_label1 -> setAlignment(Qt::AlignCenter);
        guess_label1 -> setStyleSheet("color: darkGreen;"
                    "background-color: rgba(255, 255, 255, 200);");

    // initialize buttons on page
        guess_button1 = new QPushButton("Choose Graph");
        QPushButton * page2ToHomeButton = new QPushButton ("Reset");
        QPushButton * page2MuteButton = new QPushButton("Mute music");
        QPushButton * page2UnmuteButton = new QPushButton ("Unmute music");

    // initialize layout that will hold mute/unmute buttons
        QHBoxLayout * mute_options_layout2 = new QHBoxLayout;
        mute_options_layout2 -> addWidget(page2MuteButton);
        mute_options_layout2 -> addWidget(page2UnmuteButton);

    // insert all widgets into page layout
        SimplePageLayout -> addWidget(page2_label, 3, 6, 1, 3);
        SimplePageLayout -> addWidget(livesLabel1,0,6,1, 3 );
        SimplePageLayout -> addWidget(heart_pic_label11, 1, 6);
        SimplePageLayout -> addWidget(heart_pic_label21, 1, 7);
        SimplePageLayout -> addWidget(heart_pic_label31, 1, 8);
        SimplePageLayout -> addWidget(difficulty_label1, 5, 6, 2, 3);
        SimplePageLayout -> addWidget(guess_label1, 6,6,2, 3 );
        SimplePageLayout -> addWidget(guess_button1, 7, 2, 1, 4);
        SimplePageLayout -> addWidget(ui->graph1, 0, 0, 6, 6);
        SimplePageLayout -> addWidget(page2ToHomeButton, 6, 0, 1, 6);
        SimplePageLayout -> addLayout(mute_options_layout2, 7, 0, 1,2);

// ****************************************
// 'intermediate' difficulty
// ****************************************
    QWidget * IntermediatePage= new QWidget;

    // initialize the page layout with the page widget
        IntermediatePageLayout = new QGridLayout(IntermediatePage);

    // underlined 'Lives Remaining' label to be placed right above hearts
        QLabel * livesLabel2 = new QLabel ("Lives Remaining");
        QFont f2 = livesLabel2 -> font();
        f2.setUnderline(true);
        livesLabel2-> setFont(f1);
        livesLabel2-> setAlignment(Qt::AlignCenter);
        livesLabel2-> setStyleSheet("font: 30pt;");

    // initialize QLabel's that will contain heart pictures that represent lives the user has
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

    // initialize label whose text will be set at run time
    // will contain the function and its zero printed out
        page3_label = new QLabel;
        page3_label -> setStyleSheet("font: 30pt;");

    // initialize label whose text will be set at run time
    // will contain the current difficulty
        difficulty_label2 = new QLabel;
        difficulty_label2 -> setAlignment(Qt::AlignCenter);
        difficulty_label2 -> setStyleSheet("font: 35pt");

    // initialize label to instruct user how to submit their guess
        QLabel * guess_label2 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                          "\nPush 'Choose Graph' button once you've made your choice");
        guess_label2 -> setAlignment(Qt::AlignCenter);
        guess_label2 -> setStyleSheet("color: darkGreen;"
                    "background-color: rgba(255, 255, 255, 200);");

    // initialize buttons on page
        guess_button2 = new QPushButton("Choose Graph");
        QPushButton * page3ToHomeButton = new QPushButton ("Reset");
        QPushButton * page3MuteButton = new QPushButton("Mute music");
        QPushButton * page3UnmuteButton = new QPushButton ("Unmute music");

    // initialize layout that will hold mute/unmute buttons
        QHBoxLayout * mute_options_layout3 = new QHBoxLayout;
        mute_options_layout3 -> addWidget(page3MuteButton);
        mute_options_layout3 -> addWidget(page3UnmuteButton);

    // insert all widgets into page layout
        IntermediatePageLayout -> addWidget(page3_label, 2, 6, 1, 3);
        IntermediatePageLayout -> addWidget(livesLabel2,0,6,1, 3 );
        IntermediatePageLayout -> addWidget(heart_pic_label12, 1, 6);
        IntermediatePageLayout -> addWidget(heart_pic_label22, 1, 7);
        IntermediatePageLayout -> addWidget(difficulty_label2, 5, 6, 2, 3);
        IntermediatePageLayout -> addWidget(guess_label2, 6,6,2, 3 );
        IntermediatePageLayout -> addWidget(guess_button2, 7,2,1, 4);
        IntermediatePageLayout -> addWidget(ui->graph2, 0, 0, 6, 6);
        IntermediatePageLayout -> addWidget(page3ToHomeButton, 6, 0, 1, 6);
        IntermediatePageLayout -> addLayout(mute_options_layout3, 7, 0, 1, 2);

// ****************************************
// 'difficult' difficulty
// ****************************************
    QWidget * DifficultPage = new QWidget;

    // initialize the page layout with the page widget
        DifficultPageLayout = new QGridLayout (DifficultPage);

    // underlined 'Lives Remaining' label to be placed right above hearts
        QLabel * livesLabel3 = new QLabel ("Lives Remaining");
        QFont f3 = livesLabel3 -> font();
        f3.setUnderline(true);
        livesLabel3-> setFont(f3);
        livesLabel3-> setAlignment(Qt::AlignCenter);
        livesLabel3-> setStyleSheet("font: 30pt;");

    // initialize QLabel that will contain heart picture that represents the single life the user has
        heart_pic_label13 = new QLabel ;
        QPixmap heart_lives_picture13 (":/img/img/heart3d.png");
        heart_pic_label13 -> setPixmap( heart_lives_picture1);
        heart_pic_label13 -> setScaledContents(true);
        heart_pic_label13 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    // initialize label whose text will be set at run time
    // will contain the function and its zero printed out
        page4_label = new QLabel;
        page4_label -> setStyleSheet("font: 30pt;");

    // initialize label whose text will be set at run time
    // will contain the current difficulty
        difficulty_label3 = new QLabel;
        difficulty_label3 -> setAlignment(Qt::AlignCenter);
        difficulty_label3 -> setStyleSheet("font: 35pt");

    // initialize label to instruct user how to submit their guess
        QLabel * guess_label3 = new QLabel("<h3>Click on the graph you believe to represent your polynomial</h3>"
                                          "\nPush 'Choose Graph' button once you've made your choice");
        guess_label3 -> setAlignment(Qt::AlignCenter);
        guess_label3 -> setStyleSheet("color: darkGreen;"
                    "background-color: rgba(255, 255, 255, 200);");

    // initialize buttons on page
        guess_button3 = new QPushButton("Choose Graph");
        QPushButton * page4ToHomeButton = new QPushButton ("Reset");
        QPushButton * page4MuteButton = new QPushButton("Mute music");
        QPushButton * page4UnmuteButton = new QPushButton ("Unmute music");

    // initialize layout that will hold mute/unmute buttons
        QHBoxLayout * mute_options_layout4 = new QHBoxLayout;
        mute_options_layout4 -> addWidget(page4MuteButton);
        mute_options_layout4 -> addWidget(page4UnmuteButton);

    // insert all widgets into page layout
        DifficultPageLayout -> addWidget(page4_label, 3, 6, 1, 3);
        DifficultPageLayout -> addWidget(livesLabel3, 0, 6, 1, 3);
        DifficultPageLayout -> addWidget(heart_pic_label13, 1, 6);
        DifficultPageLayout -> addWidget(difficulty_label3, 5, 6, 2, 3);
        DifficultPageLayout -> addWidget(guess_label3, 6,6,2, 3 );
        DifficultPageLayout -> addWidget(guess_button3, 7,2,1,4);
        DifficultPageLayout -> addWidget(ui->graph3, 0, 0, 6, 6);
        DifficultPageLayout -> addWidget(page4ToHomeButton, 6, 0, 1, 6);
        DifficultPageLayout -> addLayout(mute_options_layout4, 7, 0, 1, 2);

// ****************************************
// Help Page / Instructions
// ****************************************
    QWidget * helpPage = new QWidget;

    // initialize page layout with the page widget
        QGridLayout * helpPageLayout = new QGridLayout(helpPage);

    // Header label
        QLabel * helpPage_label = new QLabel ("Help Page");
        helpPage_label -> setStyleSheet("font: 50pt;");
        helpPage_label -> setAlignment(Qt::AlignCenter);

    // Widget to serve as container for multiple QLabel widgets
    // Done this way in order to set a background color for the entire block of text
        QWidget * helpPage_text_container = new QWidget;
        helpPage_text_container -> setStyleSheet("background-color: rgba(0, 0, 0, 200);");
        QVBoxLayout * helpPage_text = new QVBoxLayout(helpPage_text_container);

        // labels initalized with text
        // all background colors changed to a transparent color
        QLabel * helpPage_descript1 = new QLabel ("Approxamania is an educational game of guessing. The user must first enter the power");
            helpPage_descript1 -> setAlignment(Qt::AlignCenter);
            helpPage_descript1 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript2 = new QLabel ("of the polynomial they would like to graph (between 1 and 4):");
            helpPage_descript2 -> setAlignment(Qt::AlignCenter);
            helpPage_descript2 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript3 = new QLabel ("- 1 being a linear function of the form f(x) = ax + b");
            helpPage_descript3 -> setAlignment(Qt::AlignCenter);
            helpPage_descript3 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript4 = new QLabel ("- 4 being a polynomial of the form f(x) = ax<sup>4</sup>+bx<sup>3</sup>+cx<sup>2</sup>+dx+e");
            helpPage_descript4 -> setAlignment(Qt::AlignCenter);
            helpPage_descript4 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript5 = new QLabel ("After choosing a power, the user then selects a difficulty which dictates how");
            helpPage_descript5 -> setAlignment(Qt::AlignCenter);
            helpPage_descript5 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript6 = new QLabel ("many graphs will be plotted and alongside the one they chose.");
            helpPage_descript6 -> setAlignment(Qt::AlignCenter);
            helpPage_descript6 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript7 = new QLabel ("The goal of the user is to select the curve they chose before running out lives.");
            helpPage_descript7 -> setAlignment(Qt::AlignCenter);
            helpPage_descript7 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript8 = new QLabel ("Each incorrect guess will cost them a life, but will also delete a curve off the plot.");
            helpPage_descript8 -> setAlignment(Qt::AlignCenter);
            helpPage_descript8 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        QLabel * helpPage_descript9 = new QLabel ("Through this process the user will be aquainted with different power polynomials and learn their patterns.");
            helpPage_descript9 -> setAlignment(Qt::AlignCenter);
            helpPage_descript9 -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");

        // labels inserted into layout
        helpPage_text -> addWidget(helpPage_descript1);
        helpPage_text -> addWidget(helpPage_descript2);
        helpPage_text -> addWidget(helpPage_descript3);
        helpPage_text -> addWidget(helpPage_descript4);
        helpPage_text -> addWidget(helpPage_descript5);
        helpPage_text -> addWidget(helpPage_descript6);
        helpPage_text -> addWidget(helpPage_descript7);
        helpPage_text -> addWidget(helpPage_descript8);
        helpPage_text -> addWidget(helpPage_descript9);

    // initialize screenshots of game
        QLabel * screen_img1 = new QLabel ;
        QPixmap screen_img1_pix (":/img/img/screen1.png");
        screen_img1 -> setPixmap(screen_img1_pix);
        screen_img1 -> setScaledContents(true);
        screen_img1 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

        QLabel * screen_img2 = new QLabel ;
        QPixmap screen_img2_pix (":/img/img/screen2.png");
        screen_img2 -> setPixmap(screen_img2_pix);
        screen_img2 -> setScaledContents(true);
        screen_img2 -> setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );

    // initialize Push button that will return user home from help page
        QPushButton * helpToHomeButton = new QPushButton("Return to Home Screen");

    // insert all widgets into page layout
        helpPageLayout -> addWidget(helpPage_label, 0, 0, 2, 2);
        helpPageLayout -> addWidget(helpPage_text_container, 2, 0, 7, 1);
        helpPageLayout -> addWidget(screen_img1, 2, 1, 3, 1);
        helpPageLayout -> addWidget(screen_img2, 6, 1, 3, 1);
        helpPageLayout-> addWidget(helpToHomeButton, 11, 0, 1, 2);

// ****************************************
// Winning Page 1 - more difficulties to go
// ****************************************
    QWidget * winPage = new QWidget;

    //initialize the page layout with the page widget
        winPageLayout = new QGridLayout(winPage);

    // initialize win declaration label
        QLabel * congrats_label1 = new QLabel ("<h1> Congratulations, you have beaten this difficulty!</h1> \nKeep going by pushing 'Continue'");
        congrats_label1 -> setAlignment(Qt::AlignCenter);

    // initialize push button that will allow user to continue to next level
        next_levelButton = new QPushButton ("Continue");

    // initialize layout to hold restart game and exit game buttons
        restart_and_exitLayout1 = new QHBoxLayout;
        QPushButton * restartButton1 = new QPushButton("Restart game");
        QPushButton * exitButton1 = new QPushButton("Exit game");
        restart_and_exitLayout1 -> addWidget(restartButton1);
        restart_and_exitLayout1 -> addWidget(exitButton1);

    // insert widgets into page layout
        winPageLayout -> addWidget(congrats_label1, 1, 0);
        winPageLayout -> addWidget(next_levelButton, 2,0 );
        winPageLayout -> addLayout(restart_and_exitLayout1, 3,0 );

// ****************************************
// Losing Page
// ****************************************
    QWidget * losePage = new QWidget;

    // initialize the page layout with the page widget
        losePageLayout = new QGridLayout(losePage);

    // initialize lose declaration label
        QLabel * lose_label = new QLabel ("<h1>Sorry, you lost.");
        lose_label -> setAlignment(Qt::AlignCenter);

    // initialize label whose text will be set at run time
    // will contain information on polynomial of the degree that they chose
    // in hopes that they can learn from this information and return to the game with a better understanding
        lose_info_label = new QLabel ;
        lose_info_label -> setAlignment(Qt::AlignCenter);
        lose_info_label -> setStyleSheet("font: 30px;");

    // initialize layout that will hold mute/unmute buttons
        restart_and_exitLayout2 = new QHBoxLayout;
        QPushButton * restartButton2 = new QPushButton("Restart game");
        QPushButton * exitButton2 = new QPushButton("Exit game");
        restart_and_exitLayout2 -> addWidget(restartButton2);
        restart_and_exitLayout2 -> addWidget(exitButton2);

    // insert all widgets into page layout
        losePageLayout -> addWidget(lose_label,0,0);
        losePageLayout -> addWidget(lose_info_label, 1, 0);
        losePageLayout -> addLayout(restart_and_exitLayout2, 2,0);

// ****************************************
// Winning Page 2 - no more difficulties to go
// ****************************************
    QWidget * finalwinPage = new QWidget;

    // initialize the page layout with the page widget
        finalwinPageLayout = new QGridLayout(finalwinPage);

    // initialize win declaration label
        QLabel * congrats_label2 = new QLabel ("<h1> Congratulations, you won!</h1>");
        congrats_label2 -> setAlignment(Qt::AlignCenter);

        QPushButton * next_degreeButton = new QPushButton ("Play again with Higher Degree");

    // initialize layout that will hold mute/unmute buttons
        restart_and_exitLayout3 = new QHBoxLayout;
        QPushButton * restartButton3 = new QPushButton("Restart game");
        QPushButton * exitButton3 = new QPushButton("Exit game");
        restart_and_exitLayout3 -> addWidget(restartButton3);
        restart_and_exitLayout3 -> addWidget(exitButton3);

    //insert all widgets into page layout
        finalwinPageLayout -> addWidget(congrats_label2, 1, 0);
        finalwinPageLayout -> addWidget(next_degreeButton, 2, 0);
        finalwinPageLayout -> addLayout(restart_and_exitLayout3, 3,0 );

// ****************************************
// Stacked Widget
// ****************************************
    _stackedWidget = new QStackedWidget;
    _stackedWidget -> addWidget(firstPage);
    _stackedWidget -> addWidget(simplePage);
    _stackedWidget -> addWidget(IntermediatePage);
    _stackedWidget -> addWidget(DifficultPage);
    _stackedWidget -> addWidget(helpPage);
    _stackedWidget -> addWidget(winPage);
    _stackedWidget -> addWidget(losePage);
    _stackedWidget -> addWidget(finalwinPage);

    // layout
        QVBoxLayout * centrallayout = new QVBoxLayout;
        centrallayout -> addWidget(_stackedWidget);
        setLayout(centrallayout);

// ****************************************
// All program connects
// ****************************************
    // opening screen button connects
        connect(page2PushButton, SIGNAL(clicked()), this , SLOT(goToPage2()));
        connect(helpToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
        connect(homeToHelpButton, SIGNAL(clicked()), this, SLOT(goToHelpPage()));

    // 'Restart' button connects
        connect(page2ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
        connect(page3ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));
        connect(page4ToHomeButton,SIGNAL(clicked()), this, SLOT(goToHome()));

    // 'Mute' button connects
        connect (MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
        connect (page2MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
        connect (page3MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));
        connect (page4MuteButton, SIGNAL(clicked()), this, SLOT(muteMedia()));

    // 'Unmute' button connects
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
        connect(restartButton3, SIGNAL(clicked()), this, SLOT(goToHome()));
        connect(exitButton1,SIGNAL(clicked()), this, SLOT(ExitGame()));
        connect(exitButton2,SIGNAL(clicked()), this, SLOT(ExitGame()));
        connect(exitButton3,SIGNAL(clicked()), this, SLOT(ExitGame()));
        connect(next_levelButton, SIGNAL(clicked()), this, SLOT(goToPage2()));
        connect(next_degreeButton, SIGNAL(clicked()), this, SLOT(goToPage2End()));
}

// ****************************************
// Slot Functions
// ****************************************

// called whenever user clicks 'Graph Polynomial'
// utilizes 'if' statements to determine which difficulty is checked
void Dialog::goToPage2(){

    if(polynomial_order == 0)
        polynomial_order = poly_order -> value();

    // *****************************
    // easy
    // *****************************
    if(diff_1 ->isChecked()){

    // initialize integer using value() member function from QSpinBox class
//        polynomial_order = poly_order -> value();

    // create a vector that contains all degrees in same range of Spin Box (minus the selected degree)
        std::vector <int> all_other_degrees;
        for (int i = 1; i < 5; i++) {
            if(i != polynomial_order){
                all_other_degrees.push_back(i);
            }
        }

    // another Function instance, of same difficulty, with any degree other than the one already plotted
        Function * easy_graph_2 = new Function (all_other_degrees[1], "simple");

    // set index on stack
       _stackedWidget -> setCurrentIndex(1);

    // initialize Function object from dialog private field
    // i.e. the actual graph corresponding to user selection
       graph = new Function(polynomial_order, "simple");

    //difficulty display text is set
       std::stringstream difficulty_buffer;
       difficulty_buffer << "Current Difficulty : ";
       std::string diff_string = graph -> getDifficulty();
       difficulty_buffer << diff_string;
       std::string difficulty_buffer_string = difficulty_buffer.str();
       difficulty_label1 -> setText(QString::fromUtf8(difficulty_buffer_string.c_str()));

    // lose page label text is set
       std::stringstream info_reader;
       graph -> printInfo(info_reader);
       std::string info_string = info_reader.str();
       lose_info_label -> setText(QString::fromUtf8(info_string.c_str()));

    // read function into stringstream from print function
       std::stringstream func_reader;
       func_reader << "Function:\n";
       graph -> printFunc(func_reader); // func_reader now holds output from print function
       func_reader << "\n\nZero:\n";
       func_reader << std::to_string(graph -> getZero());

    // convert stringstream into string
       std::string s = func_reader.str(); // string is given all stringstream content

    // initialize page 2 label with string
       page2_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

    // real graph
       // allows user to click on graph
       ui -> graph1 -> setInteraction(QCP::iSelectPlottables);
       // checks if axes need to be hidden
       if(hide_axis -> isChecked()){
         ui -> graph1 -> xAxis -> setTickLabels(false);
         ui -> graph1 -> yAxis -> setTickLabels(false);
       }
       // add the actual graph to plot
           ui -> graph1 ->addGraph();
           // setData takes two QVector<double> arguments, the x and y values, respectively
           // these are obtained using Function getter function getX() & getY()
           ui -> graph1 -> graph(0) -> setData(graph -> getX(), graph -> getY());

    // insert 'fake' graphs - graphs that do not match the degree that the user selected
         ui -> graph1 ->addGraph();
         ui -> graph1 -> graph(1) -> setData(easy_graph_2->getX(), easy_graph_2->getY());

    // give the axes some labels:
         ui -> graph1 ->xAxis->setLabel("x");
         ui -> graph1 ->yAxis->setLabel("y");

    // set axes ranges, so we see all data:
         ui->graph1->xAxis->setRange(-20, 20);
         ui->graph1->yAxis->setRange(-200, 200);

    //randonmly assign 2 colors
         int j = rand() % 2;
         int k = rand() % 2;
         while(k==j){k = rand() % 2;}
         ui -> graph1 -> graph(j)->setPen(QPen(Qt::cyan));
         ui -> graph1 -> graph(k)->setPen(QPen(Qt::red));
         ui->graph1->replot();
    }

    // *****************************
    // intermediate
    // *****************************
    if(diff_2 ->isChecked()){
    // initialize integer using value() member function from QSpinBox class
//        polynomial_order = poly_order ->value();

    // create a vector that contains all degrees in same range of Spin Box (minus the selected degree)
      std::vector <int> all_other_degrees;
      for (int i = 1; i < 5; i++) {
          if(i != polynomial_order){
              all_other_degrees.push_back(i);
          }
      }

    // more Function instances, of same difficulty, with any degree other than the one already plotted
      Function * inter_graph_2 = new Function (all_other_degrees[0], "intermediate");
      Function * inter_graph_3 = new Function (all_other_degrees[1], "intermediate");

      // set index on stack
      _stackedWidget -> setCurrentIndex(2);

      // initialize Function object from dialog private field
      // i.e. the actual graph corresponding to user selection
        graph = new Function(polynomial_order, "intermediate");

      //difficulty display text is set
        std::stringstream difficulty_buffer;
        difficulty_buffer << "Current Difficulty : ";
        std::string diff_string = graph -> getDifficulty();
        difficulty_buffer << diff_string;
        std::string difficulty_buffer_string = difficulty_buffer.str();
        difficulty_label2 -> setText(QString::fromUtf8(difficulty_buffer_string.c_str()));

      // lose page label text is set
         std::stringstream info_reader;
         graph -> printInfo(info_reader);
         std::string info_string = info_reader.str();
         lose_info_label -> setText(QString::fromUtf8(info_string.c_str()));

      // read function into stringstream from print function
      std::stringstream func_reader;
      func_reader << "Function:\n";
      graph -> printFunc(func_reader); // func_reader now holds output from print function
      func_reader << "\n\nZero:\n";
      func_reader << std::to_string(graph -> getZero());

      //convert stringstream to string
      std::string s = func_reader.str(); // string is given all stringstream content

      // initialize page 3 label with string
      page3_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

      //real graph
        //allows user to click on graph
             ui -> graph2 -> setInteraction(QCP::iSelectPlottables);

      // checks if axes need to be hidden
        if(hide_axis -> isChecked()){
            ui -> graph2 -> xAxis -> setTickLabels(false);
            ui -> graph2 -> yAxis -> setTickLabels(false);
        }

    // add the actual graph to plot
      ui -> graph2 ->addGraph();
      ui -> graph2 -> graph(0) -> setData(graph->getX(), graph->getY());

      // insert 'fake' graphs - graphs that do not match the degree that the user selected
      ui -> graph2 ->addGraph();
      ui -> graph2 -> graph(1) -> setData(inter_graph_2->getX(), inter_graph_2->getY());

      ui -> graph2 ->addGraph();
      ui -> graph2 -> graph(2) -> setData(inter_graph_3->getX(), inter_graph_3->getY());

      // give the axes some labels:
      ui -> graph2 ->xAxis->setLabel("x");
      ui -> graph2 ->yAxis->setLabel("y");

      // set axes ranges, so we see all data:
      ui->graph2->xAxis->setRange(-20, 20);
      ui->graph2->yAxis->setRange(-200, 200);

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

    // *****************************
    // difficult
    // *****************************
    if(diff_3 ->isChecked()){
        // initialize integer using value() member function from QSpinBox class
//        polynomial_order = poly_order ->value();

        // create a vector that contains all degrees in same range of Spin Box (minus the selected degree)
        std::vector <int> all_other_degrees;
        for (int i = 1; i < 5; i++) {
            if(i != polynomial_order){
                all_other_degrees.push_back(i);
            }
        }

        // more Function instances, of same difficulty, with any degree other than the one already plotted
        Function * diff_graph_2 = new Function (all_other_degrees[0], "difficult");
        Function * diff_graph_3 = new Function (all_other_degrees[1], "difficult");
        Function * diff_graph_4 = new Function (all_other_degrees[2], "difficult");

        // set index on stack
        _stackedWidget -> setCurrentIndex(3);

        // initialize Function object from dialog private field
        // i.e. the actual graph corresponding to user selection
        graph = new Function(polynomial_order, "difficult");


    //difficulty display text is set
        std::stringstream difficulty_buffer;
        difficulty_buffer << "Current Difficulty : ";
        std::string diff_string = graph -> getDifficulty();
        difficulty_buffer << diff_string;
        std::string difficulty_buffer_string = difficulty_buffer.str();
        difficulty_label3 -> setText(QString::fromUtf8(difficulty_buffer_string.c_str()));

    // lose page label text is set
        std::stringstream info_reader;
        graph -> printInfo(info_reader);
        std::string info_string = info_reader.str();
        lose_info_label -> setText(QString::fromUtf8(info_string.c_str()));


    // read function into stringstream from print function
        std::stringstream func_reader ;
        func_reader << "Function:\n";
        graph -> printFunc(func_reader); // func_reader now holds output from print function
        func_reader << "\n\nZero:\n";
        func_reader << std::to_string(graph -> getZero());

    // convert stringstream into string
        std::string s = func_reader.str(); // string is given all stringstream content

    // initialize page 4 label with string
        page4_label -> setText(QString::fromUtf8(s.c_str())); // text in label is set by converting c_string into QString

    //real graph
        // allows user to click on graph
        ui -> graph3 -> setInteraction(QCP::iSelectPlottables);
        // checks is axes need to be hidden
        if(hide_axis -> isChecked()){
        ui -> graph3 -> xAxis -> setTickLabels(false);
        ui -> graph3 -> yAxis -> setTickLabels(false);
        }
        // add the actual graph to plot
        ui -> graph3 ->addGraph();
        ui -> graph3 -> graph(0) -> setData(graph->getX(), graph->getY());

    // insert 'fake' graphs - graphs that do not match the degree that the user selected
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
        ui->graph3->yAxis->setRange(-200, 200);

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

void Dialog::goToPage2End(){

    polynomial_order += 1;

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

   if(hide_axis -> isChecked()){
     ui -> graph1 -> xAxis -> setTickLabels(false);
     ui -> graph1 -> yAxis -> setTickLabels(false);
   }

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

// called whenever user clicks 'Return'
void Dialog::goToHome(){


    _stackedWidget -> setCurrentIndex(0);

    // resets hidden hearts
        heart_pic_label11 -> setVisible(true);
        heart_pic_label21 -> setVisible(true);
        heart_pic_label31 -> setVisible(true);
        heart_pic_label12 -> setVisible(true);
        heart_pic_label22 -> setVisible(true);
        heart_pic_label13 -> setVisible(true);
        hearts = {1,2,3};

    // resets hidden axes
        ui -> graph1 -> xAxis -> setTickLabels(true);
        ui -> graph1 -> yAxis -> setTickLabels(true);
        ui -> graph2 -> xAxis -> setTickLabels(true);
        ui -> graph2 -> yAxis -> setTickLabels(true);
        ui -> graph3 -> xAxis -> setTickLabels(true);
        ui -> graph3 -> yAxis -> setTickLabels(true);

    // resets axis hider button
        hide_axis -> setChecked(false);

    // resets all radio buttons so that none are pushed down
        diff_1->setAutoExclusive(false);
        diff_1->setChecked(false);
        diff_1->setAutoExclusive(true);

        diff_2->setAutoExclusive(false);
        diff_2->setChecked(false);
        diff_2->setAutoExclusive(true);

        diff_3->setAutoExclusive(false);
        diff_3->setChecked(false);
        diff_3->setAutoExclusive(true);

        polynomial_order = 0;
}

// called whenever user clicks 'Help'
void Dialog::goToHelpPage(){
    _stackedWidget -> setCurrentIndex(4);
}

// called whenever user clicks 'Mute'
void Dialog::muteMedia(){

    music -> setVolume(0);
}

// called whenever user clicks 'Unmute'
void Dialog::unMuteMedia(){
    music -> setVolume(100);
}

// called whenever user clicks 'Choose Graph' after selecting simple difficulty
void Dialog::graph_clicked1(){

    bool continuing_to_guess_wrong = true;

    // initialize the vector of pointers to QCPGraph with the selectedGraphs() member function from the QCPGraph class
    // graphs_list will now contain pointers to all selected graphs (only 1 selected at a time))
    graphs_list = ui -> graph1 -> selectedGraphs();

    // .contains() returns true if parameter is found within list
    bool selected_right_graph = graphs_list.contains(ui -> graph1 -> graph(0));

    while(continuing_to_guess_wrong){

        // if they selected the wrong graph that is denoted by !selected_right_graph
        // if this is their first time getting it wrong the size of hearts will be 3
        // if nothing is selected then the size of graphs_list would be zero
        if(!selected_right_graph && hearts.size()==3 && graphs_list.size() != 0){
            // lose first life
            heart_pic_label31 -> setVisible(false);

            //adjust vector size
            hearts.pop_back();

            // exit loop and let user guess again
            continuing_to_guess_wrong =false;
        }

        // if they selected the wrong graph that is denoted by !selected_right_graph
        // if this is their second time getting it wrong the size of hearts will be 2
        // once a graph is first clicked, a graph will remain clicked while on the same screen
        // so no need to check the size of graphs_list, only check if correct graph has been selected
        else if(!selected_right_graph && hearts.size()==2){
            // lose second life
            heart_pic_label21 -> setVisible(false);

            //adjust vector size
            hearts.pop_back();

            // exit loop and let user guess again
            continuing_to_guess_wrong =false;
        }

        // if they selected the wrong graph that is denoted by !selected_right_graph
        // if this is their third time getting it wrong the size of hearts will be 1
        else if(!selected_right_graph && hearts.size()==1){
            // lose third and last life
            heart_pic_label11 -> setVisible(false);

            // adjust vector size
            hearts.pop_back();

            // clear selections
            ui -> graph1 ->deselectAll();

            // send user to lose page
            _stackedWidget -> setCurrentIndex(6);

            // exit loop
            continuing_to_guess_wrong =false;
        }

        if(selected_right_graph){

            // remove and replot
            ui -> graph1 -> removeGraph(0);
            ui -> graph1 -> replot();

            // remove the selection of simple difficulty from starting page
            diff_1->setAutoExclusive(false);
            diff_1->setChecked(false);
            diff_1->setAutoExclusive(true);

            // set next difficulty in case user clicks continue when sent to winning page 1
            // if 'Return' is clicked instead then diff_2 is unchecked so this well-defined
            diff_2 -> setChecked(true);

            // send user to win page 1
            _stackedWidget -> setCurrentIndex(5);

            // exit loop
            continuing_to_guess_wrong =false;
        }
        // exit loop once and for all
        continuing_to_guess_wrong = false;
  }

}

// called whenever user clicks 'Choose Graph' after selecting intermediate difficulty
void Dialog::graph_clicked2(){


        bool continuing_to_guess_wrong = true;

        // initialize the vector of pointers to QCPGraph with the selectedGraphs() member function from the QCPGraph class
        // graphs_list will now contain pointers to all selected graphs (only 1 selected at a time))
        graphs_list = ui -> graph2 -> selectedGraphs();

        // .contains() returns true if parameter is found within list
        bool selected_right_graph = graphs_list.contains(ui -> graph2 -> graph(0));

        while(continuing_to_guess_wrong){

            // if they selected the wrong graph that is denoted by !selected_right_graph
            // if this is their first time getting it wrong the size of hearts will be 3
            // if nothing is selected then the size of graphs_list would be zero
            if(!selected_right_graph && hearts.size()==3 && graphs_list.size() != 0){
                // lose first life
                heart_pic_label22 -> setVisible(false);
                //adjust vector size
                hearts.pop_back();
                // exit loop and let user guess again
                continuing_to_guess_wrong =false;
            }

            // if they selected the wrong graph that is denoted by !selected_right_graph
            // if this is their second time getting it wrong the size of hearts will be 2
            // once a graph is first clicked, a graph will remain clicked while on the same screen
            // so no need to check the size of graphs_list, only check if correct graph has been selected
            else if(!selected_right_graph && hearts.size()==2&& graphs_list.size() != 0){
                // lose second life
                heart_pic_label12 -> setVisible(false);
                // adjust vector size
                hearts.pop_back();

                // clear selections
                ui -> graph2 -> deselectAll();

                // send user to lose page
                _stackedWidget -> setCurrentIndex(6);

                //exit loop
                continuing_to_guess_wrong =false;
            }

            if(selected_right_graph){

                // remove and reelot
                ui -> graph2 -> removeGraph(0);
                ui -> graph2 -> replot();

                // remove the selection of intermediate difficulty from starting page
                diff_2 ->setAutoExclusive(false);
                diff_2 ->setChecked(false);
                diff_2 ->setAutoExclusive(true);

                // set next difficulty in case user clicks continue when sent to winning page 1
                // if 'Return' is clicked instead then diff_3 is unchecked so this well-defined
                diff_3 -> setChecked(true);

                // send user to winning page 1
                _stackedWidget -> setCurrentIndex(5);

                // exit loop
                continuing_to_guess_wrong =false;
            }

            // exit loop once and for all
            continuing_to_guess_wrong = false;
      }

    }

// called whenever user clicks 'Choose Graph' after selecting difficult difficulty
void Dialog::graph_clicked3(){

        bool continuing_to_guess_wrong = true;

        // initialize the vector of pointers to QCPGraph with the selectedGraphs() member function from the QCPGraph class
        // graphs_list will now contain pointers to all selected graphs (only 1 selected at a time))
        graphs_list = ui -> graph3 -> selectedGraphs();

        // .contains() returns true if parameter is found within list
        bool selected_right_graph = graphs_list.contains(ui -> graph3 -> graph(0));

        while(continuing_to_guess_wrong){

            // if they selected the wrong graph that is denoted by !selected_right_graph
            // if this is their first time getting it wrong the size of hearts will be 3
            // if nothing is selected then the size of graphs_list would be zero
            if(!selected_right_graph && hearts.size()==3  && graphs_list.size() != 0){
                // lose first and only life
                heart_pic_label13 -> setVisible(false);
                // adjust vector size
                hearts.pop_back();

                // send user to lose page
                _stackedWidget -> setCurrentIndex(6);

                //exit loop
                continuing_to_guess_wrong =false;
            }

            if(selected_right_graph){

                // remove and replot
                ui -> graph3 -> removeGraph(0);
                ui -> graph3 -> replot();

                // send user to winning page 2 since they have beat the game at its highest difficulty
                _stackedWidget -> setCurrentIndex(7);

                //exit loop
                continuing_to_guess_wrong =false;
            }

            //exit loop once and for all
            continuing_to_guess_wrong = false;

      }
}

// called whenever user clicks 'Exit'
void Dialog::ExitGame(){
    exit(1);
}

// Dialog destructor
Dialog::~Dialog()
{
    delete ui;
}
