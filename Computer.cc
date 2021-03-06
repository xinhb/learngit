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
private:
	char * _brand;
	float _fprice;
};

Computer::Computer(const char * brand, float fprice)
: _brand(new char[strlen(brand) + 1]())
, _fprice(fprice)
{
	cout << "Computer(const char*, float)" << endl;
	strcpy(_brand, brand);//深拷贝
}

Computer::~Computer()
{//析构函数的作用：做清理工作
	delete [] _brand;
	cout << "~Computer()" << endl;
}

#if 0
//系统提供的复制构造函数不再满足需要
Computer::Computer(const Computer & rhs)
: _brand(rhs._brand) //浅拷贝
, _fprice(rhs._fprice)
{
	cout << "Computer(const Computer&)" << endl;
}
#endif

Computer::Computer(const Computer & rhs)
: _brand(new char[strlen(rhs._brand) + 1]()) //深拷贝
, _fprice(rhs._fprice)
{
	cout << "Computer(const Computer&)" << endl;
	strcpy(_brand, rhs._brand);
}


//系统提供的赋值运算符函数是有问题的，不满足需要
#if 0
Computer & Computer::operator=(const Computer & rhs)
{
	_brand = rhs._brand;//浅拷贝
	_fprice = rhs._fprice;
	return *this;
}
#endif

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
	cout << "c1 = ";
	c1.print();

	//Computer c2 = c1;//执行复制构造函数
	//c2.print();

	Computer c3("Mac", 10000);
	cout << "c3 = ";
	c3.print();

	c1 = c3;
	//c1.operator=(c3);

	cout << "c1 = ";
	c1.print();
	cout << "=====" << endl;

	c1 = c1;//自复制
	cout << "c1 = ";
	c1.print();

	return 0;
}
