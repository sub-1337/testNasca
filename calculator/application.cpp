#include "application.h"
#include <toml++/toml.hpp>
#include <spdlog/spdlog.h>

void application::read_files()
{
    try
    {
        if (!_app_input)
        {
            _app_input = std::make_unique<application_input>(_app_config->get_input(), _app_config->get_filename_mask());
        }
        if (_app_input)
        {
            _app_input->read();
            _app_data = _app_input->get_data();
        }
    }
    catch(...)
    {
        spdlog::error("Error while read file\n");
        exit(1);
    }
}

void application::calc()
{
    try
    {
        if (!_app_calc_core)
        {
            _app_calc_core = std::make_unique<application_calc_core>(_app_data);
        }
        if (_app_calc_core)
        {
            _app_calc_core->calc();
        }
    }
    catch(...)
    {
        spdlog::error("Error while calculating.\n");
        exit(1);
    }
}

void application::write()
{
    try
    {
        if(!_app_output)
        {
            _app_output = std::make_unique<application_output>(_app_data, _app_config->get_output());
        }
        if (_app_output)
        {
            _app_output->write();
        }
    }
    catch(...)
    {
        spdlog::error("Error while writing file.\n");
        exit(1);
    }
}

void application::run()
{
    read_files();
    calc();
    write();
}
