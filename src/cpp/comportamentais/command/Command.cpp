#include "Command.hpp"

#include <iostream>

void Editor::copy() {
    std::cout << "Copiando..." << std::endl;
}

void Editor::paste(std::string& content) {
    std::cout << "Colando..." << std::endl;
    text_.push_back(content);
    for (auto& line : text_) {
        std::cout << line << std::endl;
    }
}
void ::Editor::remove(int index) {
    std::cout << "Removendo..." << text_[index] << std::endl;
    text_.erase(text_.begin() + index);
    for (auto& line : text_) {
        std::cout << line << std::endl;
    }
}

PasteCommand::PasteCommand(Editor* editor, std::string& content)
    : editor_(editor), content_(content) {}

void PasteCommand::execute() {
    editor_->paste(content_);
}

void PasteCommand::undo() {
    editor_->remove(editor_->text_.size() - 1);
}

void Button::click(Command* command) {
    command->execute();
    commands_.push_back(command);
}

void Button::undo() {
    if (commands_.size() > 0) {
        commands_.back()->undo();
        commands_.pop_back();
    }
}
