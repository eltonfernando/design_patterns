
#pragma once
#include <string>
#include <vector>

class GUIContext {
   public:
    void add_component(const std::string& component_type, const std::string& label);
    void render() const;

   private:
    std::vector<std::pair<std::string, std::string>> components_;
};

class Expression {
   public:
    virtual ~Expression() = default;
    virtual void interpret(GUIContext& context) const = 0;
};

class ButtonExpression : public Expression {
   public:
    explicit ButtonExpression(const std::string& label);
    void interpret(GUIContext& context) const override;

   private:
    std::string label_;
};

class TextBoxExpression : public Expression {
   public:
    explicit TextBoxExpression(const std::string& label);
    void interpret(GUIContext& context) const override;

   private:
    std::string label_;
};
