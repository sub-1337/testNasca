#include <boost/program_options.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    namespace po = boost::program_options;
    po::options_description desc("Options of the calculator");
    desc.add_options()
        ("-cfg", "produce help message")
        ("compression", po::value<int>(), "set compression level")
        ;
    return 0;
}
