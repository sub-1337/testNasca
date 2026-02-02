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


TEST_CASE("Test calc core 3", "[core]")
{
    std::shared_ptr<application_data> data = std::make_shared<application_data>();
    data->data_in.push_back(application_input_record{.receive_ts = 1000, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1100, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1200, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1300, .price = 100.0});

    data->data_in.push_back(application_input_record{.receive_ts = 1400, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1500, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1600, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1600, .price = 120.0});
    application_calc_core calc(data);
    calc.calc();
    REQUIRE(data->data_out[0].price_median == Catch::Approx(100.0));
    REQUIRE(data->data_out[1].price_median == Catch::Approx(101.111));
}

TEST_CASE("Test calc core 4", "[core]")
{
    std::shared_ptr<application_data> data = std::make_shared<application_data>();
    data->data_in.push_back(application_input_record{.receive_ts = 1000, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1100, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1200, .price = 100.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1300, .price = 100.0});

    data->data_in.push_back(application_input_record{.receive_ts = 1400, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1500, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1600, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1600, .price = 120.0});

    data->data_in.push_back(application_input_record{.receive_ts = 1700, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1800, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 1900, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 2000, .price = 120.0});

    data->data_in.push_back(application_input_record{.receive_ts = 2100, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 2200, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 2300, .price = 120.0});
    data->data_in.push_back(application_input_record{.receive_ts = 2400, .price = 120.0});
    application_calc_core calc(data);
    calc.calc();
    REQUIRE(data->data_out[0].price_median == Catch::Approx(100.0));
    REQUIRE(data->data_out[1].price_median == Catch::Approx(101.111));
    REQUIRE(data->data_out[2].price_median == Catch::Approx(103.395));
    REQUIRE(data->data_out[3].price_median == Catch::Approx(106.7245));
    REQUIRE(data->data_out[4].price_median == Catch::Approx(109.889));
    REQUIRE(data->data_out[5].price_median == Catch::Approx(112.99));
}

