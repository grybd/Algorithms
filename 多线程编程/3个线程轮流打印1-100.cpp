#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

std::mutex data_mutex;
std::condition_variable data_var;
int flag=1;
int i=0;

#define MAXNUM 100

void printA(){
    while(i<MAXNUM){
//        std::this_thread::sleep_for(std::chrono::seconds(1)); //打印节奏变慢
        std::unique_lock<std::mutex> lck(data_mutex);
        //当flag为1时，wait不阻塞；否则wait阻塞当前线程。
        //允许其他锁住的线程继续，当其他线程调用notify函数后，并且flag为1时
        //此线程被唤醒
        data_var.wait(lck, []{return flag==1;});
        flag=2;
        if(i >= 100){
            data_var.notify_all();
            break;
        }
        i++;
        std::cout<<"threadA:"<<i<<std::endl;
        data_var.notify_all();
    }
}

void printB(){
    while(i<MAXNUM){
        std::unique_lock<std::mutex> lck(data_mutex);
        //当flag为2时，wait不阻塞；否则wait阻塞当前线程。
        //允许其他锁住的线程继续，当其他线程调用notify函数后，并且flag为2时
        //此线程被唤醒
        data_var.wait(lck, []{return flag==2;});
        flag = 3;
        if(i >= 100){
            data_var.notify_all();
            break;
        }
        i++;
        std::cout<<"threadB:"<<i<<std::endl;
        data_var.notify_all();
    }
}

void printC(){
    while(i<MAXNUM){
        std::unique_lock<std::mutex> lck(data_mutex);
        //当flag为3时，wait不阻塞；否则wait阻塞当前线程。
        //允许其他锁住的线程继续，当其他线程调用notify函数后，并且flag为3时
        //此线程被唤醒
        data_var.wait(lck, []{return flag==3;});
        flag = 1;
        if(i >= 100){
            data_var.notify_all();
            break;
        }
        i++;
        std::cout<<"threadC:"<<i<<std::endl;
        data_var.notify_all();
    }
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
