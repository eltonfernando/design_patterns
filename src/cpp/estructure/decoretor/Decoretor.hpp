#include <memory>
class ICafe {
   public:
    virtual double cost() = 0;
    virtual ~ICafe() = default;
};

class CafeSimples : public ICafe {
   public:
    virtual double cost() override;
};

class DecoretorCafe : public ICafe {
   public:
    DecoretorCafe(std::unique_ptr<ICafe> cafe);
    virtual double cost() = 0;

   protected:
    std::unique_ptr<ICafe> _cafe;
};

class Leite : public DecoretorCafe {
   public:
    Leite(std::unique_ptr<ICafe> cafe);
    virtual double cost() override;
};

class Chocolate : public DecoretorCafe {
   public:
    Chocolate(std::unique_ptr<ICafe> cafe);
    virtual double cost() override;
};
