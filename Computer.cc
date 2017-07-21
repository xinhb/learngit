 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-21 15:46:54
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer    //声明类，类的默认权限是private
{
public:
	void print()
	{
		cout << "品牌:" << _brand << endl;
		cout << "价格:" << _fprice << endl;
	}
	void setBrand(const char * brand)
	{
		strcpy(_brand ,brand);
	}
	void setPrice(float fprice)
	{
		_fprice=fprice; 
	}
private:
	char _brand[20];
	float _fprice;
}; //定义类时，注意不要漏了分号

int main(void)
{
	Computer c1;    //定义类中的一个对象c1
	c1.setPrice (500);
	c1.setBrand ("LENOVO");    //对象c1调用类中的函数
	c1.print();
	return 0;
}








