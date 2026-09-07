#include <vector>
using namespace std;

class PriceCalculator {
public:
    static constexpr double SILVER_PRICE = 150.0;
    static constexpr double GOLD_PRICE = 250.0;
    static constexpr double PLATINUM_PRICE = 400.0;

    double priceForSeat(const ShowSeat& seat) const {
        if (seat.getSeatType() == SeatType::SILVER) return SILVER_PRICE;
        if (seat.getSeatType() == SeatType::GOLD) return GOLD_PRICE;
        return PLATINUM_PRICE;
    }

    double calculateTotal(const vector<ShowSeat*>& seats) const {
        double total = 0;
        for (const ShowSeat* seat : seats) {
            total += priceForSeat(*seat);
        }
        return total;
    }

    // OOP: Compile-time polymorphism (method overloading)
    double calculateTotal(const ShowSeat& seat) const {
        return priceForSeat(seat);
    }
};
