# -*- coding: utf-8 -*-


class ButtonClickStrategy:
    def execute(self) -> None:
        ...


class SaveStrategy(ButtonClickStrategy):
    def execute(self) -> None:
        print("Salvando dados...")


class DeleteStrategy(ButtonClickStrategy):
    def execute(self) -> None:
        print("Deletando item...")


class CancelStrategy(ButtonClickStrategy):
    def execute(self) -> None:
        print("Cancelando operação...")


class Button:
    def __init__(self, label: str, strategy: ButtonClickStrategy) -> None:
        self.label = label
        self._strategy = strategy

    def set_strategy(self, strategy: ButtonClickStrategy) -> None:
        self._strategy = strategy

    def click(self) -> None:
        print(f"Botão '{self.label}' clicado.")
        self._strategy.execute()


# Exemplo de uso
if __name__ == "__main__":
    btn = Button("Ação", SaveStrategy())
    btn.click()

    btn.set_strategy(DeleteStrategy())
    btn.click()

    btn.set_strategy(CancelStrategy())
    btn.click()
