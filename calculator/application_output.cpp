#include "application_output.h"
#include <fstream>
#include <iostream>
#include <spdlog/spdlog.h>

void application_output::write()
{
    using namespace std::string_literals;
    spdlog::info(_directory +  "/"s + "output.csv"s);
    std::ofstream file(_directory +  "/"s + "output.csv"s);
    if (!file) {
        spdlog::error("Can't open file");
        exit(1);
    }

    // заголовок
    file << "receive_ts;price_median\n";

    // строки данных
    file << std::fixed << std::setprecision(2);
    for (const auto& row : _data->data_out) {
        file << row.receive_ts << ";"
             << row.price_median << "\n";
    }

    file.close();
}
