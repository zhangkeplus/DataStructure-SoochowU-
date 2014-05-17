#include "Calculator.h"
#include<iostream>
using namespace std;
Calculator::Calculator()
{
	LinkedStack s;
}
void Calculator::Clear ()
{
	s.MakeEmpty ();
}
bool Calculator::Get2_Operands (double& left,double& right)
{
	if(s.IsEmpty())
	{
		cerr<<"缺少右操作数！"<<endl;
		return false;
	}
	s.Pop(right);
	if(s.IsEmpty())
	{
		cerr<<"缺少左操作数！"<<endl;
		return false;
	}
	s.Pop(left);
	return true;
}

//void Calculator::AddOperand (double value)
//{
//	s.Push (value);
//}
void Calculator::DoOperator(char op)
{
	double left,right,value;
    bool result;
	result=Get2_Operands(left,right);
	if(result)
	{
		switch (op)
		{
		case '+':value=left+right;s.Push (value);break;
		case '-':value=left-right;s.Push (value);break;
		case '*':value=left*right;s.Push (value);break;
		case '/':if(right==0.0)
				 {
					 cerr<<"Divide by 0!"<<endl;
					 Clear();
				 }
				 else
				 {
					 value=left/right;s.Push (value);
				 }
				 break;
		}
	}
	//没有取到两个操作数
	else
		Clear();
}

void Calculator::Run()
{
	cout<<"请输入后缀表达式：";
	char ch;double newOperand;
	while(cin>>ch && ch!='#')
	{
		switch(ch)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			DoOperator(ch);break;
		default:cin.putback(ch);    //读入的字符不是操作符，将它放回到输入流中以便能用流操作将其按一个浮点操作数重新读入
			cin>>newOperand;
			s.Push(newOperand);
		}
	}
	cout<<"结果是："<<s.getTop ();
}