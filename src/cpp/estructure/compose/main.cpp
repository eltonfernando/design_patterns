#include <iostream>

#include "Compose.hpp"
int main() {
    Directory root("root");
    root.add(std::make_unique<File>("file1"));
    auto dir1 = std::make_unique<Directory>("dir1");
    dir1->add(std::make_unique<File>("file1.1"));
    root.add(std::move(dir1));
    root.add(std::make_unique<File>("file2"));
    root.add(std::make_unique<Directory>("dir2"));
    root.show();
    std::cout << "compose" << std::endl;
    return 0;
}
