#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include <memory>

class Car {
private:
    std::string model;
    std::string color;
    int year;

public:
    Car(const std::string& model, const std::string& color, int year);
    std::unique_ptr<Car> clone() const;
    void setColor(const std::string& color);
    void setYear(int year);
    std::string toString() const;
};

#endif
