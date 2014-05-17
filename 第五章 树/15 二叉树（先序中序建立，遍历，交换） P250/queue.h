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
	bool IsEmpty()const{return (front==NULL);}
private:
	LinkNode1<T> *front ,*rear;
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