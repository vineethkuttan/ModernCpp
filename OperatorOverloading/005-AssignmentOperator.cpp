#include<iostream>

class Test
{
    int *x;
public:
    Test(int val=0):x{new int(val)}{}
    void setX(int val){*x = val; }
    void print() {std::cout<< "OUTPUT: "<<*x<<"\n";}
    ~Test() { delete x;}
    /*Test& operator = (const Test& rhs)
    {
        if(this !=&rhs)
            setX(*(rhs.x));
        return *this;
    }*/
//method 2
    Test operator =(const Test& rhs)
    {
        if(this !=&rhs)
            setX(*(rhs.x));
        return *this;
    }
//copy constructor
    Test(const Test& rhs)
    {
        x=new int(*rhs.x);
    }
};

int main()
{
    Test t1(10);
    Test t2;
    t2=t1;
    t1.setX(20);
    t1.print();
    t2.print();
}
