#include <string>
using namespace std;

enum class SeatStatus { AVAILABLE, BOOKED, HELD };

class ShowSeat {
private:
    Seat seat;
    SeatStatus seatStatus; // OOP: Encapsulation

public:
    ShowSeat(const Seat& seat) : seat(seat), seatStatus(SeatStatus::AVAILABLE) {}

    int getSeatNumber() const { return seat.getNumber(); }
    SeatType getSeatType() const { return seat.getType(); }
    string getSeatTypeName() const { return seat.getTypeName(); }
    SeatStatus getStatus() const { return seatStatus; }

    string getStatusName() const {
        if (seatStatus == SeatStatus::AVAILABLE) return "AVAILABLE";
        if (seatStatus == SeatStatus::HELD) return "HELD";
        return "BOOKED";
    }

    bool holdSeat() {
        if (seatStatus != SeatStatus::AVAILABLE) return false;
        seatStatus = SeatStatus::HELD;
        return true;
    }

    bool confirmSeat() {
        if (seatStatus != SeatStatus::HELD) return false;
        seatStatus = SeatStatus::BOOKED;
        return true;
    }

    void releaseSeat() {
        seatStatus = SeatStatus::AVAILABLE;
    }
};
