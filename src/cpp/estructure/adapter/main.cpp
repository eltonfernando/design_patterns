#include <iostream>

#include "Adapter.hpp"
int main() {
  std::unique_ptr<LegacyButton> button = std::make_unique<LegacyButton>();
  LegacyButtonAdapter adapter(std::move(button));
  adapter.draw();
  std::cout << "adapter!" << std::endl;
  return 0;
}
