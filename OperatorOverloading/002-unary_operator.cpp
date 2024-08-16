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
};
//Unary +,-,++,--
int main()
{
    Point p1(4,5);
    Point p2;
    p1.print();
    p2.print();
    Point p3=-p1;
    p3.print();
}
