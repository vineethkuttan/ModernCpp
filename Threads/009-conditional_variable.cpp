/*
HomeCondition Variable In C++ Threading
Condition Variable In C++ Threading
TOPIC: Condition Variable In C++ Threading
NOTES:
1. Condition variables allow us to synchronize threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronize two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition
*/

#include <iostream>
#include <thread>
#include <mutex>
#include<condition_variable>
using namespace std;
std::mutex m1;
std::condition_variable cv;
int balanceAmount = 0;

void Deposit(int Amount)
{
    std::lock_guard<mutex> lock(m1);
    balanceAmount+=Amount;
    cv.notify_one();
}

bool isBalanceAvailable()
{
    if(balanceAmount)
        return true;
    return false;
}

void Withdraw(int Amount)
{
    std::unique_lock<mutex> ul(m1);
    //cv.wait(ul,[] { return (balanceAmount!=0)? true:false ;});
    cv.wait(ul,isBalanceAvailable);
    if(balanceAmount>=Amount)
    {
        balanceAmount-=Amount;
        printf("Amount Withdrawn\n");
    }
    else
    {
        printf("low balance\n");
    }
    cout<<balanceAmount<<" is balance amount\n";
}

int main()
{
    std::thread t2(Withdraw,400);
    std::thread t1(Deposit,500);
    t2.join();
    t1.join();
    return 0;
}
