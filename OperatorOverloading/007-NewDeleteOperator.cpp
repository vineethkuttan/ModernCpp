#include<iostream>
/*
Primary	Alternative
&&	and
&=	and_eq
&	bitand
|	bitor
~	compl
!	not
!=	not_eq
||	or
|=	or_eq
^	xor
^=	xor_eq
{	<%
}	%>
[	<:
]	:>
#	%:
##	%:%:
*/
/*
//LOCAL Scope
class Test
{
    int x;
public:
    Test(int x=0):x{x}{}
    void * operator new(size_t s)
    {
        std::cout<<"Local Scope Overloaded new operator size: "<<s<<"\n";
        void *p=malloc(s);
        return p;
    }
    void operator delete(void *p)
    {
        std::cout<<"Local Scope Overloaded Delete Operator\n";
        free(p);
    }
};
*/

//GLobal scope
void * operator new(size_t s,int val)
{
    std::cout<<val<<"Global Scope with val Overloaded new operator size: "<<s<<"\n";
    void *p=malloc(s);
    return p;
}
void * operator new(size_t s)
{
    std::cout<<"Global Scope without val Overloaded new operator size: "<<s<<"\n";
    void *p=malloc(s);
    return p;
}
void operator delete(void *p,size_t s)
{
    std::cout<<"Global Scope Overloaded Delete Operator\n";
    free(p);
}

void * operator new [](size_t s)
{
    std::cout<<"Global Scope Overloaded new operator size: "<<s<<"\n";
    void *p=malloc(s);
    return p;
}
void operator delete [](void *p)
{
    std::cout<<"Global Scope Overloaded Delete Operator\n";
    free(p);
}
int main()
<%
    /*Test *t=new Test();
    delete t;*/
    int *x1=new int;
    int *x2=new(5) int;
    delete x1;
    delete x2;
    int *x= new int[10];
    delete[] x;
%>
