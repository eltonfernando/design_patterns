# -*- coding: utf-8 -*-
# Subsistemas complexos
class ConfiguracaoSistema:
    def carregar_configuracoes(self):
        print("Carregando configurações do sistema...")


class ServicoBancoDeDados:
    def conectar(self):
        print("Conectando ao banco de dados...")


class VerificadorAtualizacao:
    def verificar(self):
        print("Verificando atualizações do sistema...")


class TelaPrincipal:
    def exibir(self):
        print("Exibindo a interface principal do sistema.")


# Façade que unifica tudo
class AppLauncher:
    def __init__(self):
        self.config = ConfiguracaoSistema()
        self.banco = ServicoBancoDeDados()
        self.verificador = VerificadorAtualizacao()
        self.tela = TelaPrincipal()

    def iniciar_app(self):
        self.config.carregar_configuracoes()
        self.banco.conectar()
        self.verificador.verificar()
        self.tela.exibir()


# Simulação da GUI chamando apenas o façade
if __name__ == "__main__":
    print("Iniciando o sistema via GUI...\n")
    sistema = AppLauncher()
    sistema.iniciar_app()
