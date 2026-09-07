#include <vector>
#include <memory>
#include <iostream>
using namespace std;

class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    vector<unique_ptr<Booking>> bookings;

    void releaseSeats(const vector<ShowSeat*>& seats) {
        for (ShowSeat* seat : seats) {
            seat->releaseSeat();
        }
    }

public:
    Booking* bookTickets(Customer customer,
                         Show& show,
                         const vector<int>& seatNumbers,
                         Payment& payment) { // SOLID: DIP - depends on Payment abstraction
        vector<ShowSeat*> selectedSeats;

        for (int seatNumber : seatNumbers) {
            ShowSeat* seat = show.findShowSeat(seatNumber);

            if (seat == nullptr) {
                cout << "Invalid seat number: " << seatNumber << "\n";
                releaseSeats(selectedSeats);
                return nullptr;
            }

            if (!seat->holdSeat()) {
                cout << "Seat " << seatNumber
                     << " is already BOOKED or unavailable.\n";
                releaseSeats(selectedSeats);
                return nullptr;
            }

            selectedSeats.push_back(seat);
        }

        double total = priceCalculator.calculateTotal(selectedSeats);

        // «create» Booking
        auto booking = make_unique<Booking>(customer, &show, selectedSeats, total);

        // Runtime polymorphism: actual pay() depends on Payment child object
        bool paid = payment.pay(total);

        if (!paid) {
            cout << "Payment failed. Booking NOT confirmed.\n";
            releaseSeats(selectedSeats);
            return nullptr;
        }

        for (ShowSeat* seat : selectedSeats) {
            seat->confirmSeat();
        }

        booking->confirm();
        Booking* result = booking.get();
        bookings.push_back(move(booking));

        cout << "Payment successful. Booking confirmed!\n";
        ticketPrinter.print(*result, payment);
        return result;
    }

    bool cancelBooking(int bookingId) {
        for (auto& booking : bookings) {
            if (booking->getBookingId() == bookingId &&
                booking->getStatus() == BookingStatus::CONFIRMED) {

                releaseSeats(booking->getBookedSeats());
                booking->cancel();
                cout << "Booking " << bookingId
                     << " cancelled. Seats are AVAILABLE again.\n";
                return true;
            }
        }

        cout << "Active booking not found for ID " << bookingId << ".\n";
        return false;
    }

    const vector<unique_ptr<Booking>>& getBookings() const {
        return bookings;
    }
};
