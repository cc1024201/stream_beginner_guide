//
// Created by heybebe on 11/10/24.
//
// ifstream_example.cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream ifs("example.txt");
    if (ifs.is_open()) {
        std::string content;
        std::getline(ifs, content);
        std::cout << "File content: " << content << std::endl;
        ifs.close();
    } else {
        std::cerr << "Failed to open file." << std::endl;
    }
    return 0;
}