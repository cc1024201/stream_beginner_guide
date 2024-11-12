//
// Created by heybebe on 11/12/24.
//
#include <iostream>
#include <fstream>
#include <string>

class MyFileStream
{
public:
    MyFileStream() : file()
    {
    }

    bool open(const std::string& filename, std::ios::openmode mode)
    {
        file.open(filename, mode);
        return file.is_open();
    }

    void close()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    bool is_open() const
    {
        return file.is_open();
    }

    MyFileStream& operator<<(const std::string& data)
    {
        if (file.is_open())
        {
            file << data;
        }
        return *this;
    }

    MyFileStream& operator<<(std::ostream& (*manip)(std::ostream&))
    {
        if (file.is_open())
        {
            file << manip;
        }
        return *this;
    }

    MyFileStream& operator>>(std::string& data)
    {
        if (file.is_open())
        {
            file >> data;
        }
        return *this;
    }

    ~MyFileStream()
    {
        close();
    }

private:
    std::fstream file;
};

int main()
{
    MyFileStream myFile;

    // Open file for writing
    if (myFile.open("example.txt", std::ios::out))
    {
        myFile << "Hello, World!" << std::endl;
        myFile.close();
    }

    // Open file for reading
    if (myFile.open("example.txt", std::ios::in))
    {
        std::string content;
        myFile >> content;
        std::cout << "Read from file: " << content << std::endl;
        myFile.close();
    }

    return 0;
}
