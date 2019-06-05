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
    void goToPage2();
    void goToHome();
    void goToHelpPage();
    void muteMedia();
    void unMuteMedia();
    void graph_clicked1();
    void graph_clicked2();
    void graph_clicked3();
    void ExitGame();


private:
    QStackedWidget * _stackedWidget;
    QRadioButton * diff_1;
    QRadioButton * diff_2;
    QRadioButton * diff_3;
    QCheckBox * hide_axis;
    Function * graph;
    QVBoxLayout * graph_display;

    QGridLayout * SimplePageLayout;
    QGridLayout * IntermediatePageLayout;
    QGridLayout * DifficultPageLayout;
    QGridLayout * winPageLayout;
    QGridLayout * finalwinPageLayout;
    QGridLayout * losePageLayout;
    QHBoxLayout * restart_and_exitLayout1;
    QHBoxLayout * restart_and_exitLayout2;
    QHBoxLayout * restart_and_exitLayout3;


    QSpinBox * poly_order;
    QLabel * page2_label;
    QLabel * page3_label;
    QLabel * page4_label;
    QLabel * heart_pic_label11;
    QLabel * heart_pic_label21;
    QLabel * heart_pic_label31;
    std::vector<int> hearts = {1,2, 3};
    QLabel * heart_pic_label12;
    QLabel * heart_pic_label22;
    QLabel * heart_pic_label13;
    QMediaPlayer* music;
    QList < QCPGraph * > graphs_list;
    Ui::Dialog *ui;
    int x = 0;
    int polynomial_order = 0;

    QPushButton * guess_button1;
    QPushButton * guess_button2;
    QPushButton * guess_button3;

    QLabel * lose_info_label;

    QLabel * congrats_label1;
    QLabel * congrats_label2;
    QPushButton * next_levelButton;
};

#endif // DIALOG_H
