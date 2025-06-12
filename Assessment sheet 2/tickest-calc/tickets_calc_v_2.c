#include <stdio.h>

int main() {
    char movieType, ticketCategory, snacksChoice;
    int ticketPrice = 0;
    int numberOfTickets;
    float discount = 0.0, snacksCost = 0.0, totalCost = 0.0, finalCost;

    // Prompt for movie type
    printf("Select Movie Type:\nA - Action\nC - Comedy\nD - Drama\n");
    printf("Enter your choice: ");
    scanf(" %c", &movieType);

    // Prompt for ticket category
    printf("Select Ticket Category:\nR - Regular\nP - Premium\n");
    printf("Enter your choice: ");
    scanf(" %c", &ticketCategory);

    // Prompt for number of tickets
    printf("Enter number of tickets: ");
    scanf("%d", &numberOfTickets);

    // Determine ticket price
    switch (movieType) {
        case 'A': case 'a':
            switch (ticketCategory) {
                case 'R': case 'r': ticketPrice = 10; break;
                case 'P': case 'p': ticketPrice = 15; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        case 'C': case 'c':
            switch (ticketCategory) {
                case 'R': case 'r': ticketPrice = 8; break;
                case 'P': case 'p': ticketPrice = 12; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        case 'D': case 'd':
            switch (ticketCategory) {
                case 'R': case 'r': ticketPrice = 7; break;
                case 'P': case 'p': ticketPrice = 10; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        default:
            printf("Invalid movie type.\n");
            return 1;
    }

    // Ask for snacks
    printf("Would you like snacks? (y/n): ");
    scanf(" %c", &snacksChoice);

    // Calculate base total
    totalCost = ticketPrice * numberOfTickets;

    // Calculate discount
    if (numberOfTickets > 5) {
        discount = totalCost * 0.10; // 10% discount
    }

    // Calculate snacks cost
    if (snacksChoice == 'y' || snacksChoice == 'Y') {
        snacksCost = 5.0 * numberOfTickets;
    }

    // Final total
    finalCost = totalCost - discount + snacksCost;

    // Print summary
    printf("\n===== Ticket Summary =====\n");

    // Movie type
    printf("Movie Type: ");
    switch (movieType) {
        case 'A': case 'a': printf("Action\n"); break;
        case 'C': case 'c': printf("Comedy\n"); break;
        case 'D': case 'd': printf("Drama\n"); break;
    }

    // Ticket category
    printf("Ticket Category: ");
    switch (ticketCategory) {
        case 'R': case 'r': printf("Regular\n"); break;
        case 'P': case 'p': printf("Premium\n"); break;
    }

    printf("Number of Tickets: %d\n", numberOfTickets);
    printf("Price per Ticket: £%d\n", ticketPrice);
    printf("Total Before Discounts/Extras: £%.2f\n", totalCost);
    printf("Bulk Discount: -£%.2f\n", discount);
    printf("Snacks Cost: +£%.2f\n", snacksCost);
    printf("Final Total: £%.2f\n", finalCost);

    return 0;
}