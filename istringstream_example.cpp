//
// Created by heybebe on 11/10/24.
//
// istringstream_example.cpp
#include <iostream>
#include <sstream>

int main() {
    std::istringstream iss("123 456");
    int a, b;
    iss >> a >> b;
    std::cout << "Read from stringstream: " << a << " " << b << std::endl;
    return 0;
}