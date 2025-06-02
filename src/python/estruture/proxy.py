# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod
from typing import Optional


class Imagem(ABC):
    @abstractmethod
    def exibir(self) -> None:
        pass


class ImagemReal(Imagem):
    def __init__(self, arquivo: str) -> None:
        print(f"Carregando imagem {arquivo} do disco...")
        self.arquivo = arquivo

    def exibir(self) -> None:
        print(f"Exibindo imagem {self.arquivo}")


class ImagemProxy(Imagem):
    def __init__(self, arquivo: str) -> None:
        self.arquivo = arquivo
        self.imagem_real: Optional[ImagemReal] = None

    def exibir(self) -> None:
        if self.imagem_real is None:
            self.imagem_real = ImagemReal(self.arquivo)
        self.imagem_real.exibir()


def main() -> None:
    img: Imagem = ImagemProxy("foto_grande.png")
    print("Imagem criada, mas ainda não carregada...")
    img.exibir()


if __name__ == "__main__":
    main()

