#include "../application_config.h"
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

TEST_CASE("Test app config", "[core]")
{
    application_config config("config_1.toml");
    REQUIRE(config.get_input() == "input_dir" );
    REQUIRE(config.get_output() == "test\\output_dir" );
    REQUIRE(config.get_filename_mask().size() == 0);
}

TEST_CASE("Test app config 2", "[core]")
{
    application_config config("config_2.toml");
    REQUIRE(config.get_input() == "input_dir" );
    REQUIRE(config.get_output() == "output" );
    REQUIRE(config.get_filename_mask().size() == 0);
    namespace fs = std::filesystem;
    REQUIRE((fs::exists("output") && fs::is_directory("output")) == true);
}

TEST_CASE("Test app config 3", "[core]")
{
    namespace fs = std::filesystem;
    //if (fs::exists("output"))
    //    fs::remove("output");
    application_config config("config_3.toml");
    REQUIRE(config.get_input() == "input_dir" );
    REQUIRE(config.get_output() == "output" );
    REQUIRE(config.get_filename_mask().size() == 1);
    REQUIRE(config.get_filename_mask()[0] == "trade");
    REQUIRE((fs::exists("output") && fs::is_directory("output")) == true);
}

TEST_CASE("Test app config 4", "[core]")
{
    application_config config("config_4.toml");
    REQUIRE(config.get_input() == "/home/user/input" );
    REQUIRE(config.get_output() == "/home/user/output" );
    REQUIRE(config.get_filename_mask().size() == 2);
    REQUIRE(config.get_filename_mask()[0] == "trade");
    REQUIRE(config.get_filename_mask()[1] == "level");
}


