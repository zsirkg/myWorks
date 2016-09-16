#include <iostream>
using namespace std;

class Foo {
    public:
        Foo(int i) {
            iVal = i;
        };
        int getNumber() {
            return iVal;
        }

    private:
        int iVal;

};

class Bar {
    public:
        int FooVal() {
            xVal++;
            return foo.getNumber();
        };

        int getCount() {
            return xVal;
        }
    private:
        static int xVal;
        static Foo foo;

};
int Bar::xVal = 0;
Foo Bar::foo(1);

int main()
{
    Bar b;

    cout << b.FooVal() << " " << b.getCount() << endl;
    cout << b.FooVal() << " " << b.getCount() << endl;
    cout << b.FooVal() << " " << b.getCount() << endl;

    return 0;
}
