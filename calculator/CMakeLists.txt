cmake_minimum_required(VERSION 3.16)

project(calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_ROOT "D:\\boost_1_82_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")

find_package(Boost 1.82.0 REQUIRED COMPONENTS filesystem system thread)

if(Boost_FOUND)
    message(STATUS "Boost include: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found")
endif()

add_executable(calculator main.cpp)


target_include_directories(calculator PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(calculator PRIVATE Boost::filesystem Boost::system Boost::thread)
