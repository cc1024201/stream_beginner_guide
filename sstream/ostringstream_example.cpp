//
// Created by heybebe on 11/10/24.
//
// ostringstream_example.cpp
#include <iostream>
#include <sstream>

int main() {
    std::ostringstream oss;
    oss << "Hello, " << "World!";
    std::string result = oss.str();
    std::cout << "Written to stringstream: " << result << std::endl;
    return 0;
}