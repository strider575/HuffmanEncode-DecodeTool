#include "HuffmanCode.h"
#include <QMessageBox>
#include <bits/stdc++.h>
using namespace std;

HuffmanCode::HuffmanCode() {}

void HuffmanCode::Encoding()
{
    this->CreateHuffmanCode();
    this->ReadTransFile();
    this->CodeText();
    this->OutPutCodeFile();
}

void HuffmanCode::ReadTransFile()
{
    const string ToBeTran = "E:\\code\\qt\\SDesign\\SDesign\\file\\ToBeTran.txt";
    ifstream InData;
    InData.open(ToBeTran, ios::in);

    if (!InData.is_open())
    {
        QMessageBox::warning(NULL, "Warning", "Fail to Open File!", QMessageBox::Yes);
        return;
    }
    getline(InData,TransText);
    InData.close();
}

void HuffmanCode::CreateHuffmanCode()
{
    int n = 26;
    string tempcode;
    Code.clear();
    for (int i = 1; i <= n; i++)
    {
        tempcode.clear();
        int c = i; //正在进行的第i个数据的编码
        int p = Tree[i]->parent; //找到该数据的父结点
        while (p) //直到父结点为0，即父结点为根结点时，停止
        {
            if (Tree[p]->lc == c) //如果该结点是其父结点的左孩子，则编码为0，否则为1
                tempcode.append("0");
            else
                tempcode.append("1");
            c = p; //继续往上进行编码
            p = Tree[c]->parent; //c的父结点
        }
        reverse(tempcode.begin(),tempcode.end());
        Code.insert(make_pair(Tree[i]->ch,tempcode));
    }
}

void HuffmanCode::CodeText()
{
    string str = TransText;
    HuffCode.clear();
    string a;
    for (int i = 0; i < (int)str.size(); i++)
    {
        a = str[i];
        HuffCode.append(Code[a]);
    }
}

void HuffmanCode::OutPutCodeFile()
{
    const string FilePath = "E:\\code\\qt\\SDesign\\SDesign\\file\\CodeFile.txt";
    ofstream OutData;
    OutData.open(FilePath, ios::out);
    if (!OutData.is_open())
    {
        QMessageBox::warning(NULL, "Warning", "Fail to Open File!", QMessageBox::Yes);
        return;
    }
    OutData << this->HuffCode << endl;

    OutData.close();
}
const map<string,string> HuffmanCode::get_Code()
{
    return this->Code;
}

const string HuffmanCode::get_CodeText()
{
    string res;
    res = "";
    for (auto it = Code.begin(); it != Code.end(); ++it)
    {
        res.append(it->first);
        res.append("-");
        res.append(it->second);
        res.append("; ");
    }
    return res;
}
void HuffmanCode::set_TreeVector(vector<HuffmanTree> TempTree)
{
    this->Tree = TempTree;
}

const string HuffmanCode::get_ToTransText()
{
    return this->TransText;
}

const string HuffmanCode::get_HuffCodeText()
{
    return this->HuffCode;
}
