// Flyweight.hpp
#pragma once
#include <memory>
#include <string>
#include <vector>

class BtnFlyweight {
   public:
    explicit BtnFlyweight(const std::string& color);
    void draw(const std::string& label, int x, int y) const;
    const std::string& color() const;
    virtual ~BtnFlyweight() = default;

   private:
    std::string color_;
};

class Factory {
   public:
    std::shared_ptr<BtnFlyweight> getBtnFlyweight(const std::string& color);
    virtual ~Factory() = default;

   private:
    std::vector<std::shared_ptr<BtnFlyweight>> btns_;
};
