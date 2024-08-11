#include <iostream>
#include<thread>
#include <chrono>
#include<mutex>
long long int global_count = 0;
std::mutex m;
void increase_count(int a)
{
    for(int i=0;i<100000;i++)
    {
        if(m.try_lock())
        {
            global_count ++;
            m.unlock();
        }
    }
}

int main()
{
    std::thread t1(increase_count,8);
    std::thread t2(increase_count,8);
    t1.join();
    t2.join();
    printf("global count %lld\n",global_count);
    return 0;
}
