#include "application_input.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>
#include <filesystem>

void application_input::get_files_path()
{
    namespace fs = std::filesystem;
    std::string path = _directory;

    // Scan given directory for files
    // and add them to read list
    for (const auto& entry : fs::directory_iterator(path)) {
        std::string curr_file = entry.path().string();
        auto curr_file_obj = entry.path();
        if (fs::is_regular_file(curr_file))
        {
            spdlog::debug("file discovered {}", curr_file);

            // Do we need to not filter files
            if (_filename_mask.size() == 0)
            {
                _files_to_read.push_back(curr_file);
            }
            else // Filter files
            {
                for (const auto& filename : _filename_mask)
                {
                    // If we need file to read
                    if (curr_file_obj.stem() == filename)
                    {
                        _files_to_read.push_back(curr_file);
                    }
                }
            }
        }

    }
}

void application_input::read_single_file(std::string path)
{
    std::ifstream file(path);
    std::string line;

    int receive_ts_col = -1;
    int price_col = -1;
    long line_number = 0;

    // Parse CSV
    // Get line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        int row_i = 0;
        application_input_record curr_record;
        // Get cell
        while (std::getline(ss, cell, ';'))
        {
            if (line_number == 0)
            {
                if (cell == "receive_ts")
                {
                    if (receive_ts_col == -1)
                    {
                        receive_ts_col = row_i;
                    }
                }
                if (cell == "price")
                {
                    if (price_col == -1)
                    {
                        price_col = row_i;
                    }
                }
            }
            else if (receive_ts_col == -1 or price_col == -1)
            {
                spdlog::error("No vital receive_ts or price in csv found.");
                exit(1);
            }
            if (line_number > 0)
            {
                if (row_i == receive_ts_col)
                    curr_record.receive_ts = std::stol(cell);
                if (row_i == price_col)
                    curr_record.price = std::stod(cell);
            }
            row_i++;
        }
        if (line_number > 0)
            _data->data_in.push_back(curr_record);
        line_number++;
    }
}

// Sort by time
void application_input::sort()
{
    _data->sort_input();
}

void application_input::read()
{
    get_files_path();

    for(auto& curr_file_path : _files_to_read)
        read_single_file(curr_file_path);

    sort();
}
