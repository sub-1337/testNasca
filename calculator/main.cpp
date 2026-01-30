#include <boost/filesystem.hpp>
#include <iostream>

int main() {
    boost::filesystem::path p("C:/");
    std::cout << "Files in C:/:" << std::endl;
    for (auto& entry : boost::filesystem::directory_iterator(p)) {
        std::cout << entry.path().string() << std::endl;
    }
    return 0;
}
