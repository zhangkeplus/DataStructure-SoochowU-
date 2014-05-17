#pragma once

#include "LinkedStack.h"
#include<cmath>
class Calculator
{
public:
	Calculator();            //构造函数（建立一个栈）
	void Run();             //执行表达式计算
	void Clear();           //清空
private:
	LinkedStack s;          //栈对象定义
	void AddOperand(double value);                 //操作数进栈
	bool Get2_Operands(double& left,double& right); //从栈中退出两个操作数
	void DoOperator(char op);                      //形成运算指令，进行运算
};

