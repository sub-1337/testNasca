#include "../application_input.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <filesystem>
#include <spdlog/spdlog.h>

TEST_CASE("Test input app", "[core]")
{
    //spdlog::set_level(spdlog::level::debug);
    application_input input("input", {"test_1"});
    input.read();
    std::shared_ptr<application_data> data = input.get_data();
    REQUIRE(data->data_in[0].receive_ts == 1000);
    REQUIRE(data->data_in[1].receive_ts == 2000);
    REQUIRE(data->data_in[2].receive_ts == 2000);
    REQUIRE(data->data_in[3].receive_ts == 3000);
    REQUIRE(data->data_in[4].receive_ts == 6000);

    REQUIRE(data->data_in[0].price == Catch::Approx(100.0));
    REQUIRE(data->data_in[3].price == Catch::Approx(103.0));
    REQUIRE(data->data_in[4].price == Catch::Approx(100.0));
    //REQUIRE();
}
