#include "Command.hpp"
int main() {
    Editor editor;
    Button button;
    std::string content = "cmd1";
    std::string content2 = "cmd2";
    auto cmd1 = new PasteCommand(&editor, content);
    auto cmd2 = new PasteCommand(&editor, content2);
    button.click(cmd1);
    button.click(cmd2);
    button.undo();
    button.undo();
    return 0;
}