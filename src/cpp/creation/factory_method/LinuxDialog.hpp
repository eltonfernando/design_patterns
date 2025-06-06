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
class LinuxDialog : public IDialog {
   public:
    LinuxDialog();
    void render() const override;
    virtual std::unique_ptr<IButton> createButton() const override;
};
