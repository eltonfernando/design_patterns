#include <string>
#include <memory>
#include <iostream>
class Imagem {
public:
    virtual void exibir() = 0;
    virtual~Imagem() = default;
};

class ImagemReal : public Imagem {
public:
    ImagemReal(const std::string& nome);    
    void exibir() override;
private:
    std::string nome_;
};

class ImagemProxy : public Imagem {
public:
    ImagemProxy(const std::string& nome);
    void exibir() override;
private:
    std::string nome_;
    std::unique_ptr<Imagem> imagem_;
};