#include "LinuxDialog.hpp"
#include "Director.hpp"

int main() {
    LinuxDialogBuilder builder;
    DialogDirector director(&builder);
    auto dialog = director.construct();
    dialog->show();
    return 0;
}
