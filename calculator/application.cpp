#include "application.h"
#include <toml++/toml.hpp>
#include <spdlog/spdlog.h>

void application::parse_config()
{

}

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

}

void application::write()
{

}

void application::run()
{
    parse_config();
    read_files();
    calc();
    write();
}
