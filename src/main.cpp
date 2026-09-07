#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <memory>
using namespace std;

// Course rule: one class per file, no header files.
// To keep the project compilable under that rule, class .cpp files are
// included here in dependency order. Compile ONLY src/main.cpp.
#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout << "Invalid input. Please enter a number.\n";
        clearBadInput();
    }
}

void listMovies(const vector<Movie>& movies) {
    cout << "\nMovies currently playing:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].getTitle()
             << " (" << movies[i].getLanguage()
             << ", " << movies[i].getDurationMinutes() << " min)\n";
    }
}

void listShowsForMovie(const vector<Show*>& shows, const Movie* movie) {
    cout << "\nShows for " << movie->getTitle() << ":\n";
    bool found = false;
    for (const Show* show : shows) {
        if (show->getMovie() == movie) {
            found = true;
            cout << "Show ID " << show->getShowId()
                 << " | Screen " << show->getScreen()->getScreenNumber()
                 << " | " << show->getStartTime() << "\n";
        }
    }
    if (!found) cout << "No shows found.\n";
}

Show* findShow(vector<Show*>& shows, int showId) {
    for (Show* show : shows) {
        if (show->getShowId() == showId) return show;
    }
    return nullptr;
}

int main() {
    Cinema cinema("Campus Cinema");

    Screen screen1(1);
    for (int i = 1; i <= 5; ++i) screen1.addSeat(Seat(i, SeatType::SILVER));
    for (int i = 6; i <= 10; ++i) screen1.addSeat(Seat(i, SeatType::GOLD));
    for (int i = 11; i <= 15; ++i) screen1.addSeat(Seat(i, SeatType::PLATINUM));
    cinema.addScreen(screen1);

    Screen screen2(2);
    for (int i = 1; i <= 4; ++i) screen2.addSeat(Seat(i, SeatType::SILVER));
    for (int i = 5; i <= 8; ++i) screen2.addSeat(Seat(i, SeatType::GOLD));
    for (int i = 9; i <= 12; ++i) screen2.addSeat(Seat(i, SeatType::PLATINUM));
    cinema.addScreen(screen2);

    vector<Movie> movies = {
        Movie("Interstellar", "English", 169),
        Movie("Dangal", "Hindi", 161),
        Movie("3 Idiots", "Hindi", 170)
    };

    vector<Show> showStorage;
    showStorage.emplace_back(101, &movies[0], &cinema.getScreens()[0], "10:00 AM");
    showStorage.emplace_back(102, &movies[0], &cinema.getScreens()[1], "06:00 PM");
    showStorage.emplace_back(201, &movies[1], &cinema.getScreens()[0], "02:00 PM");
    showStorage.emplace_back(301, &movies[2], &cinema.getScreens()[1], "09:00 PM");

    vector<Show*> shows;
    for (Show& show : showStorage) shows.push_back(&show);

    BookingService bookingService;

    while (true) {
        cout << "\n========================================\n";
        cout << "      MOVIE TICKET BOOKING SYSTEM\n";
        cout << "========================================\n";
        cout << "1. List Movies\n";
        cout << "2. View Shows for Movie\n";
        cout << "3. View Seats for Show\n";
        cout << "4. Book Ticket\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Exit\n";

        int choice = readInt("Enter your choice: ");

        if (choice == 1) {
            listMovies(movies);
        } else if (choice == 2) {
            listMovies(movies);
            int movieChoice = readInt("Choose movie number: ");
            if (movieChoice < 1 || movieChoice > (int)movies.size()) {
                cout << "Invalid movie choice.\n";
                continue;
            }
            listShowsForMovie(shows, &movies[movieChoice - 1]);
        } else if (choice == 3) {
            int showId = readInt("Enter show ID: ");
            Show* show = findShow(shows, showId);
            if (!show) {
                cout << "Invalid show ID.\n";
                continue;
            }
            show->displaySeatLayout();
        } else if (choice == 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string name, phone;
            cout << "Customer name: ";
            getline(cin, name);
            cout << "Phone: ";
            getline(cin, phone);

            int showId = readInt("Enter show ID: ");
            Show* show = findShow(shows, showId);
            if (!show) {
                cout << "Invalid show ID.\n";
                continue;
            }

            show->displaySeatLayout();
            int count = readInt("How many seats? ");
            if (count <= 0 || count > 10) {
                cout << "Invalid seat count.\n";
                continue;
            }

            vector<int> seatNumbers;
            for (int i = 0; i < count; ++i) {
                seatNumbers.push_back(readInt("Enter seat number: "));
            }

            cout << "\nPayment methods:\n1. UPI\n2. Card\n3. Cash\n4. Simulate failed UPI\n";
            int paymentChoice = readInt("Choose payment method: ");

            unique_ptr<Payment> payment;
            if (paymentChoice == 1) payment = make_unique<UpiPayment>(true);
            else if (paymentChoice == 2) payment = make_unique<CardPayment>(true);
            else if (paymentChoice == 3) payment = make_unique<CashPayment>();
            else if (paymentChoice == 4) payment = make_unique<UpiPayment>(false);
            else {
                cout << "Invalid payment choice.\n";
                continue;
            }

            Customer customer(name, phone);
            bookingService.bookTickets(customer, *show, seatNumbers, *payment);

        } else if (choice == 5) {
            int id = readInt("Enter booking ID: ");
            bookingService.cancelBooking(id);
        } else if (choice == 6) {
            cout << "Thank you for using the system.\n";
            break;
        } else {
            cout << "Invalid menu choice. Please try again.\n";
        }
    }

    return 0;
}
