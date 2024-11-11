//
// Created by heybebe on 11/10/24.
//
// ofstream_example.cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream ofs("example.txt");
    ofs << "Hello, World!" << std::endl;
    ofs.close();
    return 0;
}