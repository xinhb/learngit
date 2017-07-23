 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-23 20:52:02
 ///
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
public:
	Stack();

	void push(int);

	void pop();

	int top();

	bool empty();

	bool full();

private:
	int  _a[10]; //给栈中的每个对象申请10个整型数据空间
	int  _t;   //栈空间数组下标
};

Stack::Stack()
{
	_t=-1;  //初始化栈数组，将下标设为-1
}

void Stack::push(int i)  
{                       
	if(_t >= 9)         //判断是否满栈
	{
		exit(-1);
	}else{             //将元素i入栈
		_a[++ _t] = i;
	}
}
	
void Stack::pop()
{
	if(_t <= -1)
	{
		exit(-1);
	}else{
		_t --;
	}
}

int Stack::top()
{
	return _a[_t];
}

bool Stack::empty()           
{
	if(_t == -1) return 1;      
	else return 0;
}

bool Stack::full()
{
	if(_t == 9) return 1;  //判断是否满栈，返回值bool类型
	else return 0;
}


int main()
{
	Stack st1;     //创建栈类对象st1
	st1.push(10);
	st1.push(12);
	st1.push(14);
	cout << "栈顶=" << st1.top() << endl;
	st1.pop();
	cout << "栈顶=" << st1.top() << endl;
	return 0;
}
