#include "DataShare.h"
#include <bits/stdc++.h>
#include <QMessageBox>
using namespace std;

DataShare::DataShare() {}
void DataShare::set_Code(map<string,string> tempCode)
{
    this->Code = tempCode;
}

const map<string,string> DataShare::get_Code()
{
    return this->Code;
}
void DataShare::set_TreeVector(vector<HuffmanTree> TempTree)
{
   this->Tree = TempTree;
}
const vector<HuffmanTree> DataShare::get_TreeVector()
{
    return this->Tree;
}
