#include "LinuxDialog.hpp"

#include <iostream>

void LinuxButton::draw() const { std::cout << "Linux Button\n"; }

void LinuxLabel::draw() const { std::cout << "Linux Label\n"; }

LinuxDialogBuilder::LinuxDialogBuilder() {
  dialog_ = std::make_unique<Dialog>();
}

void LinuxDialogBuilder::buildTitle() { dialog_->setTitle("Linux Dialog"); }

void LinuxDialogBuilder::buildButton() {
  dialog_->setButton(std::make_unique<LinuxButton>());
}

void LinuxDialogBuilder::buildLabel() {
  dialog_->setLabel(std::make_unique<LinuxLabel>());
}

std::unique_ptr<Dialog> LinuxDialogBuilder::getResult() {
  return std::move(dialog_);
}
