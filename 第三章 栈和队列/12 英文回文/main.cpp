//1.�����ͷ���һ�����ַ�����ΪӢ�Ļ��ģ��ַ����еķ�Ӣ����ĸ���㣬��д��Сд��ĸ�ȼۣ���
// Rise to vote, sir.
// No lemons no melon.
// Was it a car or a cat I saw ?
//��д�ж�һ���ַ����Ƿ�ΪӢ�Ļ��ĵĳ���Ҫ����һ��ջ��һ������
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
		cout<<" ��Ӣ�Ļ���!";
	else
		cout<<"����Ӣ�Ļ���!";
}