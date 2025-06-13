#include "Interprete.hpp"

#include <iostream>
void GUIContext::add_component(const std::string& component_type, const std::string& label) {
    components_.emplace_back(component_type, label);
}

void GUIContext::render() const {
    for (const auto& [type, label] : components_) {
        std::cout << "Componente: " << type << " - Label: " << label << std::endl;
    }
}

ButtonExpression::ButtonExpression(const std::string& label) : label_(label) {}

void ButtonExpression::interpret(GUIContext& context) const {
    context.add_component("Button", label_);
}

TextBoxExpression::TextBoxExpression(const std::string& label) : label_(label) {}

void TextBoxExpression::interpret(GUIContext& context) const {
    context.add_component("TextBox", label_);
}
