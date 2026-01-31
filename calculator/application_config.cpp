#include "application_config.h"
#include <toml++/toml.h>
#include <spdlog/spdlog.h>

void application_config::read_file()
{
    try
    {
        auto config = toml::parse_file(_config_path);
    }
    catch(...)
    {
        spdlog::error("Can't parse input file {}", _config_path);
        exit(1);
    }
}
