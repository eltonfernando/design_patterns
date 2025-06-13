
#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include <memory>
#include <string>

class Mediator;

// Interfaces de componentes
class Component {
   public:
    virtual void setMediator(std::shared_ptr<Mediator> mediator) = 0;
    virtual ~Component() = default;
};

class TextBox;
class CheckBox;
class Button;

class Mediator {
   public:
    void setTextBox(std::shared_ptr<TextBox> textbox);
    void setCheckBox(std::shared_ptr<CheckBox> checkbox);
    void setButton(std::shared_ptr<Button> button);

    void notify(Component* sender, const std::string& event);

   private:
    std::weak_ptr<TextBox> textbox_;
    std::weak_ptr<CheckBox> checkbox_;
    std::weak_ptr<Button> button_;
};

class TextBox : public Component, public std::enable_shared_from_this<TextBox> {
   public:
    void setMediator(std::shared_ptr<Mediator> mediator) override;
    void input(const std::string& text);
    std::string getText() const;

   private:
    std::weak_ptr<Mediator> mediator_;
    std::string text_;
};

class CheckBox : public Component, public std::enable_shared_from_this<CheckBox> {
   public:
    void setMediator(std::shared_ptr<Mediator> mediator) override;
    void toggle();
    bool isChecked() const;

   private:
    std::weak_ptr<Mediator> mediator_;
    bool checked_{false};
};

class Button : public Component, public std::enable_shared_from_this<Button> {
   public:
    void setMediator(std::shared_ptr<Mediator> mediator) override;
    void click();
    void setEnabled(bool enabled);
    bool isEnabled() const;

   private:
    std::weak_ptr<Mediator> mediator_;
    bool enabled_{false};
};

#endif  // MEDIATOR_HPP
