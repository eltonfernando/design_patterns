# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod

# Interface comum
class Imagem(ABC):
    @abstractmethod
    def exibir(self):
        pass


# Objeto real
class ImagemReal(Imagem):
    def __init__(self, arquivo):
        print(f"Carregando imagem {arquivo} do disco...")
        self.arquivo = arquivo

    def exibir(self):
        print(f"Exibindo imagem {self.arquivo}")


# Proxy
class ImagemProxy(Imagem):
    def __init__(self, arquivo):
        self.arquivo = arquivo
        self.imagem_real = None

    def exibir(self):
        if self.imagem_real is None:
            self.imagem_real = ImagemReal(self.arquivo)
        self.imagem_real.exibir()


# Uso
def main():
    img = ImagemProxy("foto_grande.png")
    print("Imagem criada, mas ainda não carregada...")
    # Quando realmente for mostrar:
    img.exibir()


if __name__ == "__main__":
    main()
