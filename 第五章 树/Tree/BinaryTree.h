#include "stack.h"
#include<iostream>
#include<fstream>
template<class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode():leftChild(NULL),rightChild(NULL){}
	BinTreeNode(T x, BinTreeNode<T> *l=NULL, BinTreeNode<T> *r=NULL)
		:data(x),leftChild(l),rightChild(r){}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree():root(NULL){}
	BinaryTree(T value):RefValue(value),root(NULL){}
	BinTreeNode<T> *getRoot(){return root;}
	void createBinTree(istream &in, BinTreeNode<T> * &BT);//采用广义表建立二叉树
	void createBinTree_pre(ifstream &in, BinTreeNode<T> * &subTree);//利用前序遍历建立二叉树
	void preOrder(BinTreeNode<T> *p);//广义表形式输出
	void destroy(BinTreeNode<T> *p);//删除根为p的子树
	int size(BinTreeNode<T> *p)const;//计算以*p为根的二叉树的结点个数
	int height(BinTreeNode<T> *p)const;//计算以*p为根的二叉树的高度
	BinTreeNode<T> *copy(BinTreeNode<T> *orignode);//复制
	BinaryTree(BinaryTree<T> &s);                  //复制构造函数
protected:
	BinTreeNode<T> *root;
	T RefValue;
};

template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T> *p)
{
	if(p!=NULL)
	{
		cout<<p->data;
		if(p->leftChild!=NULL || p->rightChild!=NULL)
		{
			cout<<'(';
			preOrder(p->leftChild);
			cout<<',';
			if(p->rightChild!=NULL)
				preOrder(p->rightChild);
			cout<<')';
		}
	}
};

template<class T> 
void BinaryTree<T>::createBinTree(istream &in, BinTreeNode<T> *&BT)
{
	cout<<"输入数据：";
	LinkedStack<BinTreeNode<T> *> s;
	BT = NULL;
	BinTreeNode<T> *p,*t;int k;
	T ch;
	in>>ch;
	while(ch!=RefValue)
	{
		switch(ch)
		{
		case '(':s.Push(p);k=1;break;    //子表开始，将k置1
		case ')':s.Pop(t);break;         //子表结束
		case ',':k=2;break;              //以左子树为根的子树处理完毕，应接着处理以右子女为根的子树，将 k 置2
		default:p = new BinTreeNode<T>(ch);
			if(BT==NULL)
			{ 
				BT=p;
				root=BT;  //根结点
			}
			else if(k==1)
			{
				s.getTop(t);t->leftChild=p;
			}
			else
			{
				s.getTop(t);t->rightChild=p;
			}
		}
		in>>ch;
	}
};
template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *p)
{
	if(p!=NULL)
	{
		destroy(p->leftChild);
		destroy(p->rightChild);
		delete p;
	}
};
template<class T>
int BinaryTree<T>::size(BinTreeNode<T> *p) const
{
	if(p==NULL) return 0;
	else return 1+size(p->leftChild)+size(p->rightChild);
};
template<class T>
int BinaryTree<T>::height(BinTreeNode<T> *p) const
{
	if(p==NULL)return 0;
	else
	{
		int i = height(p->leftChild);
		int j = height(p->rightChild);
		return (i<j) ? j+1 : i+1;
	}
};


template<class T>
BinTreeNode<T> *BinaryTree<T>::copy(BinTreeNode<T> *orignode)
{
	if(orignode==NULL)return NULL;
	BinTreeNode<T> *temp = new BinTreeNode<T>;//创建根结点
	temp->data = orignode->data;              //传送数据 
	temp->leftChild = copy(orignode->leftChild);
	temp->rightChild = copy(orignode->rightChild);
	return temp;
};
template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &s)
{
	root = copy(s.root);
};
template<class T>
void BinaryTree<T>::createBinTree_pre(ifstream &in, BinTreeNode<T> *&subTree)
{
	T item;
	while(!in.eof())
	{
		in>>item;
		if(item!=RefValue)
		{
			subTree = new BinTreeNode<T>(item);
			if(subTree==NULL){cerr<<"wrong"<<endl;exit(1);}
			createBinTree_pre(in,subTree->leftChild);
			createBinTree_pre(in,subTree->rightChild);
		}
		else
			subTree = NULL;
	}
};