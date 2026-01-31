#include <boost/program_options.hpp>
#include <iostream>
#include <toml++/toml.h>
#include <memory>
#include "application.h"


int main(int argc, char *argv[]) {
    std::unique_ptr<application> app;

    // Parse command lines
    namespace po = boost::program_options;
    std::string config_path;
    po::options_description desc("Options of the calculator");
    desc.add_options()
    ("config,cfg", po::value<std::string>(&config_path), "config file path");
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch(po::unknown_option& ex)
    {
        std::cout << "Bad options" << "\n";
        exit(1);
    }

    // Set default config path
    po::notify(vm);
    // if (!(vm.count("config") > 0 or vm.count("cfg") > 0)) {
    //     config_path = "config.toml";
    // }

    // Runs application
    app = std::make_unique<application>(config_path);
    if (app)
        app->run();

    return 0;
}
