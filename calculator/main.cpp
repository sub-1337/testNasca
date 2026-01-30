#include <boost/program_options.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
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
    if (vm.count("config")) {
        std::cout << "Config: " << configPath << "\n";
    }
    return 0;
}
