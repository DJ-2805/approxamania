#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QStackedWidget>
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPixmap>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QString>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <QList>
#include <QDebug>
#include <sstream>
#include "Function.h"
#include "ui_dialog.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog();

public slots:
    /* Radio Button slot
     * Slot to send user to ap propriate graph displaying widget (depending on selected difficulty) after clicking 'Graph Polynomial'
    */
    void goToPage2();

    void goToPage2End();

    /* Radio Button slot
     * Slot to return user back to starting page after clicking 'Return' which is located on more than 1 widget
     * Is responsible for resetting a lot of data so that none overlaps when you continue to enter/exit the graph widgets
    */
    void goToHome();
    /* Radio Button slot
     * Slot to send user to help page after clicking 'Help'
     * contains text on general purpose of game/how to play, as well as screenshots from the program
    */
    void goToHelpPage();
    /* Radio Button slot
     * Slot to set the volume of the QMediaPlayer object to zero whenever clicked
    */
    void muteMedia();
    /* Radio Button slot
     * Slot to set the volume of the QMediaPlayer object to 100(full) whenever clicked
    */
    void unMuteMedia();
    /* Radio Button slot
     * Slot to tell compiler that user just confirmed their graph selection by clicking 'Choose Graph'
     * Will only go off when the graph on simple difficulty is currently clicked
    */
    void graph_clicked1();
    /* Radio Button slot
     * Slot to tell compiler that user just confirmed their graph selection by clicking 'Choose Graph'
     * Will only go off when the graph on intermediate difficulty is currently clicked
    */
    void graph_clicked2();
    /* Radio Button slot
     * Slot to tell compiler that user just confirmed their graph selection by clicking 'Choose Graph'
     * Will only go off when the graph on difficult difficulty is currently clicked
    */
    void graph_clicked3();
    /* Radio Button slot
     * Slot to exit game with public function exit()
     * Located on all post-game-played screens
    */
    void ExitGame();


private:
    Ui::Dialog *ui;

    // stack of widgets
    QStackedWidget * _stackedWidget;

    // instance of Function class
    Function * graph;

    // layouts of widgets on stack
    QGridLayout * SimplePageLayout;
    QGridLayout * IntermediatePageLayout;
    QGridLayout * DifficultPageLayout;
    QGridLayout * winPageLayout;
    QGridLayout * finalwinPageLayout;
    QGridLayout * losePageLayout;

    // music playing object
    QMediaPlayer* music;

    // starting page
        // difficulty radio buttons
        QRadioButton * diff_1;
        QRadioButton * diff_2;
        QRadioButton * diff_3;

        // spin box for order of polynomial
        QSpinBox * poly_order;

        // hide axes check box
        QCheckBox * hide_axis;

    // for all three difficulties and their respective widgets
        // layout for restart and exit buttons
        QHBoxLayout * restart_and_exitLayout1;
        QHBoxLayout * restart_and_exitLayout2;
        QHBoxLayout * restart_and_exitLayout3;

        // labels containing printed function and printed zero on graph widgets
        QLabel * page2_label;
        QLabel * page3_label;
        QLabel * page4_label;

        // labels that display current difficulty
        QLabel * difficulty_label1;
        QLabel * difficulty_label2;
        QLabel * difficulty_label3;

        // vector whose size determines actions in graph clicking
        std::vector<int> hearts = {1,2, 3};

        // lives in simple difficulty
        QLabel * heart_pic_label11;
        QLabel * heart_pic_label21;
        QLabel * heart_pic_label31;

        // lives in intermediate difficulty
        QLabel * heart_pic_label12;
        QLabel * heart_pic_label22;

        // lives in difficult difficulty
        QLabel * heart_pic_label13;

        // will be initialized with QCGraph -> selectedGraphs()
        // after initialization, this container will contain a pointer to the graph that is clicked
        QList < QCPGraph * > graphs_list;

        // store polynomial order in integer
        int polynomial_order = 0;

        // Push button to confirm graph selection
        QPushButton * guess_button1;
        QPushButton * guess_button2;
        QPushButton * guess_button3;

    // screens for after user is done playing
        // displays text on lose page
        QLabel * lose_info_label;

        // displays if you won text on any difficulty that is not 'difficult'
        QLabel * congrats_label1;

        // displayed after winning on difficult
        QLabel * congrats_label2;

        // push button to take user to next level if there is another difficulty
        QPushButton * next_levelButton;

        QPushButton * next_degreeButto;
};

#endif // DIALOG_H
