#include <iostream>
#include <string>
#include <fstream>

class myClass {
    public:
        myClass()
            :name("myClass"), i(1), pd(0)
        {
            std::cout << "name: " << name << std::endl;
            std::cout << "i: " << i << std::endl;
            std::cout << "dp: " << pd << std::endl;
        };
    private:
        const std::string name;
        int i;
        double *pd;
};

int main()
{
    myClass test;
}
