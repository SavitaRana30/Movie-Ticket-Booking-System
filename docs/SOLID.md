# SOLID Mapping

## S — Single Responsibility Principle

`Movie`, `Seat`, `PriceCalculator`, `TicketPrinter`, and `BookingService` each have one primary reason to change.

Example: changing ticket layout affects `TicketPrinter`; changing prices affects `PriceCalculator`.

## O — Open/Closed Principle

New payment methods can derive from the abstract `Payment` class. Existing concrete payment classes do not need to change.

Example:

```cpp
class NetBankingPayment : public Payment {
public:
    bool pay(double amount) override { /* ... */ }
};
```

## L — Liskov Substitution Principle

`UpiPayment`, `CardPayment`, and `CashPayment` can all be used through the `Payment` interface.

```cpp
Payment& payment = upiPayment;
payment.pay(total);
```

No special setup method is required by the caller.

## D — Dependency Inversion Principle

`BookingService::bookTickets` receives a `Payment&` abstraction instead of constructing a particular payment method internally.

## Deliberately NOT done

`Booking` does **not** print tickets. Ticket formatting/printing belongs to the separate `TicketPrinter` class. Combining them would give `Booking` more than one responsibility.
