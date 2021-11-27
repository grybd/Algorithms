//生产者消费者
#include <bits/stdc++.h>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

std::deque<int>q;
std::mutex mutex;
std::condition_variable cond;

void function_1()//生产者
{
  int count=10;
  while(count>0){
    std::unique_lock<std::mutex> locker(mu);
    q.push_front(count);
    locker.unlock();
    cond.notify_one();
    count--;
  }
}

void function_2() //消费者
{
  int data=0;
  while(data!=1){
    std::unique_lock<std::mutex>locker(mu);
    while(q.empty()){
      cond.wait(locker);
    }
    data = q.back();
    q.pop_back();
    locker.unlock();
  }
}

int main(){
  std::thread t1(function_1);
  std::thread t2(function_2);
  t1.join();
  t2.join();
  return 0;
}
