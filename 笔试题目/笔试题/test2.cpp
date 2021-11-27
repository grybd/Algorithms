#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

// 打印奇数
void printOdd(int n)
{
    for (int i = 1; i <= n; i+=2)
    {
        cout << "Task1:\t" << i << endl;
        Sleep(20);
    }
}
// 打印偶数
void printEven(int n)
{
    for (int i = 0; i <= n; i+=2)
    {
        cout << "Task2:\t" << i << endl;
        Sleep(30);
    }
}
int main()
{
    int n;
    cin >> n;
    time_t start, stop;
    start = time(NULL);
    thread t1(printOdd, n);
    thread t2(printEven, n);
    t1.join();
    t2.join();
    stop = time(NULL);
    cout << "任务完成！\n耗时："<< (stop-start) << endl;
    return 0;
}
