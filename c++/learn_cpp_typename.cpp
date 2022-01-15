#include <bits/stdc++.h>
using namespace std;

struct A;
template <template T> struct B;
template <typename T> struct X{
  typedef X<T> TA; //编译器知道X<T>是个类型。
  typedef X TB; // X等价于X<T>的缩写
  typedef T TC; //T 肯定是类型啦

  class Y{
    typedef X<T> TD; //X的内部，既然外部可以，内部也没问题
    typedef X<T>::Y TE; //编译器知道Y就是当前的类型

    typedef typename X<T*>::Y TF; //要加typename!，因为X<T>和X<T*>不一样，
                                  //X<T*> 可能会在实例化的时候，被别的偏特化抢过去实现了。
  };

  typedef A TG; //因为A在外面声明啦，
  typedef B<T> TH; //B<T>也是一个类型
  typedef typename B<T>::type TI;  //因为不知道B<T>::type的信息，所以需要typename

  typedef B<int>::type TJ;   // B<int> 不依赖模板参数
                             //所以编译器直接就是实例化了，因为B并没有被实现，所以就出错了
};          
