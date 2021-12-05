#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
      Person(string _name,int _age):name(_name),age(_age){}
      void print_(){
        cout<<"Base:"<<name << age << endl;
      }
    private:
      string name;
      int age;
};

class man:public Person{
    public:
      man(string _sex,string _name,int _age):Person(_name,_age),sex(_sex){}
      void print_(){
        Person::print_();
        cout<< sex << endl;
      }
    private:
     string sex;
};

class wowen:public Person{
   public:
     wowen(string _sex,string _name,int _age):Person(_name,_age),sex(_sex){}
     void print_(){
       Person::print_();
       cout<< sex << endl;
     }
   private:
     string sex;
};

int main(){
  man* fdz = new man("ÄÐÈË","fengdaozhuo",22);
  fdz->print_();
  wowen* cc = new wowen("Å®ÈË","ccc",22);
  cc->print_();
  return 0;
}
