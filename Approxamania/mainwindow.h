#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QRadioButton>
#include <QLayout>
#include <QStackedWidget>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void goToPage2();


private:
    Ui::MainWindow *ui;
    QStackedWidget * _stackedWidget;

    QWidget * firstPage;
    QWidget * secondPage;
    QLabel * welcome_label;
    QLabel * instruction_label;
    QLabel * secondpage_label;
    QSpinBox * poly_order;
    QRadioButton * diff_1;
    QRadioButton * diff_2;
    QRadioButton * diff_3;
    QVBoxLayout * diff_layout;
    QVBoxLayout * central_layout;
    QHBoxLayout * main_window_layout;
    QHBoxLayout * second_window_layout;
    QPushButton * page2PushButton;
};


#endif // MAINWINDOW_H
