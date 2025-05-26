#pragma once
#include "Dialog.hpp"

class DialogDirector {
 public:
  DialogDirector(DialogBuilder *builder);
  std::unique_ptr<Dialog> construct();

 private:
  DialogBuilder *builder_;
};
