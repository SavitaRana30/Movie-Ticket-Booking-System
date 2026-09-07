#include <iostream>
#include <iomanip>
using namespace std;

class TicketPrinter {
public:
    void print(const Booking& booking, const Payment& payment) const {
        cout << "\n========================================\n";
        cout << "                 TICKET\n";
        cout << "========================================\n";
        cout << "Booking ID : " << booking.getBookingId() << "\n";
        cout << "Customer   : " << booking.getCustomer().getName() << "\n";
        cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << "\n";
        cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << "\n";
        cout << "Time       : " << booking.getShow()->getStartTime() << "\n";
        cout << "Seats      : ";
        for (const ShowSeat* seat : booking.getBookedSeats()) {
            cout << seat->getSeatNumber() << " ";
        }
        cout << "\nTotal      : Rs. " << fixed << setprecision(2)
             << booking.getBookingAmount() << "\n";
        cout << "Payment    : " << payment.getMethodName() << "\n";
        cout << "Status     : CONFIRMED\n";
        cout << "========================================\n\n";
    }
};
