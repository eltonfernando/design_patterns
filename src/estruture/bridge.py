# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod

# Implementação
class JanelaImplementada(ABC):
    @abstractmethod
    def desenhar_janela(self, titulo):
        pass


class JanelaWindows(JanelaImplementada):
    def desenhar_janela(self, titulo):
        print(f"Desenhando janela no Windows: {titulo}")


class JanelaLinux(JanelaImplementada):
    def desenhar_janela(self, titulo):
        print(f"Desenhando janela no Linux: {titulo}")


# Abstração
class Janela:
    def __init__(self, implementacao: JanelaImplementada):
        self.implementacao = implementacao

    def desenhar(self, titulo):
        self.implementacao.desenhar_janela(titulo)


# Cliente
win = Janela(JanelaWindows())
win.desenhar("Configurações")

linux = JanelaLinux()
linux.desenhar("Preferências")
