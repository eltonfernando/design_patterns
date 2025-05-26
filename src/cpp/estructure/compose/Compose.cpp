#include "Compose.hpp"

#include <iostream>
File::File(std::string name) : name_(name) {}

void File::show(int indent) const {
    std::cout << std::string(indent, ' ') << name_ << std::endl;
}

Directory::Directory(std::string name) : name_(name) {}

void Directory::add(std::unique_ptr<IFileSystem> child) {
    children_.push_back(std::move(child));
}

void Directory::show(int indent) const {
    std::cout << std::string(indent, ' ') << name_ << std::endl;
    for (const auto &child : children_) {
        child->show(indent + 2);
    }
}
