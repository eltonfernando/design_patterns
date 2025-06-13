#include "Mediator.hpp"

#include <iostream>

// Mediator
void Mediator::setTextBox(std::shared_ptr<TextBox> textbox) {
    textbox_ = textbox;
}

void Mediator::setCheckBox(std::shared_ptr<CheckBox> checkbox) {
    checkbox_ = checkbox;
}

void Mediator::setButton(std::shared_ptr<Button> button) {
    button_ = button;
}

void Mediator::notify(Component* sender, const std::string& event) {
    auto textbox = textbox_.lock();
    auto checkbox = checkbox_.lock();
    auto button = button_.lock();

    if (!textbox || !checkbox || !button) return;

    if (event == "text_changed" || event == "checkbox_toggled") {
        bool enable = !textbox->getText().empty() && checkbox->isChecked();
        button->setEnabled(enable);
    } else if (event == "button_clicked") {
        if (!textbox->getText().empty() && checkbox->isChecked()) {
            std::cout << "Enviado com sucesso!\n";
        } else {
            std::cout << "Não é possível enviar. Preencha todos os campos.\n";
        }
    }
}

// TextBox
void TextBox::setMediator(std::shared_ptr<Mediator> mediator) {
    mediator_ = mediator;
}

void TextBox::input(const std::string& text) {
    text_ = text;
    if (auto med = mediator_.lock()) med->notify(this, "text_changed");
}

std::string TextBox::getText() const {
    return text_;
}

// CheckBox
void CheckBox::setMediator(std::shared_ptr<Mediator> mediator) {
    mediator_ = mediator;
}

void CheckBox::toggle() {
    checked_ = !checked_;
    if (auto med = mediator_.lock()) med->notify(this, "checkbox_toggled");
}

bool CheckBox::isChecked() const {
    return checked_;
}

// Button
void Button::setMediator(std::shared_ptr<Mediator> mediator) {
    mediator_ = mediator;
}

void Button::click() {
    if (auto med = mediator_.lock()) med->notify(this, "button_clicked");
}

void Button::setEnabled(bool enabled) {
    enabled_ = enabled;
}

bool Button::isEnabled() const {
    return enabled_;
}
