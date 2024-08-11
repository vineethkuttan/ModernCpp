#include <iostream>
#include<thread>
#include <chrono>
#include<future>

using namespace std;
typedef unsigned long long ull;

void findOddSum(std::promise<ull>&& oddsumpromise,int start,int endd)
{
    ull oddsum=0;
    for(int i=start;i<=endd;i++)
    {
        if(i&1)
        {
            oddsum+=i;
        }
    }
    oddsumpromise.set_value(oddsum);
}

int main()
{

    int start=0,endd=1900000000;
    std::promise<ull> oddsum;
    std::future<ull> oddfuture=oddsum.get_future();
    std::thread t1(findOddSum,std::move(oddsum),start,endd);

    cout<<"waiting to complete\n";
    cout<<"odd sum :"<<oddfuture.get()<<"\ncompleted\n";
    t1.join();
    return 0;
}
