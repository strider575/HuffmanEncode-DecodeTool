#ifndef DRAWHUFFTREE_H
#define DRAWHUFFTREE_H
#include "PublicDeclaration.h"
#include <QWidget>
#include <bits/stdc++.h>
using namespace std;

class DrawHuffTree : public QWidget
{
    Q_OBJECT
public:
    explicit DrawHuffTree(QWidget *parent = nullptr);
    void set_TreeVector(vector<HuffmanTree> TempTree);
    void set_Code(map<string,string> tempCode);
signals:

protected:
    void paintEvent(QPaintEvent *event);

public slots:

private:
    vector<HuffmanTree> Tree;
    map<string,string> Code;
};

#endif // DRAWHUFFTREE_H
