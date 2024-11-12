//
// Created by heybebe on 11/12/24.
//
#include <iostream>
#include <string>
#include <sstream>

class MyOStringStream
{
public:
    MyOStringStream() = default;

    template <typename T>
    MyOStringStream& operator<<(const T& value)
    {
        std::ostringstream oss;
        oss << value;
        data += oss.str();
        return *this;
    }

    std::string str() const
    {
        return data;
    }

    void str(const std::string& newStr)
    {
        data = newStr;
    }

private:
    std::string data;
};

int main()
{
    MyOStringStream myStream;
    myStream << 123 << " " << 456.78 << " " << "Hello";

    std::cout << "Output: " << myStream.str() << std::endl;

    return 0;
}
