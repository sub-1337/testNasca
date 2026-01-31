#ifndef APPLICATION_INPUT_H
#define APPLICATION_INPUT_H
#include <string>
#include <vector>

class application_input
{
private:
    std::string _directory;
    std::vector<std::string> _filename_mask;
public:
    struct iterator
    {

    };
    application_input(std::string directory, std::vector<std::string> filename_mask)
        : _directory(directory), _filename_mask(filename_mask)
    {

    }


};

#endif // APPLICATION_INPUT_H
