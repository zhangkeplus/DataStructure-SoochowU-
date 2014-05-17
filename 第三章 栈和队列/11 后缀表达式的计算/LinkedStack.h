#pragma once
#include<iostream>
class LinkedStack
{
public:
	LinkedStack():top(NULL){}
	void Push(const double& x);
	bool Pop(double& x);
	void MakeEmpty();
	bool IsEmpty()const{return(top==NULL)?true:false;}
	double getTop();
private:
	struct LinkNode
	{
		double data;
		LinkNode *link;
		LinkNode(LinkNode *ptr=NULL)
		{
			link=ptr;
		}
		LinkNode(const double &item , LinkNode *ptr=NULL)
		{
			data=item;
			link=ptr;
		}
	};
	LinkNode *top;
};
