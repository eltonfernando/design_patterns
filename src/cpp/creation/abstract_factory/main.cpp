#include "GuiFactory.h"
#include "WindowsGui.h"
#include "LinuxGui.h"
#include <memory>
#include <iostream>

#ifdef _WIN32
#define CURRENT_OS "windows"
#else
#define CURRENT_OS "linux"
#endif

std::unique_ptr<GuiFactory> getFactory() {
    if (std::string(CURRENT_OS) == "windows") {
        return std::make_unique<WindowsFactory>();
    } else if (std::string(CURRENT_OS) == "linux") {
        return std::make_unique<LinuxFactory>();
    } else {
        throw std::runtime_error("Unknown OS");
    }
}

int main() {
    auto factory = getFactory();
    std::unique_ptr<AbstractButton> button(factory->createButton());
    std::unique_ptr<AbstractLabel> label(factory->createLabel());

    button->draw();
    label->draw();

    return 0;
}
