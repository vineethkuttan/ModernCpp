#include<iostream>
#include<list>
struct MyStruct
{
    int mark;
    std::string name;
    MyStruct(std::string aName,int aMark)
    {
        mark=aMark;
        name=aName;
    }
     void operator+=(MyStruct& arg)
     {
         mark+=arg.mark;
         name+=arg.name;
     }
     bool operator==(const MyStruct& arg)
     {
         return name==arg.name;
     }
};

struct MyCollection
{
    std::list<MyStruct> coll;
    void operator+=(MyStruct& arg)
     {
         coll.push_back(arg);
     }
     void operator-=(const MyStruct& arg)
     {
         coll.remove(arg);
     }
};
std::ostream& operator<<(std::ostream& COUT,MyStruct& arg)
{
    COUT<<arg.name.c_str()<<" "<<arg.mark<<"\n";
    return COUT;
}
int main()
{
    MyStruct test=MyStruct("Vineeth",100);
    MyStruct test1=MyStruct("Kuttan",100);
    std::cout<<test<<test1;
    MyCollection vin;
    vin+=test;
    vin+=test1;
    test+=test1;
    vin+=test;
    for(auto i:vin.coll)
    {
        std::cout<<i;
    }
    vin-=test;
    std::cout<<"Poda\n";
    for(auto i:vin.coll)
    {
        std::cout<<i;
    }

    return 0;
}
