class Singleton {
   public:
    static Singleton& getInstance();
    void execute();

   private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&) = delete; // Bloqueia contrutor copias Singleton s2 = s1;
    Singleton& operator=(const Singleton&) = delete; // Bloqueia operador de copia s2=s1;
    Singleton(Singleton&&) = delete; // Bloqueia o Construtor de Movimentação Singleton s = std::move(Singleton::getInstance());
    Singleton& operator=(Singleton&&) = delete; //Bloqueia o Operador de Atribuição por Movimentação  s = std::move(Singleton::getInstance()).
};
