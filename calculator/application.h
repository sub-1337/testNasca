#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>
#include "application_config.h"

class application
{
private:
    //std::string _configPath;
    application_config _app_config;

public:
    application(const std::string& configPath) : _app_config(configPath) {}
    void parse();
    void run();
};
#endif // APPLICATION_H
