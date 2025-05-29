#include "Facade.hpp"

#include <iostream>
#include <memory>
void ConfiguracaSistema::configurar() {
    std::cout << "Configurando o sistema" << std::endl;
}
void ServicoBancoDados::conectar() {
    std::cout << "Conectando ao banco de dados" << std::endl;
}
void ServicoBancoDados::desconectar() {
    std::cout << "Desconectando do banco de dados" << std::endl;
}
void JanelaPrincial::exibir() {
    std::cout << "Exibindo a janela principal" << std::endl;
}
void JanelaPrincial::ocultar() {
    std::cout << "Ocultando a janela principal" << std::endl;
}

void Facade::inicializar() {
    configuracao.configurar();
    bancoDados.conectar();
    janelaPrincipal.exibir();
}

void Facade::finalizar() {
    janelaPrincipal.ocultar();
    bancoDados.desconectar();
}
