# Class Responsibilities

| Class | What it knows | What it does | Must NOT do |
|---|---|---|---|
| Movie | title, language, duration | exposes movie information | book seats or process payment |
| Seat | number, type | exposes seat information | track show-specific booking status |
| Screen | screen number, seats | owns physical seats | process bookings |
| Cinema | name, screens | owns screens | calculate prices |
| Show | movie, screen, time, ShowSeats | finds/displays show seats | process payment |
| ShowSeat | Seat + status | hold, confirm, release seat | calculate entire booking total |
| Customer | name, phone | exposes customer information | change seat state |
| Booking | booking ID, customer, show, seats, amount, status | confirm/cancel booking state | print ticket or process payment |
| Payment | payment contract | defines `pay(amount)` | know booking internals |
| UpiPayment | UPI payment behavior | performs UPI payment | print ticket |
| CardPayment | Card payment behavior | performs card payment | price seats |
| CashPayment | Cash payment behavior | performs cash payment | own bookings |
| PriceCalculator | seat prices | calculates total | modify seat state |
| TicketPrinter | ticket format | prints booking information | confirm booking |
| BookingService | booking workflow | orchestrates validation, payment, confirmation, cancellation | contain UI/menu logic |
