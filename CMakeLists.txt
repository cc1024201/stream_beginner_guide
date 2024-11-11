cmake_minimum_required(VERSION 3.29)
project(stream_beginner_guide)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp)

add_executable(cin_example iostream/cin_example.cpp)

add_executable(cout_example iostream/cout_example.cpp)

add_executable(cerr_example iostream/cerr_example.cpp)

add_executable(clog_example iostream/clog_example.cpp)

add_executable(ifstream_example fstream/ifstream_example.cpp)
add_executable(ofstream_example fstream/ofstream_example.cpp)
add_executable(istringstream_example sstream/istringstream_example.cpp)
add_executable(ostringstream_example sstream/ostringstream_example.cpp)
