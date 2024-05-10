#include "DrawHuffTree.h"
#include <QString>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QDebug>

DrawHuffTree::DrawHuffTree(QWidget *parent) : QWidget(parent)
{
    this->resize(1280,720);
    this->setWindowTitle("查看赫夫曼树");
    this->setAttribute(Qt::WA_DeleteOnClose,true);
}

void DrawHuffTree::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPen pen;
    pen.setColor(QColor(0,0,0,255));
    QBrush brush;
    brush.setColor(QColor(0,0,0,0));
    brush.setStyle(Qt::SolidPattern);
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    QFont font;
    font.setFamily("Consolas");
    font.setPointSize(16);
    font.setItalic(false);
    painter.setFont(font);

    int n = 26;
    //this->Tree.erase(Tree.begin());
    //painter.drawText(100, 20,QString::number(Tree.size()));
    Tree[2 * n - 1]->idx = 1;
    Tree[2 * n - 1]->idy = 1;
    for (int i = 2 * n - 1; i > n; i--)
    {
        Tree[Tree[i]->lc]->idx = 2 * Tree[i]->idx;
        Tree[Tree[i]->rc]->idx = 2 * Tree[i]->idx + 1;

        Tree[Tree[i]->lc]->idy = 2 * Tree[i]->idy;
        Tree[Tree[i]->rc]->idy = 2 * Tree[i]->idy + 1;
    }

    for (int i = 2 * n - 1; i > 0; i--) // 为idx域赋值
        Tree[i]->idx = Tree[i]->idx / pow(2, (int)(log10(Tree[i]->idx) / log10(2)));
    for (int i = 1; i <= n; i++) // 求出每个i叶子节点的idx排序
    {
        int k = 1;
        for (int j = 1; j <= n; j++)
        {
            if (Tree[j]->idx < Tree[i]->idx)
                k++;
        }
        //k增序排名
        Tree[i]->pos.x = 300 + k * 30; // 根据叶子节点的idx排序求出叶子节点的x坐标
    }
    for (int i = n + 1; i <= 2 * n - 1; i++) // 根据叶子节点求出双亲的x坐标
        Tree[i]->pos.x = (Tree[Tree[i]->lc]->pos.x + Tree[Tree[i]->rc]->pos.x) / 2;
    for (int i = 1; i <= 2 * n - 1; i++)
        Tree[i]->pos.y = 40 * int(log10(Tree[i]->idy) / log10(2)); // 根据节点的层数求出节点的y坐标

    for (int i = 1; i <= n; i++) // 输出每个字符及其对应的概率、编码
    {
        painter.drawText(20, 20 * (i + 1), QString::fromStdString(Tree[i]->ch));
        painter.drawText(50, 20 * (i + 1), QString::number(Tree[i]->weight));
        painter.drawText(110, 20 * (i + 1), QString::fromStdString(Code[Tree[i]->ch]));
    }

    for (int i = 1; i <= 2 * n - 1; i++) // 绘制节点小圆
    {
        painter.drawEllipse((int)Tree[i]->pos.x - 105, 95 + (int)Tree[i]->pos.y, 10 ,10);
        if (Tree[i]->lc == 0 && Tree[i]->rc == 0)//叶子节点的字符
            painter.drawText((int)Tree[i]->pos.x - 100, 105 + (int)Tree[i]->pos.y, QString::fromStdString(Tree[i]->ch));
        else // 绘制节点的左右子树
        {
            painter.drawText((int)(Tree[i]->pos.x + Tree[Tree[i]->lc]->pos.x) / 2 - 100, // 左子树标0
                      (int)(Tree[i]->pos.y + Tree[Tree[i]->lc]->pos.y) / 2 + 100, "0");
            painter.drawText((int)(Tree[i]->pos.x + Tree[Tree[i]->rc]->pos.x) / 2 - 100, // 右子树标1
                      (int)(Tree[i]->pos.y + Tree[Tree[i]->rc]->pos.y) / 2 + 100, "1");

            painter.drawLine((int)Tree[i]->pos.x - 100, (int)Tree[i]->pos.y + 100, // 绘制节点与左子树的连线
                 (int)Tree[Tree[i]->lc]->pos.x - 100, (int)Tree[Tree[i]->lc]->pos.y + 100);
            painter.drawLine((int)Tree[i]->pos.x - 100, (int)Tree[i]->pos.y + 100, // 绘制节点与右子树的连线
                 (int)Tree[Tree[i]->rc]->pos.x - 100, (int)Tree[Tree[i]->rc]->pos.y + 100);

        }
    }
}
void DrawHuffTree::set_Code(map<string,string> tempCode)
{
    this->Code = tempCode;
}
void DrawHuffTree::set_TreeVector(vector<HuffmanTree> TempTree)
{
    this->Tree.clear();
    this->Tree = TempTree;
}
