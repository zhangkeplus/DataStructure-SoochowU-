#include<iostream>
#include "BinaryTree.h"
using namespace std;
int main()
{
	ifstream in("F:\\1.txt");
	BinaryTree<char> tree('#');
	
	BinTreeNode<char> *bt;
	tree.createBinTree(in,bt);
	tree.preOrder(bt);


//	BinaryTree<char> ke(tree);
//	ke.preOrder(ke.getRoot());
}