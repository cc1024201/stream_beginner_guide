//
// Created by heybebe on 11/11/24.
//
#include <iostream>
#include <cstring> // for strlen and strcpy

class MyString
{
private:
    char* data;

public:
    // Default constructor
    MyString() : data(nullptr)
    {
    }

    // Constructor from C-style string
    MyString(const char* str)
    {
        if (str)
        {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }
        else
        {
            data = nullptr;
        }
    }

    // Copy constructor
    MyString(const MyString& other)
    {
        if (other.data)
        {
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }
    }

    // Assignment operator from C-style string
    MyString& operator=(const char* str)
    {
        if (data)
        {
            delete[] data;
        }
        if (str)
        {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        }
        else
        {
            data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MyString()
    {
        delete[] data;
    }

    // Print function for demonstration
    void print() const
    {
        if (data)
        {
            std::cout << data << std::endl;
        }
        else
        {
            std::cout << "(null)" << std::endl;
        }
    }
};

int main()
{
    MyString str;
    const char* buffer = "Hello, World!";
    str = buffer; // Using the overloaded assignment operator
    str.print(); // Output: Hello, World!
    return 0;
}
