//
// Created by heybebe on 11/11/24.
//
#include <iostream>
#include <streambuf>
#include <cstdio>

class cerr_streambuf : public std::streambuf
{
protected:
    virtual int overflow(int c) override
    {
        if (c != EOF)
        {
            if (std::fputc(c, stderr) == EOF)
            {
                return EOF;
            }
        }
        return c;
    }
};

class cerr_ostream : public std::ostream
{
public:
    cerr_ostream() : std::ostream(&buf)
    {
    }

private:
    cerr_streambuf buf;
};

cerr_ostream my_cerr;

int main()
{
    my_cerr << "This is an error message." << std::endl;
    return 0;
}
