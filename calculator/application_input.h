#ifndef APPLICATION_INPUT_H
#define APPLICATION_INPUT_H
#include <string>
#include <vector>
#include <memory>
#include "application_data.h"

class application_input
{
private:
    std::string _directory;
    std::vector<std::string> _filename_mask;
    std::vector<std::string> _files_to_read;
    std::shared_ptr<application_data> _data;

    void get_files_path();
    void read_single_file(std::string path);
    void sort();
public:
    void read();
    application_input(std::string directory, std::vector<std::string> filename_mask)
        : _directory(directory), _filename_mask(filename_mask)
    {
        _data = std::make_shared<application_data>();
    }
    std::shared_ptr<application_data> get_data()
    {
        return _data;
    }
};

#endif // APPLICATION_INPUT_H
