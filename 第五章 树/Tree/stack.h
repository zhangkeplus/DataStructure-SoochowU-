#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
struct LinkNode
{
	T data;
	LinkNode<T> *link;
	LinkNode(LinkNode<T> *ptr=NULL)
	{
		link=ptr;
	}
	LinkNode(const T &item , LinkNode<T> *ptr=NULL)
	{
		data=item;
		link=ptr;
	}
};
template<class T>
class LinkedStack
{
public:
	LinkedStack():top(NULL){}
	void Push(const T& x);
	bool Pop(T& x);
	bool getTop(T& x)const;
	bool IsEmpty()const{return(top==NULL);}
	int getSize()const;
	void input();
	void output();
private:
	LinkNode<T> *top;
};
template<class T>
void LinkedStack<T>::Push(const T &x)
{
	LinkNode<T> *p;
	p=new LinkNode<T>(x,top);
	assert(p!=NULL);
	top=p;
	assert(top!=NULL);
};
template<class T>
bool LinkedStack<T>::Pop(T &x)
{
	if(IsEmpty())return false;
	LinkNode<T> *p=top;
	top=top->link ;
	x=p->data ;
	delete p;
	return true;
};
template<class T>
bool LinkedStack<T>::getTop(T &x) const
{
   if(IsEmpty())return false;
	x=top->data ;
	return true;
};