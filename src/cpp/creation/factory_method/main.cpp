
#include <iostream>
#include <memory>

#include "LinuxDialog.hpp"

int main() {
  LinuxDialog dialog;
  dialog.render();
  std::unique_ptr<IButton> button = dialog.createButton();
  button->draw();
  return 0;
}
