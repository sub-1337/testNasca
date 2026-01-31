#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>
#include "application_config.h"
#include "application_input.h"
#include <memory>

class application
{
private:
    std::unique_ptr<application_config> _app_config;
    std::unique_ptr<application_input> _app_input;
public:
    application(const std::string& configPath) : _app_config(std::make_unique<application_config>(configPath)) {}
    void parse_config();
    void read_files();
    void run();
};
#endif // APPLICATION_H
