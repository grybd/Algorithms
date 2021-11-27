#include <iostream>
   #include <string> // Header file needed to use string objects
   using namespace std;
   int main()
   {
       string name_;
       string city_;
       cout << "Please enter your name_: ";
       cin >> name_;
       cout << "Enter the city_ you live in: ";
       cin >> city_;
       cout << "Hello, " << name_ << endl;
       cout << "You live in " << city_ << endl;
       string name;
       string city;
       cout << "Please enter your name: ";
       cin >> name;
       cout << "Enter the city you live in: ";
       cin >> city;
       cout << "Hello, " << name << endl;
       cout << "You live in " << city << endl;
       return 0;

   }
