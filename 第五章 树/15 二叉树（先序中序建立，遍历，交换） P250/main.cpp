//���ݶ�������������������н����������Ķ�������洢�ṹ��������� ���� ����Ͳ������У��������������н�������������
//��������� ���� ���� �Ͳ��������
#include "BinaryTree.h"
#include<iostream>
using namespace std;
int main()
{
	int pre[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int in[12]={4,3,6,5,2,7,8,1,9,11,10,12};
	BinaryTree<int> tree;
	BinTreeNode<int> *sub = tree.createBinaryTree(pre,in,12);
	cout<<"�������������";
	tree.preOrder(sub);
	cout<<endl<<"�������������";
	tree.inOrder(sub);
	cout<<endl<<"�������������";
	tree.postOrder(sub);
	cout<<endl<<"�������������";
	tree.levelOrder(sub);
	cout<<endl;

	tree.exchangeNode(sub);
	cout<<"������"<<endl;
	cout<<"�������������";
	tree.preOrder(sub);
	cout<<endl<<"�������������";
	tree.inOrder(sub);
	cout<<endl<<"�������������";
	tree.postOrder(sub);
	cout<<endl<<"�������������";
	tree.levelOrder(sub);

}