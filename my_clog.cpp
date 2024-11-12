//
// Created by heybebe on 11/12/24.
//
#include <iostream>
#include <streambuf>
#include <cstdio>

class clog_streambuf : public std::streambuf
{
protected:
    virtual int overflow(int c) override
    {
        if (c != EOF)
        {
            if (std::fputc(c, stdout) == EOF)
            {
                return EOF;
            }
        }
        return c;
    }
};

class clog_ostream : public std::ostream
{
public:
    clog_ostream() : std::ostream(&buf)
    {
    }

private:
    clog_streambuf buf;
};

clog_ostream my_clog;

int main()
{
    my_clog << "This is a log message." << std::endl;
    return 0;
}
