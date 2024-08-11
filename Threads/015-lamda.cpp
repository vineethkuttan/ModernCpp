#include<iostream>
#include<list>
#include<algorithm>
int main()
{
    //Syntax
    //[](){};
    //[] ->setting global parameters, ()->passing arguements, {}->statements
    int a=10,b=20,c=30;
    std::list<int> li{1,3,5,6};
    for_each(li.begin(),li.end(),[](int x)
            {
                if(x&1)
                {
                    printf("Number is odd\n");
                }
                else
                {
                    printf("Number is even\n");
                }

            });
    for_each(li.begin(),li.end(),[a,b](int x)
            {
                if(x&1)
                {
                    printf("Number is %d odd %d\n",x,x*a);
                }
                else
                {
                    printf("Number is %d even %d\n",x,x*b);
                }

            });

    for_each(li.begin(),li.end(),[=](int x)
            {
                if(x&1)
                {
                    printf("Number is %d odd %d\n",x,x*a);
                }
                else
                {
                    printf("Number is %d even %d\n",x,x*b);
                }

            });
    for_each(li.begin(),li.end(),[&a,&b](int x)
            {
                if(x&1)
                {
                    printf("Number is %d odd %d\n",x,x*a);
                    a*=x;
                }
                else
                {
                    printf("Number is %d even %d\n",x,x*b);
                    b*=x;
                }
            });
    std::cout<<a<<" "<<b<<"\n";
    for_each(li.begin(),li.end(),[&](int x)
            {
                if(x&1)
                {
                    printf("Number is %d odd %d\n",x,x*a);
                    a*=x;
                }
                else
                {
                    printf("Number is %d even %d\n",x,x*b);
                    b*=x;
                }
            });
    std::cout<<a<<" "<<b<<"\n";
   return 0;
}
