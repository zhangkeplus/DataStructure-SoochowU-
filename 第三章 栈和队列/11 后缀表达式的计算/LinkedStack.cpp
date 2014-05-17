#include "LinkedStack.h"
#include<assert.h>
void LinkedStack::Push(const double &x)
{
	LinkNode *p;
	p=new LinkNode(x,top);
	assert(p!=NULL);
	top=p;
	assert(top!=NULL);
}
bool LinkedStack::Pop(double &x)
{
	if(IsEmpty())return false;
	LinkNode *p=top;
	top=top->link ;
	x=p->data ;
	delete p;
	return true;
}
void LinkedStack::MakeEmpty()
{
	LinkNode *p;
	while(top!=NULL)
	{
		p=top;
		top=top->link ;
		delete p;
	}
}
double LinkedStack::getTop()
{
	return top->data ;
}