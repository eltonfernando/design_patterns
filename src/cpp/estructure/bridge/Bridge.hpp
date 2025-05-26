#pragma once
#include <memory>
class IJanela {
   public:
    virtual void desenhar() = 0;
    virtual ~IJanela() = default;
};

class JanelaWindows : public IJanela {
   public:
    void desenhar() override;
};

class JanelaLinux : public IJanela {
   public:
    void desenhar() override;
};

class Janela {
   private:
    std::unique_ptr<IJanela> janela_;

   public:
    Janela(std::unique_ptr<IJanela> janela);
    void desenhar() const;
};
