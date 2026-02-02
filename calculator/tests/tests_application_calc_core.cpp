#include "../application_calc_core.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <filesystem>

TEST_CASE("Test calc core", "[core]")
{
    std::shared_ptr<application_data> data = std::make_shared<application_data>();
    data->data_in.push_back(application_input_record{.receive_ts = 1000, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1100, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1200, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1300, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1400, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1500, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1600, .price = 100.0});
    application_calc_core calc(data);
    calc.calc();
    REQUIRE(data->data_out[0].price_median == Catch::Approx(100.0));
}


TEST_CASE("Test calc core 2", "[core]")
{
    std::shared_ptr<application_data> data = std::make_shared<application_data>();
    application_calc_core calc(data);
    calc.calc();
    REQUIRE(data->data_out.size() == 0);
}

