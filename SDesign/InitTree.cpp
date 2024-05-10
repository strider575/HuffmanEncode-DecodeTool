#include "InitTree.h"
#include <QMessageBox>
#include <bits/stdc++.h>
using namespace std;
InitTree::InitTree() {}
void InitTree::InitHuffmanTree()
{
    this->ReadFile();
    this->CreateHuffTree();
    this->WriteFile();
}
void InitTree::ReadFile()
{
    const string charFrequency = "E:\\code\\qt\\SDesign\\SDesign\\file\\charFrequency.txt";
    ifstream InData;
    InData.open(charFrequency, ios::in);

    if (!InData.is_open())
    {
        QMessageBox::warning(NULL, "Warning", "Fail to Open File!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    string TempChar;
    double TempFreq;
    while (InData >> TempChar && InData >> TempFreq)
    {
        struct InputDataNode* NewNode = new struct InputDataNode;
        NewNode->ch = TempChar;
        NewNode->weight = TempFreq;
        this->InData.push_back(NewNode);
    }
    InData.close();
}

void SelectMinNodes(HuffmanTree& HT, int n, int& s1, int& s2);
void InitTree::CreateHuffTree()
{
    this->Tree.clear();
    int m = 2 * InData.size() - 1; //哈夫曼树总结点数
    HuffmanTree HT = (HuffmanTree)calloc(m + 1, sizeof(HNode)); //开m+1个HTNode，因为下标为0的HTNode不存储数据
    for (int i = 1; i <= (int)InData.size(); i++)
    {
        HT[i].ch = InData[i - 1]->ch;
        HT[i].weight = InData[i - 1]->weight; //赋权值给n个叶子结点
    }
    for (int i = InData.size() + 1; i <= m; i++) //构建哈夫曼树
    {
        //选择权值最小的s1和s2，生成它们的父结点
        int s1, s2;
        SelectMinNodes(HT, i - 1, s1, s2);
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[s1].parent = i; //s1的父亲是i
        HT[s2].parent = i; //s2的父亲是i
        HT[i].lc = s1; //左孩子是s1
        HT[i].rc = s2; //右孩子是s2
    }
    for (int i = 0; i <= m; ++i)
    {
        this->Tree.push_back(&HT[i]);
    }
}

void SelectMinNodes(HuffmanTree& HT, int n, int& s1, int& s2)
{
    int min = 0;
    //找第一个最小值
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            min = i;
            break;
        }
    }
    for (int i = min + 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && HT[i].weight < HT[min].weight)
            min = i;
    }
    s1 = min; //第一个最小值给s1

    //找第二个最小值
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && i != s1)
        {
            min = i;
            break;
        }
    }
    for (int i = min + 1; i <= n; i++)
    {
        if (HT[i].parent == 0 && HT[i].weight < HT[min].weight&&i != s1)
            min = i;
    }
    s2 = min; //第二个最小值给s2
}
void InitTree::WriteFile()
{
    //哈夫曼树中各结点之间的关系
    const string FilePath = "E:\\code\\qt\\SDesign\\SDesign\\file\\hfmTree.txt";
    ofstream OutData;
    OutData.open(FilePath, ios::out);
    for (int i = 1; i < (int)Tree.size(); i++)
    {
        //字符,权值,父结点,左孩子,右孩子
        OutData << i << " ";
        if (Tree[i]->ch != "")
            OutData << Tree[i]->ch << " ";
        else
            OutData << "[NULL]" << " ";

        OutData << Tree[i]->weight << " " << Tree[i]->parent << " " << Tree[i]->lc
                << " " << Tree[i]->rc << " " << endl;
    }
}
const vector<HuffmanTree> InitTree::get_TreeVector()
{
    return this->Tree;
}
