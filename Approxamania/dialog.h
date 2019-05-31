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
#include "Function.h"


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
    void show_graph_data(Function * graphx);
    void hide_graph_data(Function * graphx);


private:
    QStackedWidget * _stackedWidget;
    QRadioButton * diff_1;
    QRadioButton * diff_2;
    QRadioButton * diff_3;
    Function * graph ;
    QVBoxLayout * graph_display;
    QSpinBox * poly_order;
    QLabel * page2_label;
    QLabel * page3_label;
    QLabel * page4_label;
    QHBoxLayout * hearts_layout1;
    QHBoxLayout * hearts_layout2;
    QHBoxLayout * hearts_layout3;
    QLabel * heart_pic_label11;
    QLabel * heart_pic_label21;
    QLabel * heart_pic_label31;
    QLabel * heart_pic_label12;
    QLabel * heart_pic_label22;
    QLabel * heart_pic_label13;
    QMediaPlayer* music;
    Ui::Dialog *ui;
    int x = 0;
    int polynomial_order = 0;
};

#endif // DIALOG_H
