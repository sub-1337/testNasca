add_executable(calculator_tests
    tests.cpp
)

target_link_libraries(calculator_tests PRIVATE
    Catch2::Catch2WithMain
    Boost::program_options
    tomlplusplus::tomlplusplus
    spdlog::spdlog
)

include(CTest)
include(Catch)

catch_discover_tests(calculator_tests)