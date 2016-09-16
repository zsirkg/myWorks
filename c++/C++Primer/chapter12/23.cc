#include <iostream>

class NoDefault {
    public:
        NoDefault(int i) {
            std::cout << "Nodefault constructor: i = " << i << std::endl;
        };
    private:
        int i;
};

class C {
    public:
        C():i(5), NDF(i) {
            std::cout << "C constructor" << std::endl;
        }
    private:
        int i;
        NoDefault NDF;
};

int main()
{
    C c;

    return 0;
}
