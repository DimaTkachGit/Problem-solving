#include <stdio.h>
#include <ctype.h>  // For toupper()
#include <string.h>
#include <stdlib.h>

int isDigitsOnly(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to show price list
void viewTicketPrices() {
    printf("\n=== Ticket Prices ===\n");
    printf("Action  - Regular: £10 | Premium: £15\n");
    printf("Comedy  - Regular: £8  | Premium: £12\n");
    printf("Drama   - Regular: £7  | Premium: £10\n");
    printf("Snacks: £5 per ticket (optional)\n");
    printf("Bulk Discount: 10%% off if more than 5 tickets are booked\n");
}

int main() {
    int choice;
    char movieType, ticketCategory, snacksChoice;
    int ticketPrice, numberOfTickets;
    float totalCost, discount, snacksCost, finalCost;

    int validInput = 0;
    do {
        printf("\n===== Movie Ticket Booking Menu =====\n");
        printf("1. Book Tickets\n");
        printf("2. View Ticket Prices\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        // scanf("%d", &choice);
        if (scanf("%d", &choice) == 1) {
            validInput = 1;
        } else {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the buffer
        }

        
        switch (choice) {
            case 1: // Book Tickets
                // Movie Type Input & Validation
                do {
                    printf("Enter Movie Type (A - Action, C - Comedy, D - Drama): ");
                    scanf(" %c", &movieType);
                    movieType = toupper(movieType);
                } while (movieType != 'A' && movieType != 'C' && movieType != 'D');

                // Ticket Category Input & Validation
                do {
                    printf("Enter Ticket Category (R - Regular, P - Premium): ");
                    scanf(" %c", &ticketCategory);
                    ticketCategory = toupper(ticketCategory);
                } while (ticketCategory != 'R' && ticketCategory != 'P');

                // Number of Tickets Input & Validation
                do {
                    printf("Enter Number of Tickets (must be > 0): ");
                    scanf("%d", &numberOfTickets);
                } while (numberOfTickets <= 0);

                // Snacks Choice
                printf("Would you like snacks? (Y/N): ");
                scanf(" %c", &snacksChoice);
                snacksChoice = toupper(snacksChoice);

                // Ticket Price Determination
                switch (movieType) {
                    case 'A':
                        ticketPrice = (ticketCategory == 'R') ? 10 : 15;
                        break;
                    case 'C':
                        ticketPrice = (ticketCategory == 'R') ? 8 : 12;
                        break;
                    case 'D':
                        ticketPrice = (ticketCategory == 'R') ? 7 : 10;
                        break;
                }

                // Cost Calculations
                totalCost = ticketPrice * numberOfTickets;
                discount = (numberOfTickets > 5) ? totalCost * 0.10 : 0;
                snacksCost = (snacksChoice == 'Y') ? 5.0 * numberOfTickets : 0;
                finalCost = totalCost - discount + snacksCost;

                // Booking Summary
                printf("\n===== Booking Summary =====\n");

                printf("Movie Type: ");
                switch (movieType) {
                    case 'A': printf("Action\n"); break;
                    case 'C': printf("Comedy\n"); break;
                    case 'D': printf("Drama\n"); break;
                }

                printf("Ticket Category: %s\n", ticketCategory == 'R' ? "Regular" : "Premium");
                printf("Number of Tickets: %d\n", numberOfTickets);
                printf("Price per Ticket: £%d\n", ticketPrice);
                printf("Total Cost Before Discount: £%.2f\n", totalCost);
                printf("Bulk Discount: -£%.2f\n", discount);
                printf("Snacks Cost: +£%.2f\n", snacksCost);
                printf("Final Total Cost: £%.2f\n", finalCost);
                break;

            case 2: // View Ticket Prices
                viewTicketPrices();
                break;

            case 3: // Exit
                printf("Thank you for using the Movie Ticket Booking System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}