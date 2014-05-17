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
		cerr<<"ȱ���Ҳ�������"<<endl;
		return false;
	}
	s.Pop(right);
	if(s.IsEmpty())
	{
		cerr<<"ȱ�����������"<<endl;
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
	//û��ȡ������������
	else
		Clear();
}

void Calculator::Run()
{
	cout<<"�������׺���ʽ��";
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
		default:cin.putback(ch);    //������ַ����ǲ������������Żص����������Ա��������������䰴һ��������������¶���
			cin>>newOperand;
			s.Push(newOperand);
		}
	}
	cout<<"����ǣ�"<<s.getTop ();
}