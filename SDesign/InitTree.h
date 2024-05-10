#ifndef INITTREE_H
#define INITTREE_H
#include "PublicDeclaration.h"
#include <bits/stdc++.h>
using namespace std;
class InitTree
{
private:
    typedef struct InputDataNode
    {
        string ch;
        double weight;
    }*InNode;

public:
    InitTree();
    void InitHuffmanTree();
    void ReadFile();
    void WriteFile();
    void CreateHuffTree();
    const vector<HuffmanTree> get_TreeVector();

private:
    vector<InNode> InData;
    vector<HuffmanTree> Tree;
};

#endif // INITTREE_H
