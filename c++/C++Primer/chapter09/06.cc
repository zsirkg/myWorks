#include <list>
#include <iostream>
using namespace std;

class Foo{
    Foo(int){cout<<"=="<<endl;};
};

int main()
{
    list< Foo > FooList;

    return 0;
}
