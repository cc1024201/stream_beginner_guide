//
// Created by heybebe on 11/11/24.
//
#include <iostream>
#include <string>
#include <cstdio>

class MyCin
{
public:
    MyCin& operator>>(std::string& str)
    {
        char buffer[1024];
        if (std::fgets(buffer, sizeof(buffer), stdin))
        {
            str = buffer;
            // Remove the newline character if present
            if (!str.empty() && str.back() == '\n')
            {
                str.pop_back();
            }
        }
        else
        {
            // Handle error or end of input
            str.clear();
        }
        return *this;
    }

    MyCin& operator>>(int& value)
    {
        std::string str;
        *this >> str;
        value = std::stoi(str);
        return *this;
    }

    MyCin& operator>>(double& value)
    {
        std::string str;
        *this >> str;
        value = std::stod(str);
        return *this;
    }

    // Add more overloaded operators as needed
};

int main()
{
    MyCin myCin;
    std::string inputStr;
    int inputInt;
    double inputDouble;

    std::cout << "Enter a string: ";
    myCin >> inputStr;
    std::cout << "You entered: " << inputStr << std::endl;

    std::cout << "Enter an integer: ";
    myCin >> inputInt;
    std::cout << "You entered: " << inputInt << std::endl;

    std::cout << "Enter a double: ";
    myCin >> inputDouble;
    std::cout << "You entered: " << inputDouble << std::endl;

    return 0;
}
