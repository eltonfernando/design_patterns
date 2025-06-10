#include "Proxy.hpp"

ImagemReal::ImagemReal(const std::string& nome) : nome_(nome) {
    std::cout << "Criando imagem real" << std::endl;
}

void ImagemReal::exibir() {
    std::cout << "Exibindo imagem real" << std::endl;
}

ImagemProxy::ImagemProxy(const std::string& nome) : nome_(nome) {}

void ImagemProxy::exibir() {
    if (!imagem_) {
        imagem_ = std::make_unique<ImagemReal>(nome_);
    }
    imagem_->exibir();
}
