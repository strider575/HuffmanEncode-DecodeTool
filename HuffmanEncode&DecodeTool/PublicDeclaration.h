#ifndef PUBLICDECLARATION_H
#define PUBLICDECLARATION_H
#include <bits/stdc++.h>
using namespace std;

typedef struct DrawNode
{
    int x,y;
}TreePoint;

typedef struct HNode
{
    string ch;
    double weight; //权值
    int parent; //父节点
    int lc, rc; //左右孩子

    double idx,idy;
    TreePoint pos;
}*HuffmanTree;

#endif // PUBLICDECLARATION_H
