#include <boost/program_options.hpp>
#include <iostream>
#include <memory>
#include "application.h"

#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("Program run");
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
    catch(const po::unknown_option& ex)
    {
        spdlog::error("Unknown parameters");
        exit(1);
    }
    catch(...)
    {
        spdlog::error("Generic error while parsing parameters");
        exit(1);
    }

    po::notify(vm);

    // Runs application
    app = std::make_unique<application>(config_path);
    if (app)
        app->run();

    return 0;
}
