#pragma once

#include "LinkedStack.h"
#include<cmath>
class Calculator
{
public:
	Calculator();            //���캯��������һ��ջ��
	void Run();             //ִ�б��ʽ����
	void Clear();           //���
private:
	LinkedStack s;          //ջ������
	void AddOperand(double value);                 //��������ջ
	bool Get2_Operands(double& left,double& right); //��ջ���˳�����������
	void DoOperator(char op);                      //�γ�����ָ���������
};

