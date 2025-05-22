#pragma once
#include "GuiFactory.h"

class LinuxButton : public AbstractButton {
 public:
  void draw() override;
};

class LinuxLabel : public AbstractLabel {
 public:
  void draw() override;
};

class LinuxFactory : public GuiFactory {
 public:
  AbstractButton* createButton() override;
  AbstractLabel* createLabel() override;
};
