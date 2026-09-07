#include <iostream>
using namespace std;

class CardPayment : public Payment { // OOP: Inheritance
private:
    bool simulateSuccess;

public:
    CardPayment(bool simulateSuccess = true) {
        this->simulateSuccess = simulateSuccess;
    }

    bool pay(double amount) override {
        cout << "Processing Card payment of Rs. " << amount << "...\n";
        return simulateSuccess;
    }

    const char* getMethodName() const override { return "CARD"; }
};
