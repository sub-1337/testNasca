add_executable(calculator_tests
    tests.cpp
    ../application_config.cpp
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

configure_file(files/config_1.toml ${CMAKE_CURRENT_BINARY_DIR}/config_1.toml COPYONLY)
configure_file(files/config_2.toml ${CMAKE_CURRENT_BINARY_DIR}/config_2.toml COPYONLY)
configure_file(files/config_3.toml ${CMAKE_CURRENT_BINARY_DIR}/config_3.toml COPYONLY)
configure_file(files/config_4.toml ${CMAKE_CURRENT_BINARY_DIR}/config_4.toml COPYONLY)
