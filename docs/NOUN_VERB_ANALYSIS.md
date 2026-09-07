# Noun–Verb Analysis

## Nouns found

Movie, cinema, screen, show, seat, seat layout, customer, booking, payment, ticket.

## Verbs found

List, choose, display, book, reject, calculate, pay, print, cancel, release.

## Noun analysis table

| Noun | Keep as class? | Reason |
|---|---:|---|
| Movie | Yes | Has independent data and identity. |
| Seat | Yes | Has a seat number and seat type. |
| Screen | Yes | Represents one auditorium and owns physical seats. |
| Cinema | Yes | Represents the theatre and owns screens. |
| Show | Yes | Represents one Movie on one Screen at one start time. |
| ShowSeat | Yes | Stores one seat's state for one show. |
| Customer | Yes | Stores customer name and phone. |
| Booking | Yes | Stores booking identity, show, seats, amount, and status. |
| Payment | Yes | Represents a payment contract and supports polymorphism. |
| Seat layout | No | It is a view of a Show's ShowSeats, not an independent object. |
| Ticket | No | Printing/formatting is behavior delegated to `TicketPrinter`. |
