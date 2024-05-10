#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H

#include "PublicDeclaration.h"
#include <bits/stdc++.h>
using namespace std;

class HuffmanCode
{
public:
    HuffmanCode();
    void Encoding();
    void ReadTransFile();
    void CreateHuffmanCode();
    void CodeText();
    void OutPutCodeFile();
    void set_TreeVector(vector<HuffmanTree> TempTree);

    const map<string,string> get_Code();
    const string get_CodeText();
    const string get_ToTransText();
    const string get_HuffCodeText();
private:
    string TransText;
    string HuffCode;
    vector<HuffmanTree> Tree;
    map<string,string> Code;
};

#endif // HUFFMANCODE_H
