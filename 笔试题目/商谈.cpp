// write your code here
#include <bits/stdc++.h>
using namespace std;

static int count_1,count_2;

class Person{
   public:
     string name;
     int age;
     virtual int GetDressed(){cout <<count_1+count_2<<endl; return count_1+count_2;};
};
class man:public Person{
   public:
   man(string name_,int age_):name(name_),age(age_){count_1++;}
   string name;
   int  age;
   int GetDressed(){cout<<count_1<<endl; return count_1;}
};
class woman:public Person{
   public:
   woman(string name_,int age_):name(name_),age(age_){count_2++;}
   string name;
   int  age;
   int GetDressed(){cout<<count_2<<endl;return count_2;}
};
int main(){
    string a,b,c,d;
    Person* m = new man(a,10);
    m->GetDressed();
    Person* m_1 = new man(b,9);
    m_1->GetDressed();
    Person* w = new woman(c,12);
    w->GetDressed();
    Person* w_1 = new woman(d,13);
    w_1 ->GetDressed();
    Person* p = new Person();
    p->GetDressed();
    return 0;
}
