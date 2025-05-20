#pragma once
#include "GuiFactory.h"

class WindowsButton : public AbstractButton {
public:
    void draw() override;
};

class WindowsLabel : public AbstractLabel {
public:
    void draw() override;
};

class WindowsFactory : public GuiFactory {
public:
    AbstractButton* createButton() override;
    AbstractLabel* createLabel() override;
};
