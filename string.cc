 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-23 16:46:55
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();                               //显式无参构造函数

	String(const char *pstr);               //显式有参构造函数

	String(const String & rhs);            //复制构造函数

	String & operator=(const String & rhs); //赋值运算符函数

	~String();

	void print();                          //打印函数

	
private:
	char * _pstr;
};


String::String() //不带参数
{
	_pstr = new char[strlen("hello world")+1]; //申请堆空间
	strcpy(_pstr,"hello world");//复制字符到成员变量_pstr中
	cout << "String()" << endl;
}

String::String(const char *pstr) //带参数
{
	_pstr = new char[strlen(pstr)+1];
	strcpy(_pstr,pstr);
	cout << "String(const char * pstr)" << endl;
}

String::String(const String & rhs)   //复制构造函数,类外定义成员函数
{
	_pstr = new char[strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);
	cout <<" String(const String & rhs)" << endl;	
}

String & String::operator=(const String & rhs) //赋值运算符函数，类外定义成员函数
{
	if(this != &rhs)//考虑到自复制的情况
	{
		delete []_pstr;//回收左操作数的空间
		_pstr=new char[strlen(rhs._pstr)+1];//再去深拷贝
		strcpy(_pstr,rhs._pstr);
		cout << "String & operator=(const String & rhs)" << endl;
	}
	return *this;

}
void String::print()
{
	cout << "_pstr=" << _pstr << endl;
}

String::~String()
{
	delete [] _pstr;
	cout << "~String()" << endl;
}


int main()
{
	String str1;
	str1.print();

	String str2="Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4 = str3;  //实现复制构造函数
	str4.print();

	str4 = str2;   //实现赋值运算符函数
	str4.print();

	return 0;
}





