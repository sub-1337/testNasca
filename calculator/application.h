#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>
#include "application_config.h"
#include "application_input.h"
#include "application_output.h"
#include "application_calc_core.h"
#include <memory>

class application
{
private:
    std::unique_ptr<application_config> _app_config;
    std::unique_ptr<application_input> _app_input;
    std::unique_ptr<application_output> _app_output;
    std::unique_ptr<application_calc_core> _app_calc_core;
protected:
    void parse_config();
    void read_files();
    void calc();
    void write();
public:
    application(const std::string& configPath) : _app_config(std::make_unique<application_config>(configPath)) {}
    void run();
};
#endif // APPLICATION_H
