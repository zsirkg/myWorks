#include <iostream>
using namespace std;

class Employee {
    public:
        Employee():m_id(m_cnt) {
            cout << "default constructor id:" << m_id << endl;
            m_cnt++;
        }
        Employee(const string & na):m_name(na),m_id(m_cnt) {
            cout << "constructor id:" << m_id << endl;
            m_cnt++;
        }
        Employee(const Employee & rhs):m_name(rhs.m_name), m_id(m_cnt) {
            cout << "copy constructor id:" << m_id << endl;
            m_cnt++;
        }
        Employee & operator=(const Employee & rhs) {
            cout << "operator= id:" << m_id << endl;
            m_name = rhs.m_name;
            m_cnt++;
        }
    private:
        int m_id;
        string m_name;
        static int m_cnt;
};
int Employee::m_cnt = 1;

int main()
{
    cout << "Employee employee01" << endl;
    Employee employee01;

    cout << "Employee employee02(\"terry\")" << endl;
    Employee employee02("terry");

    cout << "Employee employee03(employee02)" << endl;
    Employee employee03(employee02);

    cout << "employee01 = employee03" << endl;
    employee01 = employee03;

    return 0;
}
