#include "../application_config.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Test app config", "[core]")
{
    // std::ofstream file("config_1.toml");
    // if (file.is_open()) {
    //     outFile << "New content here!" << std::endl;
    //     outFile.close();
    // }
    application_config config("files/config_1.toml");
}
