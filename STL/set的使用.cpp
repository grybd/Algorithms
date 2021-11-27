#include <iostream>
#include <set>
using namespace std;

int main()
{
 set<float> a;
 a.insert(12.3);
 a.insert(60.3);
 a.insert(32.3);
 a.insert(822.1);
 a.insert(41140.1);
 a.insert(44449.8);
 set<float>::iterator p2a= a.begin();
 while(p2a!= a.end())
 {cout<< *p2a<< endl; ++p2a;}
 set<string> b;
 b.insert("bcdefg");
 b.insert("acdefg");
 b.insert("abdefg");
 b.insert("dabcefg");
 b.insert("bcdfg");
 b.insert("fabcdeg");
 set<string>::iterator p2= b.begin();
 while(p2!= b.end())
 {cout<< *p2<< endl; ++p2;}
 return 0;
}
