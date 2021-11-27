//只能在堆上建立对象
class A
{
protected:
    A(){}
    ~A(){}
public:
  static A*create()
  {
    return new A();
  }
  void destroy()
  {
    delete this;
  }
};

//只能在栈上建立对象
// 只有使用new运算符，对象才会建立在堆上，因此，只要禁用new运算符就可以实现类对象只能建立在栈上。
//将operator new()设为私有即可。代码如下：
class A_{
private:
  void* operator new(size_t t){}
  void operator delete(void *ptr){}
public:
  A_(){}
  ~A_(){}
};
