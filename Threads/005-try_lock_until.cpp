#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increment(int i)
{
    auto now=std::chrono::steady_clock::now();
    if(m.try_lock_until(now + std::chrono::seconds(2)))
    {
        ++myAmount;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        cout << "Thread " << i << " Entered" << endl;
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " Couldn't Enter" << endl;
    }
}

int main()
{
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);
    t1.join();
    t2.join();
    cout << myAmount << endl;
    return 0;
}
