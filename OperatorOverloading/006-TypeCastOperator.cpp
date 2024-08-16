#include<iostream>

double dollarToRupee()
{
    return 71.5;
}

class Rupee
{
    double rupee;
public:
    Rupee(double d=0):rupee{d}{}
    void print() { std::cout << rupee<<"\n";}
    /*operator Dollar()
    {
        return Dollar(rupee/dollarToRupee());
    }*/
};

class Dollar
{
    double dollar;
public:
    Dollar(double d=0):dollar{d}{}
    void print() { std::cout << dollar<<"\n";}
    operator Rupee()
    {
        return Rupee(dollar*dollarToRupee());
    }
};

int main()
{
    Dollar d(10);
    Rupee r;
    r=d;
    r.print();
    d.print();
    return 0;
}
