#include <boost/program_options.hpp>
#include <iostream>
#include <toml++/toml.h>
#include <memory>

class Application
{
private:
    std::string configPath;
public:
    Application(const std::string& configPath) : configPath(configPath) {}
    void Run() {  }
};

int main(int argc, char *argv[]) {
    std::unique_ptr<Application> app;

    namespace po = boost::program_options;

    std::string configPath;

    po::options_description desc("Options of the calculator");
    desc.add_options()
    ("config,cfg", po::value<std::string>(&configPath), "config file path");

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch(po::unknown_option& ex)
    {
        std::cout << "Bad options" << "\n";
        exit(1);
    }
    po::notify(vm);
    if (vm.count("config") > 0 or vm.count("cfg") > 0 ) {
        app = std::make_unique<Application>(configPath);
    }
    if (app)
        app->Run();
    return 0;
}
