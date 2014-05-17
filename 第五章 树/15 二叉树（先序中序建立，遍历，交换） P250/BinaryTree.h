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
	BinTreeNode<T> *createBinaryTree(T *VLR, T *LVR, int n); //����ǰ�����к��������й��������
	void preOrder(BinTreeNode<T> *p); //�������
	void inOrder(BinTreeNode<T> *p);  //�������
	void postOrder(BinTreeNode<T> *p);//�������
	void levelOrder(BinTreeNode<T> *p);//�������
	void exchangeNode(BinTreeNode<T> *p);//�������������н�����������
	BinTreeNode<T> *getRoot()const {return root;}
private:
	BinTreeNode<T> *root;
//	T RefValue;      //��������ֹͣ��־
};
template <class T>
BinTreeNode<T> *BinaryTree<T>::createBinaryTree(T *VLR, T *LVR, int n)
{
	if(n==0) return NULL;
	int k=0;
	while(VLR[0]!=LVR[k]) k++; //������������Ѱ�Ҹ�
	BinTreeNode<T> *t = new BinTreeNode<T>(VLR[0]);//���������
	t->leftChild = createBinaryTree(VLR+1,LVR,k);//��ǰ��VLR+1��ʼ�������0��k-1�������е�k��Ԫ�صݹ齨��������
	t->rightChild = createBinaryTree(VLR+k+1,LVR+k+1,n-k-1);//��ǰ��VLR+k+1��ʼ�������k+1��n-1�������е�n-k-1��Ԫ�ؽ���������
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