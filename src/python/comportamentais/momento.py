# -*- coding: utf-8 -*-
from copy import deepcopy

# Memento: guarda o estado
class FormState:
    def __init__(self, data):
        self._data = deepcopy(data)

    def get_state(self):
        return self._data


# Originator: o formulário
class Formulario:
    def __init__(self):
        self._data = {"nome": "", "email": "", "idade": ""}

    def preencher(self, nome=None, email=None, idade=None):
        if nome:
            self._data["nome"] = nome
        if email:
            self._data["email"] = email
        if idade:
            self._data["idade"] = idade

    def salvar_estado(self):
        return FormState(self._data)

    def restaurar_estado(self, memento):
        self._data = memento.get_state()

    def mostrar(self):
        print(self._data)


# Caretaker: controla os mementos (ex: botão "Desfazer")
class Historico:
    def __init__(self):
        self._estados = []

    def salvar(self, memento):
        self._estados.append(memento)

    def desfazer(self):
        if self._estados:
            return self._estados.pop()
        return None


# Exemplo de uso
form = Formulario()
historico = Historico()

# Primeiro preenchimento
form.preencher(nome="Maria", email="maria@example.com")
historico.salvar(form.salvar_estado())
form.mostrar()

# Segunda edição
form.preencher(email="nova_maria@example.com")
historico.salvar(form.salvar_estado())
form.mostrar()

# Terceira edição
form.preencher(idade="30")
form.mostrar()

# Desfazer
form.restaurar_estado(historico.desfazer())
form.mostrar()

form.restaurar_estado(historico.desfazer())
form.mostrar()
