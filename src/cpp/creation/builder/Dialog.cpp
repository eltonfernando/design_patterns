#include "Dialog.hpp"

#include <iostream>

void Dialog::setTitle(const std::string &title) { title_ = title; }

void Dialog::setButton(std::unique_ptr<IButton> btn) {
  button_ = std::move(btn);
}

void Dialog::setLabel(std::unique_ptr<ILabel> lbl) { label_ = std::move(lbl); }

void Dialog::show() const {
  std::cout << "Dialog Title: " << title_ << '\n';
  if (label_) label_->draw();
  if (button_) button_->draw();
}
