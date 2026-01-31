#include "application_config.h"
#include <filesystem>
#include <toml++/toml.h>
#include <spdlog/spdlog.h>

void application_config::read_file()
{
    try
    {
        auto config = toml::parse_file(_config_path);
        _input = config["main"]["input"].value_or("");
        if (_input == "")
        {
            spdlog::error("Mandatory parameter \"input\" in config not found");
            exit(1);
        }
        _output = config["main"]["output"].value_or("");
        if (_output == "")
        {
            _output = "output";
            namespace fs = std::filesystem;
            if (fs::create_directories(_output)) {
                spdlog::info("No output folder set. Default folder \"{}\" created", _output);
            } else {
                if (fs::exists(_output) && fs::is_directory(_output)) {
                    spdlog::info("No output folder set. Default folder \"{}\" exist, using it", _output);
                } else {
                    spdlog::error("No output folder set. Default folder \"{}\" can't be created", _output);
                    exit(1);
                }
            }
        }

        // Reading mask
        if (auto* array = config["main"]["filename_mask"].as_array()) {
            // Iterate array in config
            for (auto&& node : *array) {
                // Trying to read
                if (auto val = node.value<std::string>()) {
                    _filename_mask.push_back(*val);
                }
            }
        }

        if (_filename_mask.size())
        {
            spdlog::debug("Masks read:");
            for (const auto& mask : _filename_mask)
                spdlog::debug("Masks: {}", mask);
        }
        else
        {
            spdlog::info("No file masks in config");
        }
    }
    catch(...)
    {
        spdlog::error("Can't parse input file {}", _config_path);
        exit(1);
    }
}
