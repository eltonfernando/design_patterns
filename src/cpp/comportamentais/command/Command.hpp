#include <string>
#include <vector>
class Command {
   public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class Editor {
   public:
    void copy();
    void paste(std::string& content);
    void remove(int index);

    std::vector<std::string> text_;
};

class PasteCommand : public Command {
   public:
    PasteCommand(Editor* editor, std::string& content);
    void execute() override;
    void undo() override;

   private:
    Editor* editor_;
    std::string content_;
};

class Button {
   public:
    void click(Command* command);
    void undo();

   private:
    std::vector<Command*> commands_;
};
