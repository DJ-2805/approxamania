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

private:
    QStackedWidget * _stackedWidget;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
