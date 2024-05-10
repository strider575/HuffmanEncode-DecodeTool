#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DataShare.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Init_clicked();

    void on_Encode_clicked();

    void on_DecodeButton_clicked();

    void on_ShowTreeButton_clicked();

    void on_Button_Exit_clicked();

private:
    Ui::MainWindow *ui;
    DataShare data1;
};
#endif // MAINWINDOW_H
