#include <iostream>

class Account {
    public:
        Account(std::string own, double am){
            owner = own;
            amount = am;
        };
        static void setRate(double r) {
            rate = r;
        };
        void getAcount(){
            std::cout << owner << " " << amount * rate << std::endl;
        };
    private:
        std::string owner;
        double amount;
        static double rate;
};
double Account::rate = 0.5;

int main()
{
    Account myAccount("zsir", 10);

    myAccount.getAcount();

    return 0;
}
