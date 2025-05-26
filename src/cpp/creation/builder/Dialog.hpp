#pragma once
#include <memory>
#include <string>

class IButton {
   public:
    virtual void draw() const = 0;  // método puramente virtual
    virtual ~IButton() = default;   // destrutor virtual obrigatório em interfaces
};

class ILabel {
   public:
    virtual void draw() const = 0;
    virtual ~ILabel() = default;
};

class Dialog {
   public:
    void setTitle(const std::string &title);
    void setButton(std::unique_ptr<IButton> btn);
    void setLabel(std::unique_ptr<ILabel> lbl);
    void show() const;

   private:
    std::string title_;
    std::unique_ptr<IButton> button_;
    std::unique_ptr<ILabel> label_;
};

class DialogBuilder {
   public:
    virtual void buildTitle() = 0;
    virtual void buildButton() = 0;
    virtual void buildLabel() = 0;
    virtual std::unique_ptr<Dialog> getResult() = 0;
    virtual ~DialogBuilder() = default;
};
