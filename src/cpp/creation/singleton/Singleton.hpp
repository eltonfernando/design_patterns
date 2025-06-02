class Singleton{
    public:
        static Singleton& getInstance();
        void execute();
    private:
        Singleton();
        ~Singleton();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};  