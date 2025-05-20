# -*- coding: utf-8 -*-
# sempre que você quer evitar dependência direta entre objetos que colaboram
from typing import Optional


class Mediator:
    def __init__(self):
        self.textbox: Optional[TextBox] = None
        self.checkbox: Optional[CheckBox] = None
        self.button: Optional[Button] = None

    def notify(self, sender: object, event: str) -> None:
        if event in ("text_changed", "checkbox_toggled"):
            if self.textbox and self.checkbox and self.button:
                self.button.enabled = bool(self.textbox.text and self.checkbox.checked)

        elif event == "button_clicked":
            if self.textbox and self.checkbox:
                if self.textbox.text and self.checkbox.checked:
                    print("Enviado com sucesso!")
                else:
                    print("Não é possível enviar. Preencha todos os campos.")


class TextBox:
    def __init__(self, mediator: Mediator):
        self.mediator = mediator
        self.text: str = ""

    def input(self, text: str) -> None:
        self.text = text
        self.mediator.notify(self, "text_changed")


class CheckBox:
    def __init__(self, mediator: Mediator):
        self.mediator = mediator
        self.checked: bool = False

    def toggle(self) -> None:
        self.checked = not self.checked
        self.mediator.notify(self, "checkbox_toggled")


class Button:
    def __init__(self, mediator: Mediator):
        self.mediator = mediator
        self.enabled: bool = False

    def click(self) -> None:
        self.mediator.notify(self, "button_clicked")


# Uso
mediator = Mediator()
textbox = TextBox(mediator)
checkbox = CheckBox(mediator)
button = Button(mediator)

mediator.textbox = textbox
mediator.checkbox = checkbox
mediator.button = button

# Simulação
textbox.input("Olá mundo")
checkbox.toggle()
button.click()  # Enviado com sucesso!
