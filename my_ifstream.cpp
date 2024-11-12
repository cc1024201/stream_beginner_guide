//
// Created by heybebe on 11/12/24.
//
#include <iostream>
#include <fstream>
#include <string>

class my_ifstream
{
public:
    my_ifstream() : file(nullptr)
    {
    }

    my_ifstream(const std::string& filename) : file(nullptr)
    {
        open(filename);
    }

    ~my_ifstream()
    {
        if (file)
        {
            close();
        }
    }

    void open(const std::string& filename)
    {
        file = std::fopen(filename.c_str(), "r");
        if (!file)
        {
            std::cerr << "Failed to open file: " << filename << std::endl;
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

    bool is_open() const
    {
        return file != nullptr;
    }

    my_ifstream& operator>>(std::string& str)
    {
        if (file)
        {
            char buffer[1024];
            if (std::fgets(buffer, sizeof(buffer), file))
            {
                str = buffer;
            }
            else
            {
                str.clear();
            }
        }
        return *this;
    }

    explicit operator bool() const
    {
        return is_open();
    }

private:
    std::FILE* file;
};

int main()
{
    my_ifstream myfile("example.txt");
    if (myfile.is_open())
    {
        std::string line;
        while (myfile >> line)
        {
            std::cout << line;
        }
        myfile.close();
    }
    return 0;
}
