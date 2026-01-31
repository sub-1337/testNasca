cmake_minimum_required(VERSION 3.16)

project(calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Далее идёт код подключения boost
## с помощью фетча, у меня это не заработало
## но вы можете попробовать

# Включим модуль фетча
include(FetchContent)

# Запрашиваем буст
#FetchContent_Declare(
#    boost
#    GIT_REPOSITORY https://github.com/boostorg/boost.git
#    GIT_TAG boost-1.84.0
#)
#FetchContent_MakeAvailable(boost)

# Запрашиваем toml++
FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

# Запрашиваем spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.17.0 # Use a specific version tag for stability
)
FetchContent_MakeAvailable(spdlog)

# Require test framework
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.12.0 # Use a specific version tag
)
FetchContent_MakeAvailable(Catch2)

# TODO: замените на свой путь к бусту
set(Boost_ROOT "D:\\boost_1_82_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")

find_package(Boost 1.82.0 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    message(STATUS "Boost include: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
else()
    message(FATAL_ERROR "Boost not found")
endif()

add_executable(calculator main.cpp
    application.cpp
    application.h
    application_config.h application_config.cpp)


target_include_directories(calculator PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(calculator PRIVATE Boost::program_options tomlplusplus::tomlplusplus spdlog::spdlog)

enable_testing()
add_subdirectory(tests)
