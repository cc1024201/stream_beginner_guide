//
// Created by heybebe on 11/12/24.
//
#include <iostream>
#include <fstream>
#include <string>

class MyOfstream
{
public:
    MyOfstream() : file(nullptr)
    {
    }

    MyOfstream(const std::string& filename)
    {
        open(filename);
    }

    ~MyOfstream()
    {
        if (file)
        {
            close();
        }
    }

    void open(const std::string& filename)
    {
        file = std::fopen(filename.c_str(), "w");
        if (!file)
        {
            throw std::ios_base::failure("Failed to open file");
        }
    }

    void close()
    {
        if (file)
        {
            std::fclose(file);
            file = nullptr;
        }
    }

    MyOfstream& operator<<(const std::string& data)
    {
        if (file)
        {
            std::fputs(data.c_str(), file);
        }
        else
        {
            throw std::ios_base::failure("File not open");
        }
        return *this;
    }

    MyOfstream& operator<<(int data)
    {
        if (file)
        {
            std::fprintf(file, "%d", data);
        }
        else
        {
            throw std::ios_base::failure("File not open");
        }
        return *this;
    }

    // Add more overloads for other data types as needed

private:
    std::FILE* file;
};

int main()
{
    try
    {
        MyOfstream myfile("example.txt");
        myfile << "Hello, World!" << 123 << "\n";
        myfile.close();
    }
    catch (const std::ios_base::failure& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
