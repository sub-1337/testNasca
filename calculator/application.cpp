#include "application.h"
#include <toml++/toml.hpp>

void application::parse_config()
{

}

void application::read_files()
{
    if (!_app_input)
    {
        _app_input = std::make_unique<application_input>(_app_config->get_input(), _app_config->get_filename_mask());
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
