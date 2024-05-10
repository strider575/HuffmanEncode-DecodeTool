#ifndef HUFFMANDECODE_H
#define HUFFMANDECODE_H
#include <bits/stdc++.h>
using namespace std;

class HuffmanDecode
{
public:
    HuffmanDecode();
    void Decoding();
    void ReadText();
    void DecodeText();
    void OutPutTextfile();
    void set_Code(map<string,string> tempCode);

    const string get_ResText();

private:
    string ToDecodeText;
    string ResText;
    map<string,string> Code;
};

#endif // HUFFMANDECODE_H
