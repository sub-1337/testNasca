add_executable(calculator_tests
    tests_application_config.cpp
    tests_application.cpp
    tests_application_input.cpp
    tests_application_calc_core.cpp
)

target_link_libraries(calculator_tests PRIVATE
    calculator_lib                  # Ваша библиотека
    Catch2::Catch2WithMain          # Catch2 с main функцией
    Boost::program_options
    tomlplusplus::tomlplusplus
    spdlog::spdlog
)

# Включаем CTest
include(CTest)
include(Catch)

# Автоматическое обнаружение тестов Catch2
catch_discover_tests(calculator_tests)

configure_file(files/config_1.toml ${CMAKE_CURRENT_BINARY_DIR}/config_1.toml COPYONLY)
configure_file(files/config_2.toml ${CMAKE_CURRENT_BINARY_DIR}/config_2.toml COPYONLY)
configure_file(files/config_3.toml ${CMAKE_CURRENT_BINARY_DIR}/config_3.toml COPYONLY)
configure_file(files/config_4.toml ${CMAKE_CURRENT_BINARY_DIR}/config_4.toml COPYONLY)
configure_file(files/config_5_only_input.toml ${CMAKE_CURRENT_BINARY_DIR}/config_5_only_input.toml COPYONLY)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/input")
configure_file(files/input/test_1.csv ${CMAKE_CURRENT_BINARY_DIR}/input/test_1.csv COPYONLY)
