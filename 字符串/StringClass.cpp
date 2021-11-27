#include <bits/stdc++.h>
using namespace std;

class Mystring
{
	public:
				//Mystring(void);
				Mystring(const char* str = NULL);
				Mystring(const Mystring& str);
				Mystring&  operator = (const Mystring& str);
				~Mystring(void);
	private:
				char* str_data;
};
Mystring :: Mystring(const char* str)
{
	if(str == NULL)
	{
		str_data = new char[1];
		str_data[0] = '\0' ;
	}
	else
	{
			str_data = new char[strlen(str)+1];
			strcpy(str_data,str);//strcoy 会自动在后面加'\0'
	}
}
Mystring :: Mystring(const Mystring& str)
{
	str_data = new char[strlen(str.str_data)+1];
	strcpy(str_data,str.str_data);
}

Mystring& Mystring:: operator = (const Mystring& str)
{
		if(this ==&str)
		{
			return *this;
		}

		delete str_data;
		str_data = new char[strlen(str.str_data)+1]  ;
		strcpy(str_data,str.str_data);
		return *this;
}
Mystring::~Mystring()
{
	if(str_data!=NULL)
	{
		delete str_data;
		str_data = NULL;
	}
}
