
#include "ChainOfResponsibility.hpp"

#include <iostream>
GUIComponent::GUIComponent(std::shared_ptr<GUIComponent> parent) : parent_(std::move(parent)) {}

void GUIComponent::handleClick(int x, int y) {
    if (parent_) {
        parent_->handleClick(x, y);
    }
}

Button::Button(int x, int y, int width, int height, std::shared_ptr<GUIComponent> parent)
    : GUIComponent(parent), x_(x), y_(y), width_(width), height_(height) {}

void Button::handleClick(int x, int y) {
    if (x >= x_ && x < x_ + width_ && y >= y_ && y < y_ + height_) {
        std::cout << "Clicou no botão" << std::endl;
    } else {
        GUIComponent::handleClick(x, y);
    }
}

Panel::Panel(std::shared_ptr<GUIComponent> parent) : GUIComponent(parent) {}

void Panel::handleClick(int x, int y) {
    std::cout << "Clicou no painel" << std::endl;
    GUIComponent::handleClick(x, y);
}

Window::Window(std::shared_ptr<GUIComponent> parent) : GUIComponent(parent) {}

void Window::handleClick(int x, int y) {
    std::cout << "Clicou na janela" << std::endl;
    GUIComponent::handleClick(x, y);
}
