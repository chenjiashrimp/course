/*
描述
我们知道如何按照三种深度优先次序来周游一棵二叉树，来得到中根序列、前根序列和后根序列。反过来，如果给定二叉树的中根序列和后根序列，或者给定中根序列和前根序列，可以重建一二叉树。本题输入一棵二叉树的中根序列和后根序列，要求在内存中重建二叉树，最后输出这棵二叉树的前根序列。

用不同的整数来唯一标识二叉树的每一个结点，下面的二叉树



中根序列是9 5 32 67

后根序列9 32 67 5

前根序列5 9 67 32

输入
两行。第一行是二叉树的中根序列，第二行是后根序列。每个数字表示的结点之间用空格隔开。结点数字范围0～65535。暂不必考虑不合理的输入数据。
输出
一行。由输入中的中根序列和后根序列重建的二叉树的前根序列。每个数字表示的结点之间用空格隔开。
样例输入
9 5 32 67
9 32 67 5
样例输出
5 9 67 32
*/

#include<iostream>
using namespace std;
typedef struct _btn {
    int data;
    struct _btn* lchild;
    struct _btn* rchild;
}btn;
#define MAXN 65536
int inOrder[MAXN];
int postOrder[MAXN];
btn* buildtree(int io1, int io2, int po1, int po2)//中序的首尾元素坐标，后序的首尾元素坐标
{
    int iolen = io2 - io1 + 1;//中序的长度
    int i;
    btn* root = new btn;//新建的一个结点作为根结点
    root->data = postOrder[po2];//后序的最后一个元素是根结点
    root->lchild = NULL;
    root->rchild = NULL;//左右孩子初始化为空
    //在中序里寻找根结点
    for (i = 0;i < iolen;++i)
    {
        if (root->data == inOrder[io1 + i])
            break;
    }
    //于是左子树的中序从io1到io1+i-1,后序从po1到po1+i-1
    //注意递归出口，只有当io1<=io1+i-1即i>=1时才有意义
    if (i >= 1)
        root->lchild = buildtree(io1, io1 + i - 1, po1, po1 + i - 1);
    //右子树类似
    if (io1 + i + 1 <= io2)
        root->rchild = buildtree(io1 + i + 1, io2, po1 + i, po2 - 1);
    //返回根结点
    return root;
}
void preOrder(btn* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
//后序遍历，用于释放二叉树
void deletetree(btn* root)
{
    if (root != NULL)
    {
        deletetree(root->lchild);
        deletetree(root->rchild);
        delete root;
        root = NULL;
    }
}
int main()
{
    int i = 0;
    while (cin >> inOrder[i++])
    {
        if (cin.get() != ' ')
            break;
    }
    i = 0;
    while (cin >> postOrder[i++])
    {
        if (cin.get() != ' ')
            break;
    }
    btn* root = buildtree(0, i - 1, 0, i - 1);
    preOrder(root);
    deletetree(root);
    return 0;
}
