#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>
class Application
{
private:
    std::string _configPath;
public:
    Application(const std::string& configPath) : _configPath(configPath) {}
    void parse();
    void run();
};
#endif // APPLICATION_H
