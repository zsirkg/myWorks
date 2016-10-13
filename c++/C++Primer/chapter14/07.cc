#include <iostream>
using namespace std;

class CheckoutRecord {
    public:
        CheckoutRecord():book_id(0), title("null"){};
        CheckoutRecord(double id, string t):
            book_id(id), title(t) {}

        CheckoutRecord& operator=(const CheckoutRecord& rhs);
        friend ostream& operator<<(ostream& out, const CheckoutRecord &c);
        friend istream& operator>>(istream& in, CheckoutRecord &c);
    private:
        double book_id;
        string title;
};

CheckoutRecord& CheckoutRecord::operator=(const CheckoutRecord& rhs)
{
    book_id = rhs.book_id;
    title = rhs.title;

    return *this;
}

ostream& operator<<(ostream& out, const CheckoutRecord &c)
{
    out << c.book_id << " " << c.title;

    return out;
}

istream& operator>>(istream& in, CheckoutRecord &c)
{
    in >> c.book_id >> c.title;
    if(!in) {
        c = CheckoutRecord();
    }

    return in;
}

int main()
{
    CheckoutRecord C(23, "zsir");
    CheckoutRecord C1(22, "terry");


    //cin >> C;
    C = C1;
    cout << C << endl;
}
