#include "queue.h"
#include<iostream>
template <class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T> *leftChild,*rightChild;
	BinTreeNode():leftChild(NULL),rightChild(NULL){}
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL)
		:data(x),leftChild(l),rightChild(r){}
};

template <class T>
class BinaryTree
{
public:
	BinaryTree():root(NULL){}
	BinaryTree(T value):RefValue(value),root(NULL){}
	bool IsEmpty(){return root==NULL}
	BinTreeNode<T> *createBinaryTree(T *VLR, T *LVR, int n); //利用前序序列和中序序列构造二叉树
	void preOrder(BinTreeNode<T> *p); //先序遍历
	void inOrder(BinTreeNode<T> *p);  //中序遍历
	void postOrder(BinTreeNode<T> *p);//后序遍历
	void levelOrder(BinTreeNode<T> *p);//层序遍历
	void exchangeNode(BinTreeNode<T> *p);//交换二叉树所有结点的左右子树
	BinTreeNode<T> *getRoot()const {return root;}
private:
	BinTreeNode<T> *root;
//	T RefValue;      //数据输入停止标志
};
template <class T>
BinTreeNode<T> *BinaryTree<T>::createBinaryTree(T *VLR, T *LVR, int n)
{
	if(n==0) return NULL;
	int k=0;
	while(VLR[0]!=LVR[k]) k++; //在中序序列中寻找根
	BinTreeNode<T> *t = new BinTreeNode<T>(VLR[0]);//创建根结点
	t->leftChild = createBinaryTree(VLR+1,LVR,k);//从前序VLR+1开始对中序的0到k-1左子序列的k个元素递归建立左子树
	t->rightChild = createBinaryTree(VLR+k+1,LVR+k+1,n-k-1);//从前序VLR+k+1开始对中序的k+1到n-1右子序列的n-k-1个元素建立右子树
	return t;
};

template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T> *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		preOrder(p->leftChild);
		preOrder(p->rightChild);
	}
};

template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T> *p)
{
	if(p!=NULL)
	{
		inOrder(p->leftChild);
		cout<<p->data<<" ";
		inOrder(p->rightChild);
	}
};

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T> *p)
{
	if(p!=NULL)
	{
		postOrder(p->leftChild);
		postOrder(p->rightChild);
		cout<<p->data<<" ";
	}
};

template<class T>
void BinaryTree<T>::levelOrder(BinTreeNode<T> *p)
{
	LinkedQueue<BinTreeNode<T>*> Q;
//	BinTreeNode<T> *p = root;
	Q.EnQueue(p);
	while(!Q.IsEmpty())
	{
		Q.DeQueue(p);
		cout<<p->data<<" ";
		if(p->leftChild!=NULL) Q.EnQueue(p->leftChild);
		if(p->rightChild!=NULL)Q.EnQueue(p->rightChild);
	}
};


template<class T>
void BinaryTree<T>::exchangeNode(BinTreeNode<T> *p)
{
	if(p!=NULL)
	{
		BinTreeNode<T> *temp = p->leftChild;
		p->leftChild = p->rightChild ;
		p->rightChild = temp;
		exchangeNode(p->leftChild);
		exchangeNode(p->rightChild);
	}
};