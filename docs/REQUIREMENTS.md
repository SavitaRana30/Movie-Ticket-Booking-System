# Requirement Analysis

## Functional Requirements

| ID | Requirement |
|---|---|
| FR1 | The system shall allow the customer to view all movies currently playing in the cinema. |
| FR2 | The system shall allow the customer to select a movie and view its shows, including screen number and start time. |
| FR3 | The system shall display the seat layout of a selected show with AVAILABLE and BOOKED status. |
| FR4 | The system shall allow one or more available seats to be booked and reject an already-booked seat. |
| FR5 | The system shall calculate the booking amount according to seat type: SILVER ₹150, GOLD ₹250, PLATINUM ₹400. |
| FR6 | The system shall allow UPI, Card, or Cash payment. A failed payment shall not confirm the booking. |
| FR7 | The system shall print a ticket containing booking ID, movie, screen, time, seat numbers, and total amount. |
| FR8 | The system shall allow cancellation of a booking and make its seats AVAILABLE again. |

## Non-Functional Requirements

**NFR1 — Modularity:** Each class has one clear responsibility and is stored in its own source file.

**NFR2 — Extensibility:** New payment methods can be added by deriving from `Payment` without modifying existing payment classes.

**NFR3 — Reliability:** Invalid input, invalid seats, unavailable seats, and failed payments are handled without crashing the program.

**NFR4 — Maintainability:** The code uses meaningful names, constants instead of magic prices, small functions, and separation of responsibilities.
