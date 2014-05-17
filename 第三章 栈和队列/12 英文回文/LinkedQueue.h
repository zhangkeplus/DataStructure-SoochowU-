#include<iostream>
template<class T>	
struct LinkNode1
{
	T data;
	LinkNode1<T> *link;
	LinkNode1(LinkNode1<T> *ptr=NULL)
	{
		link=ptr;
	}
	LinkNode1(const T &item , LinkNode1<T> *ptr=NULL)
	{
		data=item;
		link=ptr;
	}
};
template<class T>
class LinkedQueue
{
public:
	LinkedQueue():rear(NULL),front(NULL){}
	bool EnQueue(const T &x);
	bool DeQueue(T &x);
	bool getFront(T &x)const;
	void makeEmpty();
	bool IsEmpty()const{return (front==NULL);}
	int getSize()const;
private:
	LinkNode1<T> *front ,*rear;
};

template<class T>
void LinkedQueue<T>::makeEmpty ()
{
	linkNode1<T> *p;
	while(front!=NULL)
	{
		p=front;
		front=front->link ;
		delete p;
	}
};
template<class T>
bool LinkedQueue<T>::EnQueue(const T &x)
{
	if(front==NULL)
	{
		front=rear=new LinkNode1<T>(x);
		if(front==NULL)
			return false;
	}
	else
	{
		rear->link =new LinkNode1<T>(x);
		if(rear->link ==NULL)
			return false;
		rear=rear->link ;
	}
	return true;
};
template<class T>
bool LinkedQueue<T>::DeQueue(T &x)
{
	if(IsEmpty())
		return false;
	LinkNode1<T> *p=front;
	x=front->data ;
	front=front->link ;
	delete p;
	return true;
};
template<class T>
bool LinkedQueue<T>::getFront(T &x) const
{
	if(IsEmpty()) return false;
	x=front->data ;
	return true;
};
template<class T>
int LinkedQueue<T>::getSize()const
{
	LinkNode1<T> *p=front;
	int k=0;
	while(p!=NULL)
	{
		p=p->link ;
		k++;
	}
	return k;
};