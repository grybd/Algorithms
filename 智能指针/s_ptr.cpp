/*
当新增一个时引用计数加1，当过期时引用计数减一。
只有引用计数为0时，智能指针才会自动释放引用的内存资源。
对shared_ptr进行初始化时不能将一个普通指针直接赋值给智能指针，
因为一个是指针，一个是类。可以通过make_shared函数或者通过构造函数传入普通指针。
并可以通过get函数获得普通指针。

为什么要使用智能指针
智能指针的作用是管理一个指针，因为存在以下这种情况：申请的空间在函数结束时忘记释放，
造成内存泄漏。使用智能指针可以很大程度上的避免这个问题，因为智能指针是一个类，当超出
了类的实例对象的作用域时，会自动调用对象的析构函数，析构函数会自动释放资源。
所以智能指针的作用原理就是在函数结束时自动释放内存空间，不需要手动释放内存空间。
*/

#include <memory>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(){
  auto_ptr<string> p1(new string("I reigned lonely as a cloud."));
  auto_ptr<string>p2;
  p2=p1;//此时不会报错，p2剥夺了p1的所有权，但是当程序运行时访问p1将会报错。所以auto_ptr的缺点是：\
  存在潜在的内存崩溃问题！
  unique_ptr<string>p3(new string("auto"));
  unique_ptr<string>p4;
  /*（替换auto_ptr）unique_ptr实现独占式拥有或严格拥有概念，
  保证同一时间内只有一个智能指针可以指向该对象。它对于避免资源
  泄露(例如“以new创建对象后因为发生异常而忘记调用delete”)特别有用。
  采用所有权模式，还是上面那个例子*/
  //p4=p3;//此时会报错；

  /*
  shared_ptr实现共享式拥有概念。多个智能指针可以指向相同对象，该对象和其相关资源会在“最后一个引用被销毁”时候释放。
  从名字share就可以看出了资源可以被多个指针共享，它使用计数机制来表明资源被几个指针共享。可以通过成员函数use_count()
  来查看资源的所有者个数。除了可以通过new来构造，还可以通过传入auto_ptr, unique_ptr,weak_ptr来构造。当我们调用release()
  时，当前指针会释放资源所有权，计数减一。当计数等于0时，资源会被释放。shared_ptr 是为了解决 auto_ptr 在对象所有权上的局限性
  (auto_ptr 是独占的), 在使用引用计数的机制上提供了可以共享所有权的智能指针。
  */

  /*
  share_ptr虽然已经很好用了，但是有一点share_ptr智
  能指针还是有内存泄露的情况，当两个对象相互使用一个
  shared_ptr成员变量指向对方，会造成循环引用，使引用
  计数失效，从而导致内存泄漏。weak_ptr是一种不控制对
  象生命周期的智能指针, 它指向一个 shared_ptr管理的对象.
  进行该对象的内存管理的是那个强引用的shared_ptr， weak_ptr
  只是提供了对管理对象的一个访问手段。weak_ptr 设计的目的是为配合
  shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 它只可以
  从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会
  引起引用记数的增加或减少。weak_ptr是用来解决shared_ptr相互引用时的死锁问题,
  如果说两个shared_ptr相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。
  它是对对象的一种弱引用，不会增加对象的引用计数，和shared_ptr之间可以相互转化，shared_ptr
  可以直接赋值给它，它可以通过调用lock函数来获得shared_ptr。
  */








}
