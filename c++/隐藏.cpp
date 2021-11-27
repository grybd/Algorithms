#include <bits/stdc++.h>
using namespace std;

void hidefunc(char* pstr)
{
	cout << "global function: " << pstr << endl;
}

class HideA
{
public:
	void hidefunc()
	{
		cout << "HideA function" << endl;
	}
	void usehidefunc()
	{
		//隐藏外部函数hidefunc，使用外部函数时要加作用域
		hidefunc();
		::hidefunc("lvlv");
	}
};

class HideB : public HideA
{
public:
	void hidefunc()
	{
		cout << "HideB function" << endl;
	}
	void usehidefunc()
	{
		//隐藏基类函数hidefunc，使用外部函数时要加作用域
		hidefunc();
		HideA::hidefunc();
	}
};

int main(){
  HideB *b = new HideB();
  b->usehidefunc();
}
