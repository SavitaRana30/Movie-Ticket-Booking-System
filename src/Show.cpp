#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Show {
private:
    int showId;
    Movie* movie;          // OOP: Aggregation - existing Movie
    Screen* screen;        // Aggregation - existing Screen
    string startTime;
    vector<ShowSeat> showSeats; // OOP: Composition - Show owns ShowSeats

public:
    Show(int showId, Movie* movie, Screen* screen, string startTime) {
        this->showId = showId;
        this->movie = movie;
        this->screen = screen;
        this->startTime = startTime;

        for (const Seat& seat : screen->getSeats()) {
            showSeats.emplace_back(seat);
        }
    }

    int getShowId() const { return showId; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }

    vector<ShowSeat>& getShowSeats() { return showSeats; }
    const vector<ShowSeat>& getShowSeats() const { return showSeats; }

    ShowSeat* findShowSeat(int seatNumber) {
        for (ShowSeat& showSeat : showSeats) {
            if (showSeat.getSeatNumber() == seatNumber) return &showSeat;
        }
        return nullptr;
    }

    void displaySeatLayout() const {
        cout << "\nSeat Layout (A=AVAILABLE, B=BOOKED, H=HELD)\n";
        cout << "-------------------------------------------\n";
        string currentType = "";
        for (const ShowSeat& s : showSeats) {
            if (s.getSeatTypeName() != currentType) {
                currentType = s.getSeatTypeName();
                cout << "\n" << currentType << ": ";
            }
            char mark = s.getStatus() == SeatStatus::AVAILABLE ? 'A'
                      : (s.getStatus() == SeatStatus::BOOKED ? 'B' : 'H');
            cout << "[" << s.getSeatNumber() << ":" << mark << "] ";
        }
        cout << "\n\n";
    }
};
