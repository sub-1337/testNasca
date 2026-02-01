#include "application_calc_core.h"
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/median.hpp>
#include <vector>
#include <cmath>
#include <spdlog/spdlog.h>

bool areEqual(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

void application_calc_core::calc(std::shared_ptr<application_data> data)
{
    using namespace boost::accumulators;
// Не совсем понимаю писать так или по-дргуому
/*
    std::vector<double> data_curr;
    for (auto& curr_row : data->data_in)
    {
        data_curr.push_back(curr_row.price);
        spdlog::info("Curr row is {}", curr_row.price);

        accumulator_set<double, stats<tag::median>> acc;

        for(double x : data_curr) {
           acc(x);
        }

        // Получаем медиану
        spdlog::info("Median is {}", median(acc));
    }
*/
    // Или так
    accumulator_set<double, stats<tag::median>> acc;
    long count_of_elems = 0;
    long count_of_elems_needs_to_skip = 5;
    double prev_median_number = 0;
    for (auto& curr_row : data->data_in)
    {
        double price = curr_row.price;
        long receive_ts = curr_row.receive_ts;
        spdlog::debug("Curr row is {}", price);

        acc(price);

        // Get median
        double median_number = median(acc);

        spdlog::debug("Median is {}",  median_number);

        // We need to skip first 5 elements to calc
        // median properly
        if (count_of_elems >= count_of_elems_needs_to_skip)
        {
            // If not equal - add to output
            if (!areEqual(median_number, prev_median_number))
            {
                data->data_out.push_back(application_output_record({.receive_ts = receive_ts, .price_median = median_number}));
                // Save new last value
                prev_median_number = median_number;
            }
        }
        count_of_elems++;
    }

}
