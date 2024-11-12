//
// Created by heybebe on 11/11/24.
//
#include <iostream>
#include <string>

class MyCout
{
public:
    // Overload the << operator for different types
    MyCout& operator<<(const std::string& str)
    {
        std::cout << str;
        return *this;
    }

    MyCout& operator<<(const char* str)
    {
        std::cout << str;
        return *this;
    }

    MyCout& operator<<(char c)
    {
        std::cout << c;
        return *this;
    }

    MyCout& operator<<(int value)
    {
        std::cout << value;
        return *this;
    }

    MyCout& operator<<(double value)
    {
        std::cout << value;
        return *this;
    }

    MyCout& operator<<(std::ostream& (*fp)(std::ostream&))
    {
        fp(std::cout);
        return *this;
    }

    // Add more overloads as needed for other types
};

int main()
{
    MyCout myCout;
    myCout << "Hello, World!" << std::endl;
    myCout << 123 << std::endl;
    myCout << 45.67 << std::endl;
    return 0;
}
