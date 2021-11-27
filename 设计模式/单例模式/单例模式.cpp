#include <mutex>
#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton(){}

private:
    // 此类唯一对象
    static Singleton *instance;
    static std::mutex my_mutex;
public:
    static Singleton* getInstance()
    {
        // instance为共享数据，给instance加锁
        std::lock_guard<std::mutex>mutexObj(my_mutex);
        // 如果此函数第一次调用，此时instance值为NULL，就new一个对象
        if (instance == NULL)
        {
            instance = new Singleton();
            std::cout << "创建一个对象\n";
        }
        return instance;
    }
};
Singleton* Singleton::instance = NULL;
std::mutex Singleton::my_mutex;
