#include<iostream>

class Test
{
    int x;
public:
    Test(int x=0):x{x}{}
    friend std::istream& operator>>(std::istream& input , Test& obj);
    friend std::ostream& operator<<(std::ostream& output , Test& obj);
};

std::istream& operator>>(std::istream&input , Test& obj)
{
    input>>obj.x;
    return input;
}
std::ostream& operator<<(std::ostream& output , Test& obj)
{
    output<<obj.x<<"\n";
    return output;
}

int main()
{
    Test t;
    std::cin>>t;
    std::cout<<t;
    return 0;
}
