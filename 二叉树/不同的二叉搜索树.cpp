#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

#define MAXNUM 100;

std::mutex data_mutex;
std::condition_variable data_val;

int flag=1;
int i=0;
void printA(){
    std::thread::sleep_for(std::chrono::seconds(1);
    std::unique_lock<std::mutex>lck(data_mutex);
    while(i<MAXNUM){
        data_val.wait(lck,[]{return flag==1})
    }
    i++;
    flag = 2;
    std::cout<<"threadA:"<<i<<std::endl;
    data_val.notify_all();
}


void printB(){
    std::thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex>lck(data_mutex);
    while(i<MAX_NUM){
        data.val.wait(lock,[]{return flag==2});
    }
    i++;
    flag = 3;
    cout<<"threadB:"<<i<<endl;
}


void printC(){
    std::thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex>lck(data_mutex);
    while(i<MAX_NUM){
        data.val.wait(lock,[]{return flag==3});
    }
    i++;
    flag = 1;
    cout<<"threadC:"<<i<<endl;
}


int main(){
    std::thread tA(printA);
    std::thread tB(printB);
    std::thread tC(printC);
    tA.join();
    tB.join();
    tC.join();
    return 0;
}