//
// Created by heybebe on 11/12/24.
//
#include <iostream>
#include <string>
#include <sstream>

class MyStringStream
{
public:
    MyStringStream(const std::string& str) : data(str), pos(0)
    {
    }

    MyStringStream& operator>>(std::string& output)
    {
        std::istringstream iss(data.substr(pos));
        iss >> output;
        pos += output.length() + 1; // Update position
        return *this;
    }

    MyStringStream& operator>>(int& output)
    {
        std::istringstream iss(data.substr(pos));
        iss >> output;
        pos += std::to_string(output).length() + 1; // Update position
        return *this;
    }

    MyStringStream& operator>>(double& output)
    {
        std::istringstream iss(data.substr(pos));
        iss >> output;
        pos += std::to_string(output).length() + 1; // Update position
        return *this;
    }

    // Add more overloads as needed

private:
    std::string data;
    size_t pos;
};

int main()
{
    MyStringStream myStream("123 456.78 Hello");

    int intValue;
    double doubleValue;
    std::string strValue;

    myStream >> intValue >> doubleValue >> strValue;

    std::cout << "Integer: " << intValue << std::endl;
    std::cout << "Double: " << doubleValue << std::endl;
    std::cout << "String: " << strValue << std::endl;

    return 0;
}
