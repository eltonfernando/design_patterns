# -*- coding: utf-8 -*-
"""

"""


class Command:
    def execute(self):
        pass

    def undo(self):
        pass


# Receptor
class Editor:
    def __init__(self):
        self.text = ""

    def copy(self):
        print("Copiar (simulado)")

    def paste(self, content):
        self.text += content
        print(f"Texto após colar: {self.text}")

    def remove(self, length):
        self.text = self.text[:-length]
        print(f"Texto após undo: {self.text}")


# Comando concreto com undo
class PasteCommand(Command):
    def __init__(self, editor, content):
        self.editor = editor
        self.content = content

    def execute(self):
        self.editor.paste(self.content)

    def undo(self):
        self.editor.remove(len(self.content))


# Invoker com pilha de undo
class Button:
    def __init__(self):
        self.history = []

    def click(self, command):
        command.execute()
        self.history.append(command)

    def undo(self):
        if self.history:
            cmd = self.history.pop()
            cmd.undo()


# Uso
editor = Editor()
button = Button()

cmd1 = PasteCommand(editor, "Olá ")
cmd2 = PasteCommand(editor, "mundo!")

button.click(cmd1)
button.click(cmd2)
button.undo()  # Remove "mundo!"
button.undo()  # Remove "Olá "
