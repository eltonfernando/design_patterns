# -*- coding: utf-8 -*-
from typing import Dict, Tuple


class BotaoFlyweight:
    def __init__(self, cor: str, fonte: str) -> None:
        self.cor = cor
        self.fonte = fonte

    def desenhar(self, texto: str, x: int, y: int) -> None:
        print(f"Desenhando botão '{texto}' na posição ({x},{y}) com cor {self.cor} e fonte {self.fonte}.")


class FabricaBotoes:
    _botoes: Dict[Tuple[str, str], BotaoFlyweight] = {}

    @classmethod
    def obter_botao(cls, cor: str, fonte: str) -> BotaoFlyweight:
        chave = (cor, fonte)
        if chave not in cls._botoes:
            cls._botoes[chave] = BotaoFlyweight(cor, fonte)
        return cls._botoes[chave]


# Uso
fabrica = FabricaBotoes()
botao_azul = fabrica.obter_botao("azul", "Arial")
botao_vermelho = fabrica.obter_botao("vermelho", "Arial")

botao_azul.desenhar("OK", 10, 20)
botao_azul.desenhar("Enviar", 30, 50)
botao_vermelho.desenhar("Cancelar", 60, 80)
