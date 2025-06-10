#pragma once

#include <memory>
class GUIComponent {
public:
    explicit GUIComponent(std::shared_ptr<GUIComponent> parent = nullptr);
    virtual ~GUIComponent()=default;
    virtual void handleClick(int x, int y);
protected:
    std::shared_ptr<GUIComponent> parent_;
};

class Button : public GUIComponent {
public:
    explicit Button(int x, int y, int width, int height, std::shared_ptr<GUIComponent> parent = nullptr);
    void handleClick(int x, int y) override;
private:
    int x_;
    int y_;
    int width_;
    int height_;
};

class Panel : public GUIComponent {
public:
    explicit Panel(std::shared_ptr<GUIComponent> parent = nullptr);
    void handleClick(int x, int y) override;
};

class Window : public GUIComponent {
public:
    explicit Window(std::shared_ptr<GUIComponent> parent = nullptr);
    void handleClick(int x, int y) override;
};