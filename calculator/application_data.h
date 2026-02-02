#ifndef APPLICATION_DATA_H
#define APPLICATION_DATA_H
#include <vector>
#include <algorithm>

struct application_input_record
{
    long receive_ts;
    double price;
};

struct application_output_record
{
    long receive_ts;
    double price_median;
};

struct application_data
{
    std::vector<application_input_record> data_in;
    std::vector<application_output_record> data_out;
    void sort_input()
    {
        std::sort(data_in.begin(), data_in.end(),
                  [](const application_input_record& a,
                     const application_input_record& b)
                  {
                      return a.receive_ts < b.receive_ts;
                  });
    }
};

#endif // APPLICATION_DATA_H
