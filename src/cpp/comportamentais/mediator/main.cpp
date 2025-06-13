#include <memory>

#include "Mediator.hpp"

int main() {
    auto mediator = std::make_shared<Mediator>();

    auto textbox = std::make_shared<TextBox>();
    auto checkbox = std::make_shared<CheckBox>();
    auto button = std::make_shared<Button>();

    textbox->setMediator(mediator);
    checkbox->setMediator(mediator);
    button->setMediator(mediator);

    mediator->setTextBox(textbox);
    mediator->setCheckBox(checkbox);
    mediator->setButton(button);

    textbox->input("Olá mundo");
    checkbox->toggle();
    button->click();

    return 0;
}
