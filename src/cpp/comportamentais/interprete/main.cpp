#include <memory>
#include <vector>

#include "Interprete.hpp"

int main() {
    GUIContext context;

    std::vector<std::unique_ptr<Expression>> expressions;
    expressions.emplace_back(std::make_unique<ButtonExpression>("Salvar"));
    expressions.emplace_back(std::make_unique<TextBoxExpression>("Nome"));
    expressions.emplace_back(std::make_unique<ButtonExpression>("Cancelar"));

    for (const auto& expr : expressions) {
        expr->interpret(context);
    }

    context.render();
    return 0;
}
