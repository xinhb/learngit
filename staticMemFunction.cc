 ///
 /// @file    Computer3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 11:37:34
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, float fprice);

	~Computer();

	Computer(const Computer & rhs);

	Computer & operator=(const Computer & rhs);

	void print();

	//因为静态成员函数参数之中不包含this指针
	//
	//所以在其内部不直接非静态数据成员以及成员函数
	//只能访问静态数据成员和成员函数
	static void printTotal()
	{
		//print();//error
		//cout << "品牌:" << _brand << endl;//error
		cout << "总价: "<< _totalPrice << endl;
	}

	static void printCompter(const Computer & com)
	{
		cout << "品牌:" << com._brand << endl;
		cout << "价格:" << com._fprice << endl;
	}

private:
	char * _brand;
	float _fprice;
	static float _totalPrice;
};


float Computer::_totalPrice = 0.0;

Computer::Computer(const char * brand, float fprice)
: _brand(new char[strlen(brand) + 1]())
, _fprice(fprice)
{
	cout << "Computer(const char*, float)" << endl;
	strcpy(_brand, brand);//深拷贝

	_totalPrice += _fprice;
}

Computer::~Computer()
{
	delete [] _brand;
	cout << "~Computer()" << endl;
	_totalPrice -= _fprice;
}

Computer::Computer(const Computer & rhs)
: _brand(new char[strlen(rhs._brand) + 1]()) //深拷贝
, _fprice(rhs._fprice)
{
	cout << "Computer(const Computer&)" << endl;
	strcpy(_brand, rhs._brand);
}


Computer & Computer::operator=(const Computer & rhs)
{
	if(this != &rhs) //1. 考虑自复制
	{
		delete [] _brand;//2. 回收左操作数的空间
		_brand = new char[strlen(rhs._brand) + 1]();//3. 再去进行深拷贝
		strcpy(_brand, rhs._brand);
		_fprice = rhs._fprice;
	}
	return *this;
}

void Computer::print()
{
	cout << "品牌:" << _brand << endl;
	cout << "价格:" << _fprice << endl;
}

int main(void)
{
	Computer c1("Lenovo", 5000);
	//c1.print();
	//c1.printCompter(c1);
	Computer::printCompter(c1);//静态成员函数直接通过类名进行访问
	Computer::printTotal();

	Computer c2("Mac", 10000);
	//c2.print();
	Computer::printCompter(c2);
	Computer::printTotal();

	Computer c3("ThinkPad", 7000);
	//c3.print();
	Computer::printCompter(c3);
	Computer::printTotal();

	return 0;
}
