#include <vector>
using namespace std;

enum class BookingStatus { PENDING, CONFIRMED, CANCELLED };

class Booking {
private:
    static int nextBookingId; // OOP: Static member
    int bookingId;
    Customer customer;
    Show* show;
    vector<ShowSeat*> bookedSeats; // OOP: Aggregation
    double bookingAmount;          // OOP: Encapsulation
    BookingStatus status;

public:
    Booking(Customer customer, Show* show, const vector<ShowSeat*>& seats, double amount)
        : customer(customer), show(show), bookedSeats(seats), bookingAmount(amount),
          status(BookingStatus::PENDING) {
        bookingId = nextBookingId++;
    }

    int getBookingId() const { return bookingId; }
    const Customer& getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getBookedSeats() const { return bookedSeats; }
    double getBookingAmount() const { return bookingAmount; }
    BookingStatus getStatus() const { return status; }

    void confirm() { status = BookingStatus::CONFIRMED; }
    void cancel() { status = BookingStatus::CANCELLED; }
};

int Booking::nextBookingId = 1001;
