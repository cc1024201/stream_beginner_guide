//
// Created by heybebe on 11/12/24.
//
#include <iostream>
#include <string>
#include <sstream>

class MyStringStream
{
public:
    MyStringStream() = default;

    MyStringStream(const std::string& str) : data(str)
    {
    }

    // Output operator
    template <typename T>
    MyStringStream& operator<<(const T& value)
    {
        std::ostringstream oss;
        oss << value;
        data += oss.str();
        return *this;
    }

    // Input operator
    template <typename T>
    MyStringStream& operator>>(T& value)
    {
        std::istringstream iss(data.substr(pos));
        iss >> value;
        pos += iss.tellg();
        return *this;
    }

    std::string str() const
    {
        return data;
    }

    void str(const std::string& newStr)
    {
        data = newStr;
        pos = 0;
    }

private:
    std::string data;
    size_t pos = 0;
};

int main()
{
    MyStringStream myStream;
    myStream << 123 << " " << 456.78 << " " << "Hello";

    std::cout << "Output: " << myStream.str() << std::endl;

    int intValue;
    double doubleValue;
    std::string strValue;

    myStream >> intValue >> doubleValue >> strValue;

    std::cout << "Integer: " << intValue << std::endl;
    std::cout << "Double: " << doubleValue << std::endl;
    std::cout << "String: " << strValue << std::endl;

    return 0;
}
