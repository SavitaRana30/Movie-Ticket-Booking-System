# Relationship Table

| Pair | Relationship | Lifetime-test justification |
|---|---|---|
| Cinema — Screen | Composition | Screens are owned by the cinema in this design; destroying the cinema destroys its stored screens. |
| Screen — Seat | Composition | Physical seats are owned by a Screen; destroying the Screen destroys those Seat objects. |
| Show — Movie | Aggregation | A Show refers to an existing Movie; the Movie can exist before/after that Show. |
| Show — Screen | Aggregation | A Show refers to an existing Screen; the Screen exists independently of the Show. |
| Show — ShowSeat | Composition | ShowSeats represent seat state specifically for one Show and die with that Show. |
| Booking — Customer | Association | A booking refers to customer information, but Customer is conceptually independent. |
| Booking — ShowSeat | Aggregation | Booking references existing ShowSeats owned by the Show. |
| Booking — Payment | Association | Payment is used in the booking flow but is not owned as part of Booking state. |
| Payment — UpiPayment | Inheritance | UpiPayment is a specialized Payment and fulfills the same payment contract. |
| Payment — CardPayment | Inheritance | CardPayment is a specialized Payment. |
| Payment — CashPayment | Inheritance | CashPayment is a specialized Payment. |
| BookingService — Booking | Association | BookingService creates and manages bookings as part of the workflow. |
