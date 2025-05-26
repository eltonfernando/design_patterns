#pragma once

class AbstractButton {
   public:
    virtual void draw() = 0;
    virtual ~AbstractButton() = default;
};

class AbstractLabel {
   public:
    virtual void draw() = 0;
    virtual ~AbstractLabel() = default;
};

class GuiFactory {
   public:
    virtual AbstractButton *createButton() = 0;
    virtual AbstractLabel *createLabel() = 0;
    virtual ~GuiFactory() = default;
};
