#ifndef APPLICATION_CONFIG_H
#define APPLICATION_CONFIG_H
#include <string>
#include <vector>

class application_config
{
private:
    std::string _config_path;
    std::string _input;
    std::string _output;
    std::vector<std::string> _filename_mask;
    void read_file();
public:
    application_config(std::string config_path_) : _config_path(config_path_)
    {
        read_file();
    };
};

#endif // APPLICATION_CONFIG_H
