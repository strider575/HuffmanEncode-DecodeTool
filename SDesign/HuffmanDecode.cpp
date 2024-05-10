#include "HuffmanDecode.h"
#include <bits/stdc++.h>
#include <QMessageBox>
using namespace std;

HuffmanDecode::HuffmanDecode() {}
void HuffmanDecode::Decoding()
{
    this->ReadText();
    this->DecodeText();
    this->OutPutTextfile();
}
void HuffmanDecode::ReadText()
{
    const string CodeFile = "E:\\code\\qt\\SDesign\\SDesign\\file\\CodeFile.txt";
    ifstream InData;
    InData.open(CodeFile, ios::in);

    if (!InData.is_open())
    {
        QMessageBox::warning(NULL, "Warning", "Fail to Open File!", QMessageBox::Yes);
        return;
    }
    getline(InData,ToDecodeText);

    InData.close();
}

void HuffmanDecode::DecodeText()
{
    string temp;
    ResText.clear();//解码后的字符串
    for (int i = 0; i < (int)ToDecodeText.size(); i++)
    {
        temp = temp + ToDecodeText[i];
        for(map<string,string>::iterator it = Code.begin(); it != Code.end(); ++it)
        {
            if (it->second == temp)
            {
                ResText.append(it->first);
                temp.clear();
            }
        }
    }
}
void HuffmanDecode::OutPutTextfile()
{
    const string FilePath = "E:\\code\\qt\\SDesign\\SDesign\\file\\Textfile.txt";
    ofstream OutData;
    OutData.open(FilePath, ios::out);
    OutData << ResText << endl;

    OutData.close();
}
void HuffmanDecode::set_Code(map<string,string> tempCode)
{
    this->Code = tempCode;
}

const string HuffmanDecode::get_ResText()
{
    return ResText;
}
