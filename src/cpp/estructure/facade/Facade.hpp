#pragma once

class ConfiguracaSistema {
   public:
    void configurar();
};

class ServicoBancoDados {
   public:
    void conectar();
    void desconectar();
};

class JanelaPrincial {
   public:
    void exibir();
    void ocultar();
};

class Facade {
   public:
    void inicializar();
    void finalizar();

   private:
    ConfiguracaSistema configuracao;
    ServicoBancoDados bancoDados;
    JanelaPrincial janelaPrincipal;
};
