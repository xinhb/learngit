 ///
 /// @file    reference1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-20 22:42:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int a=10;
	int &refa=a;
	cout << "a=" << a << endl;

	int b=20;
	refa=b;
	cout << "a=" << a << endl;
 





}
