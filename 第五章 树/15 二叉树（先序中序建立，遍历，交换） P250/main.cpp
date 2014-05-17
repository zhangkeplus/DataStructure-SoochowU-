//根据二叉树的先序和中序序列建立二叉树的二叉链表存储结构，输出先序 中序 后序和层序序列，交换二叉树所有结点的左右子树，
//再输出先序 中序 后序 和层序的序列
#include "BinaryTree.h"
#include<iostream>
using namespace std;
int main()
{
	int pre[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int in[12]={4,3,6,5,2,7,8,1,9,11,10,12};
	BinaryTree<int> tree;
	BinTreeNode<int> *sub = tree.createBinaryTree(pre,in,12);
	cout<<"先序序列输出：";
	tree.preOrder(sub);
	cout<<endl<<"中序序列输出：";
	tree.inOrder(sub);
	cout<<endl<<"后序序列输出：";
	tree.postOrder(sub);
	cout<<endl<<"层序序列输出：";
	tree.levelOrder(sub);
	cout<<endl;

	tree.exchangeNode(sub);
	cout<<"交换后："<<endl;
	cout<<"先序序列输出：";
	tree.preOrder(sub);
	cout<<endl<<"中序序列输出：";
	tree.inOrder(sub);
	cout<<endl<<"后序序列输出：";
	tree.postOrder(sub);
	cout<<endl<<"层序序列输出：";
	tree.levelOrder(sub);

}