#include <iostream>

using namespace std;

template<class T>
class SmartPoint
{
public:
 //构造函数
 SmartPoint(T* p=NULL)
 {
  _ptr = p;
  if (p != NULL)
  {
   _count = 1;
  }
  else
  {
   _count = 0;
  }
 }
 //析构函数
 ~SmartPoint()
 {
  if (--_count == 0)
  {
   delete _ptr;
  }
 }
 //拷贝构造函数
 SmartPoint(const SmartPoint& src)
 {
  if (this != &src)
  {
   _ptr = src._ptr;
   _count = src._count;
   _count++;
  }
 }

 //重载赋值操作符
 SmartPoint& operator=(const SmartPoint& src)
 {
  if (_ptr == src._ptr)
  {
   return *this;
  }
  if (_ptr)
  {
   _count--;
   if (_count == 0)
   {
    delete _ptr;
   }
  }
  _ptr = src._ptr;
  _count = src._count;
  _count++;
  return *this;
 }

 //重载操作符
 T* operator ->()
 {
  if (_ptr)
   return _ptr;
 }

 //重载操作符
 T& operator *()
 {
  if (_ptr)
   return *_ptr;
 }

 size_t use_count()
 {
  return _count;
 }
private:
 T* _ptr;
 size_t _count;

};

void Use(SmartPoint<char> p)
{
 int n = p.use_count();
}

int main()
{
 SmartPoint<char>sp1(new char);
 Use(sp1);
 SmartPoint<char>sp2(sp1);
 SmartPoint<char>sp3;
 sp3 = sp1;
 int n = sp1.use_count();
 return 0;
}
