#pragma once
#include "GuiFactory.hpp"

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
  AbstractButton *createButton() override;
  AbstractLabel *createLabel() override;
};
