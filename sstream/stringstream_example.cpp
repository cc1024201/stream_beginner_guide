//
// Created by heybebe on 11/11/24.
//
#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Example 1: Converting an integer to a string
    int num = 42;
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    std::cout << "Integer to string: " << str << std::endl;

    // Example 2: Converting a string to an integer
    std::string strNum = "123";
    int convertedNum;
    ss.clear(); // Clear the stringstream state
    ss.str(strNum); // Set the stringstream content
    ss >> convertedNum;
    std::cout << "String to integer: " << convertedNum << std::endl;

    // Example 3: Reading and writing multiple data types
    std::string input = "John 25 3.14";
    std::string name;
    int age;
    double pi;
    ss.clear();
    ss.str(input);
    ss >> name >> age >> pi;
    std::cout << "Name: " << name << ", Age: " << age << ", Pi: " << pi << std::endl;

    return 0;
}