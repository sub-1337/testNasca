#ifndef APPLICATION_OUTPUT_H
#define APPLICATION_OUTPUT_H
#include <string>
#include <vector>
#include <memory>
#include "application_data.h"

class application_output
{
private:
    std::string _directory;
    std::shared_ptr<application_data> _data;
public:
    application_output(std::shared_ptr<application_data> data, const std::string& directory)
        : _data(data), _directory(directory) {};

    void write();
};

#endif // APPLICATION_OUTPUT_H
