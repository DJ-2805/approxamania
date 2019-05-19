#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QStackedWidget>
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QPixmap>
#include <QMediaPlayer>


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


private:
    QStackedWidget * _stackedWidget;
    QRadioButton * diff_1;
    QRadioButton * diff_2;
    QRadioButton * diff_3;
    QHBoxLayout * hearts_layout;
    QLabel * heart_pic_label1;
    QLabel * heart_pic_label2;
    QLabel * heart_pic_label3;
    Ui::Dialog *ui;
    int x = 0;
};

#endif // DIALOG_H
