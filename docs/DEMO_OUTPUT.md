# Demo Run

Example successful booking:

```text
========================================
      MOVIE TICKET BOOKING SYSTEM
========================================
1. List Movies
2. View Shows for Movie
3. View Seats for Show
4. Book Ticket
5. Cancel Booking
6. Exit
Enter your choice: 4

Customer name: Kailash
Phone: 9999999999
Enter show ID: 101

Seat Layout (A=AVAILABLE, B=BOOKED, H=HELD)
-------------------------------------------

SILVER: [1:A] [2:A] [3:A] [4:A] [5:A]
GOLD: [6:A] [7:A] [8:A] [9:A] [10:A]
PLATINUM: [11:A] [12:A] [13:A] [14:A] [15:A]

How many seats? 1
Enter seat number: 1

Payment methods:
1. UPI
2. Card
3. Cash
4. Simulate failed UPI
Choose payment method: 1

Processing UPI payment of Rs. 150...
Payment successful. Booking confirmed!

========================================
                 TICKET
========================================
Booking ID : 1001
Movie      : Interstellar
Screen     : 1
Time       : 10:00 AM
Seats      : 1
Total      : Rs. 150.00
Payment    : UPI
Status     : CONFIRMED
========================================
```

## Required edge case: already booked seat

Attempting to book the same seat again:

```text
Seat 1 is already BOOKED or unavailable.
```

## Required edge case: failed payment

Choose `4. Simulate failed UPI`:

```text
Processing UPI payment of Rs. 150...
Payment failed. Booking NOT confirmed.
```

The held seat is released and becomes AVAILABLE again.

## Required edge case: cancellation

```text
Enter booking ID: 1001
Booking 1001 cancelled. Seats are AVAILABLE again.
```

## Required edge case: invalid input

```text
Enter seat number: 99
Invalid seat number: 99
```
