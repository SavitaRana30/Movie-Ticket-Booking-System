#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats; // OOP: Composition - Screen owns Seat objects

public:
    Screen() : screenNumber(0) {}

    Screen(int screenNumber) {
        this->screenNumber = screenNumber;
    }

    int getScreenNumber() const { return screenNumber; }

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    const vector<Seat>& getSeats() const {
        return seats;
    }
};
