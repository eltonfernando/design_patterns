#pragma once

#include <memory>
class IButton {
    public: 
        virtual void draw() const = 0;
        virtual ~IButton() = default;
};
class ILabel {
    public:
        virtual void draw() const = 0;
        virtual ~ILabel() = default;
};
class IDialog {
    public:
        virtual void render() const  = 0;
        virtual std::unique_ptr<IButton> createButton() const = 0;
        virtual ~IDialog() = default;
};
