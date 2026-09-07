#include <string>
using namespace std;

enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
private:
    int number;
    SeatType type;

public:
    Seat() : number(0), type(SeatType::SILVER) {}

    Seat(int number, SeatType type) {
        this->number = number;
        this->type = type;
    }

    int getNumber() const { return number; }
    SeatType getType() const { return type; }

    string getTypeName() const {
        if (type == SeatType::SILVER) return "SILVER";
        if (type == SeatType::GOLD) return "GOLD";
        return "PLATINUM";
    }
};
