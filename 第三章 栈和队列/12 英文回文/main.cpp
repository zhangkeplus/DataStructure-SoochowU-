//1.正读和反读一样的字符串成为英文回文，字符串中的非英文字母不算，大写和小写字母等价，如
// Rise to vote, sir.
// No lemons no melon.
// Was it a car or a cat I saw ?
//编写判断一个字符串是否为英文回文的程序，要求用一个栈和一个队列
#include<iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"
using namespace std;
int main()
{
	bool flag = true;
	char ch,s,q;
	LinkedStack<char> a;
	LinkedQueue<char> b;
	cin>>ch;
	while (ch!='#')
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			ch+=32;
			a.Push(ch);
			b.EnQueue(ch);
		}
		else if(ch >= 'a' && ch <= 'z')
		{
			a.Push (ch);
			b.EnQueue (ch);
		}
		cin>>ch;
	}
	while(!a.IsEmpty ())
	{
		a.Pop(s);
		b.DeQueue(q);
		if(s!=q)
		{
			flag=false;
			break;
		}
	}
	if(flag)
		cout<<" 是英文回文!";
	else
		cout<<"不是英文回文!";
}