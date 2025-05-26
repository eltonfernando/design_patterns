#pragma once
#include "Dialog.hpp"

class LinuxButton : public IButton {
   public:
    void draw() const override;
};

class LinuxLabel : public ILabel {
   public:
    void draw() const override;
};

class LinuxDialogBuilder : public DialogBuilder {
   public:
    LinuxDialogBuilder();
    void buildTitle() override;
    void buildButton() override;
    void buildLabel() override;
    std::unique_ptr<Dialog> getResult() override;

   private:
    std::unique_ptr<Dialog> dialog_;
};
