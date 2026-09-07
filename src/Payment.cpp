class Payment {
public:
    virtual bool pay(double amount) = 0; // OOP: Abstraction
    virtual const char* getMethodName() const = 0;
    virtual ~Payment() = default;
};
