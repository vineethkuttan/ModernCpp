#include <iostream>
#include<thread>
#include <chrono>
#include<mutex>
int global_count = 0;
std::mutex m;
void fun(int f,std::string s)
{
    for (int i = 0; i < f; i++)
    {
        printf("%s %d\n",s.c_str(), i);
    }
}
class A
{
public:
    void Boomer(int a, int b)
    {
        printf("Boomer %d\n", a * b);
    }
};

void increase_count(int a)
{
    m.lock();
    global_count ++;
    m.unlock();
}
int main()
{
    std::thread t1(fun, 4,"vineeth");
    std::thread t2(fun, 10,"Ajith");
    A b;
    std::thread t3(&A::Boomer, &b,5,6);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    printf("HelloWorld");
    if (t3.joinable())
        t3.detach();
    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();
    std::thread tcount(increase_count, 5);
    std::thread tcount2(increase_count, 6);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (tcount.joinable())
        tcount.detach();
    if (tcount2.joinable())
        tcount2.detach();
    printf("global count %d\n", global_count);
    return 0;
}
