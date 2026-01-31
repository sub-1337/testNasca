#include "../application.h"
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

TEST_CASE("Test app", "[core]")
{
    application app("config_5_only_input.toml");
    app.run();
    //REQUIRE();
}
