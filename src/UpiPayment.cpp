#include <iostream>
using namespace std;

class UpiPayment : public Payment { // OOP: Inheritance
private:
    bool simulateSuccess;

public:
    UpiPayment(bool simulateSuccess = true) {
        this->simulateSuccess = simulateSuccess;
    }

    bool pay(double amount) override { // OOP: Runtime polymorphism
        cout << "Processing UPI payment of Rs. " << amount << "...\n";
        return simulateSuccess;
    }

    const char* getMethodName() const override { return "UPI"; }
};
