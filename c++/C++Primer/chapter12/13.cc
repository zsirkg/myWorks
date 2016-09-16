#include <iostream>
#include <string>

class Screen {
    public:
        typedef std::string::size_type index;
        Screen(index h, index w, const std::string &content=" ")
        {
            cursor = 0;
            contents = content;
            height = h;
            width = w;
        }
        Screen& move(index r, index c)
        {
            index row = r * width;
            cursor = row + c;

            return *this;
        }
        Screen& set(char c)
        {
            contents[cursor] = c;
            return *this;
        }
        Screen& display(std::ostream &os)
        {
            do_display(os);
            return *this;
        }
        const Screen& display(std::ostream &os) const
        {
            do_display(os);
            return *this;
        }
    private:
        std::string contents;
        index cursor;
        index width, height;
        void do_display(std::ostream &os) const
                {os << contents;}
};


int main()
{
    Screen myScreen(2, 4, "zsir\ntest\n");

    myScreen.move(0, 0).set('s').display(std::cout);

    return 0;
}
