#include <iostream>

#include "Adapter.hpp"
int main() {
  LegacyButton button;
  auto adapter = LegacyButtonAdapter(&button);
  adapter.draw();
  std::cout << "adapter!" << std::endl;
  return 0;
}
