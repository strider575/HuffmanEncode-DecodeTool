#ifndef DATASHARE_H
#define DATASHARE_H
#include <bits/stdc++.h>
#include "PublicDeclaration.h"

using namespace std;

class DataShare
{
public:
    DataShare();
    void set_Code(map<string,string>);
    const map<string,string> get_Code();

    void set_TreeVector(vector<HuffmanTree> TempTree);
    const vector<HuffmanTree> get_TreeVector();
private:
    map<string,string> Code;//哈夫曼编码的键值对
    vector<HuffmanTree> Tree;
};

#endif // DATASHARE_H
