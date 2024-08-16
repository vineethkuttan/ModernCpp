#include<iostream>
class Point
{
    int x;
    int y;
public:
    Point(int x=0,int y=0):x{x},y{y}
    {

    }
    void print()
    {
        printf("x -> %d , y -> %d\n",x,y);
    }

    Point operator - ()
    {
        return Point(-x,-y);
    }

    int& operator [] (int pos)
    {
        if(pos==0)
            return x;
        else if(pos==1)
            return y;
        else
            throw std::runtime_error("UnsupportedOperationException");
    }
};
int main()
{
    Point p1(4,5);
    Point p2;
    p1.print();
    p2.print();
    Point p3=-p1;
    p3.print();
    p3[0]=77;
    p3[1]=99;
    p3.print();
    p3[5]=2;
}
