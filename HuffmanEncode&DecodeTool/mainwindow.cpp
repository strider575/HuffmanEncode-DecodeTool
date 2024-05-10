#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "InitTree.h"
#include "HuffmanCode.h"
#include "HuffmanDecode.h"
#include "DataShare.h"
#include "DrawHuffTree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("赫夫曼编码/译码器");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Init_clicked()
{
    InitTree *a  = new InitTree;
    a->InitHuffmanTree();
    data1.set_TreeVector(a->get_TreeVector());

    delete a;
}


void MainWindow::on_Encode_clicked()
{
    HuffmanCode *a = new HuffmanCode;

    if(data1.get_TreeVector().empty())
    {
        QMessageBox::warning(NULL, "Warning", "未初始化霍夫曼树！请先初始化", QMessageBox::Yes);
        delete a;
        return;
    }
    a->set_TreeVector(data1.get_TreeVector());
    a->Encoding();
    data1.set_Code(a->get_Code());
    //QMessageBox::warning(NULL, "Warning", "Fail to Open File!", QMessageBox::Yes);
    ui->ToTransText->setText(QString::fromStdString(a->get_ToTransText()));
    ui->HuffCode->setText(QString::fromStdString(a->get_CodeText()));
    ui->ToDecodeText->setText(QString::fromStdString(a->get_HuffCodeText()));

    delete a;
}


void MainWindow::on_DecodeButton_clicked()
{
    HuffmanDecode *a = new  HuffmanDecode;
    if(data1.get_TreeVector().empty())
    {
        QMessageBox::warning(NULL, "Warning", "未初始化霍夫曼树！请先初始化", QMessageBox::Yes);
        delete a;
        return;
    }
    if(data1.get_Code().empty())
    {
        QMessageBox::warning(NULL, "Warning", "未编码！请先编码", QMessageBox::Yes);
        delete a;
        return;
    }
    a->set_Code(data1.get_Code());
    a->Decoding();

    ui->ResText->setText(QString::fromStdString(a->get_ResText()));
    delete a;
}


void MainWindow::on_ShowTreeButton_clicked()
{
    DrawHuffTree *a = new DrawHuffTree();
    if(data1.get_TreeVector().empty())
    {
        QMessageBox::warning(NULL, "Warning", "未初始化霍夫曼树！请先初始化", QMessageBox::Yes);
        delete a;
        return;
    }
    if(data1.get_Code().empty())
    {
        QMessageBox::warning(NULL, "Warning", "未编码！请先编码", QMessageBox::Yes);
        delete a;
        return;
    }
    a->set_Code(data1.get_Code());
    a->set_TreeVector(data1.get_TreeVector());
    a->show();
    //delete a;
}


void MainWindow::on_Button_Exit_clicked()
{
    this->close();
}

