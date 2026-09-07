# Movie Ticket Booking System

A menu-driven **C++ console application** for a single cinema, created for **System Design (TCS-504), Assignment 1**.

##  Project Scope

The project implements exactly the required core features:

- List movies currently playing
- List shows for a chosen movie
- Display seat layout with AVAILABLE / BOOKED status
- Book one or more seats and reject unavailable seats
- Seat pricing: SILVER ₹150, GOLD ₹250, PLATINUM ₹400
- Payment through UPI, Card or Cash
- Failed payment does **not** confirm booking and releases held seats
- Print a ticket
- Cancel a booking and make seats available again

## Repository structure

```text
TCS504-Movie-Ticket-Booking-System/
├── src/
│   ├── Movie.cpp
│   ├── Seat.cpp
│   ├── Screen.cpp
│   ├── Cinema.cpp
│   ├── ShowSeat.cpp
│   ├── Show.cpp
│   ├── Customer.cpp
│   ├── Booking.cpp
│   ├── Payment.cpp
│   ├── UpiPayment.cpp
│   ├── CardPayment.cpp
│   ├── CashPayment.cpp
│   ├── PriceCalculator.cpp
│   ├── TicketPrinter.cpp
│   ├── BookingService.cpp
│   └── main.cpp
├── docs/
│   ├── REQUIREMENTS.md
│   ├── NOUN_VERB_ANALYSIS.md
│   ├── CLASS_RESPONSIBILITIES.md
│   ├── RELATIONSHIPS.md
│   ├── class-diagram.mmd
│   ├── sequence-diagram.mmd
│   ├── SOLID.md
│   └── DEMO_OUTPUT.md
├── .gitignore
├── LICENSE
└── README.md
```

## Important course-rule note

The project requires **one class per file and no header files**.

Normally, a C++ project would use `.h/.hpp` files. To obey the course rule while keeping the repository compilable, `src/main.cpp` includes the class `.cpp` files in dependency order.

**Compile only `src/main.cpp`.** Do not compile all `.cpp` files separately.

## Build on macOS / Linux

```bash
g++ -std=c++17 src/main.cpp -o movie_booking
./movie_booking
```

## Build on Windows with MinGW

```bash
g++ -std=c++17 src/main.cpp -o movie_booking.exe
movie_booking.exe
```

## OOP concepts demonstrated

- Encapsulation — private `seatStatus` and `bookingAmount`
- Abstraction — abstract `Payment`
- Inheritance — `UpiPayment`, `CardPayment`, `CashPayment`
- Runtime polymorphism — `Payment&` invokes different `pay()` implementations
- Compile-time polymorphism — overloaded `calculateTotal()`
- Static member — unique booking IDs
- `this` keyword — constructors
- Composition — Cinema→Screen, Screen→Seat, Show→ShowSeat
- Aggregation — Show→Movie, Booking→ShowSeat
- Association — service interactions

## Edge cases demonstrated

1. Already-booked seat → rejected
2. Failed payment → booking not confirmed; seats released
3. Cancellation → seats available again
4. Invalid menu/seat/show input → clear message; no crash

## UML diagrams

Mermaid sources are in `docs/`.

GitHub can render Mermaid diagrams directly when pasted into Markdown fenced blocks using `mermaid`.

