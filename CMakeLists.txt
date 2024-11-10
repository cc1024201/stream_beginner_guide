cmake_minimum_required(VERSION 3.29)
project(iostream_beginner_guide)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp)

add_executable(cin_example cin_example.cpp)

add_executable(cout_example cout_example.cpp)

add_executable(cerr_example cerr_example.cpp)

add_executable(clog_example clog_example.cpp)

add_executable(ifstream_example ifstream_example.cpp)
add_executable(ofstream_example ofstream_example.cpp)
add_executable(istringstream_example istringstream_example.cpp)
add_executable(ostringstream_example ostringstream_example.cpp)
