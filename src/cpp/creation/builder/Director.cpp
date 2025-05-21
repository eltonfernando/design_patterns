#include "Director.hpp"

DialogDirector::DialogDirector(DialogBuilder* builder) : builder_(builder) {}

std::unique_ptr<Dialog> DialogDirector::construct() {
    builder_->buildTitle();
    builder_->buildLabel();
    builder_->buildButton();
    return builder_->getResult();
}
