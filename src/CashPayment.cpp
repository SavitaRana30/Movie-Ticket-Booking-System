#include <iostream>
using namespace std;

class CashPayment : public Payment { // OOP: Inheritance
public:
    bool pay(double amount) override {
        cout << "Cash received: Rs. " << amount << "\n";
        return true;
    }

    const char* getMethodName() const override { return "CASH"; }
};
