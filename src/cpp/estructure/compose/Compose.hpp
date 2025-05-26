#pragma once

#include <memory>
#include <string>
#include <vector>
class IFileSystem {
   public:
    virtual void show(int indent = 0) const = 0;
    virtual ~IFileSystem() = default;
};

class File : public IFileSystem {
   public:
    File(std::string name);
    void show(int indent = 0) const override;

   private:
    std::string name_;
};

class Directory : public IFileSystem {
   public:
    Directory(std::string name);
    void add(std::unique_ptr<IFileSystem> child);
    void show(int indent = 0) const override;

   private:
    std::string name_;
    std::vector<std::unique_ptr<IFileSystem>> children_;
};
