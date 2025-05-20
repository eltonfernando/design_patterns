# -*- coding: utf-8 -*-

# Esse padrão é útil quando você quer que múltiplos objetos tenham chance de processar um evento
class GUIComponent:
    def __init__(self, parent=None):
        self.parent = parent

    def handle_click(self, x, y):
        if self.parent:
            return self.parent.handle_click(x, y)
        print("Clique não tratado.")


class Button(GUIComponent):
    def __init__(self, x, y, w, h, parent=None):
        super().__init__(parent)
        self.x, self.y, self.w, self.h = x, y, w, h

    def handle_click(self, x, y):
        if self.x <= x <= self.x + self.w and self.y <= y <= self.y + self.h:
            print("Botão clicado!")
        else:
            super().handle_click(x, y)


class Panel(GUIComponent):
    def handle_click(self, x, y):
        print("Painel recebeu o clique, repassando...")
        super().handle_click(x, y)


class Window(GUIComponent):
    def handle_click(self, x, y):
        print("Janela recebeu o clique, repassando...")
        super().handle_click(x, y)


# Criando a cadeia
janela = Window()
painel = Panel(parent=janela)
botao = Button(10, 10, 100, 30, parent=painel)

# Teste
botao.handle_click(15, 20)  # Dentro do botão
botao.handle_click(200, 200)  # Fora do botão
