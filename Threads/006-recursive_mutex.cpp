#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int myAmount = 0;
std::recursive_mutex m;

void recursor(char c,int num)
{
    if(num<0)
        return;
    m.lock();
    cout<<"Thread :"<<c<<" " <<myAmount++<<endl;
    recursor(c,--num);
    m.unlock();
}

void chumma()
{
    for(int i=0;i<5;i++)
        m.lock();
    for(int i=0;i<5;i++)
        m.unlock();
}

int main()
{
    std::thread t1(recursor,'1',10);
    std::thread t2(recursor,'2',10);
    t1.join();
    t2.join();

    return 0;
}
