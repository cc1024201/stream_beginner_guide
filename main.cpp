#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // std::cin example
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;

    // std::cout example
    std::cout << "Hello, World!" << std::endl;

    // std::cerr example
    std::cerr << "This is an error message." << std::endl;

    // std::clog example
    std::clog << "This is a log message." << std::endl;

    // std::ifstream example
    std::ifstream ifs("example.txt");
    if (ifs.is_open()) {
        std::string content;
        ifs >> content;
        std::cout << "File content: " << content << std::endl;
        ifs.close();
    } else {
        std::cerr << "Failed to open file." << std::endl;
    }

    // std::ofstream example
    std::ofstream ofs("example.txt");
    ofs << "Hello, World!" << std::endl;
    ofs.close();

    // std::istringstream example
    std::istringstream iss("123 456");
    int a, b;
    iss >> a >> b;
    std::cout << "Read from stringstream: " << a << " " << b << std::endl;

    // std::ostringstream example
    std::ostringstream oss;
    oss << "Hello, " << "World!";
    std::string result = oss.str();
    std::cout << "Written to stringstream: " << result << std::endl;

    return 0;
}