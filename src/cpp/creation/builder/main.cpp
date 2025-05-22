#include "Director.hpp"
#include "LinuxDialog.hpp"

int main() {
  LinuxDialogBuilder builder;
  DialogDirector director(&builder);
  auto dialog = director.construct();
  dialog->show();
  return 0;
}
