#include <stdio.h>
#include <ctype.h>  // for toupper()

int main() {
    char movieType, ticketCategory, snacksChoice;
    int ticketPrice = 0;
    int numberOfTickets;
    float discount = 0.0, snacksCost = 0.0, totalCost = 0.0, finalCost;

    // Prompt for movie type
    printf("Select Movie Type:\nA - Action\nC - Comedy\nD - Drama\n");
    printf("Enter your choice: ");
    scanf(" %c", &movieType);
    movieType = toupper(movieType); // Convert to uppercase

    // Prompt for ticket category
    printf("Select Ticket Category:\nR - Regular\nP - Premium\n");
    printf("Enter your choice: ");
    scanf(" %c", &ticketCategory);
    ticketCategory = toupper(ticketCategory); // Convert to uppercase

    // Prompt for number of tickets
    printf("Enter number of tickets: ");
    scanf("%d", &numberOfTickets);

    // Determine ticket price
    switch (movieType) {
        case 'A':
            switch (ticketCategory) {
                case 'R': ticketPrice = 10; break;
                case 'P': ticketPrice = 15; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        case 'C':
            switch (ticketCategory) {
                case 'R': ticketPrice = 8; break;
                case 'P': ticketPrice = 12; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        case 'D':
            switch (ticketCategory) {
                case 'R': ticketPrice = 7; break;
                case 'P': ticketPrice = 10; break;
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
    snacksChoice = toupper(snacksChoice); // Convert to uppercase

    // Calculate base total
    totalCost = ticketPrice * numberOfTickets;

    // Calculate discount
    if (numberOfTickets > 5) {
        discount = totalCost * 0.10;
    }

    // Calculate snacks cost
    if (snacksChoice == 'Y') {
        snacksCost = 5.0 * numberOfTickets;
    }

    // Final total
    finalCost = totalCost - discount + snacksCost;

    // Print summary
    printf("\n===== Ticket Summary =====\n");

    // Movie type
    printf("Movie Type: ");
    switch (movieType) {
        case 'A': printf("Action\n"); break;
        case 'C': printf("Comedy\n"); break;
        case 'D': printf("Drama\n"); break;
    }

    // Ticket category
    printf("Ticket Category: ");
    switch (ticketCategory) {
        case 'R': printf("Regular\n"); break;
        case 'P': printf("Premium\n"); break;
    }

    printf("Number of Tickets: %d\n", numberOfTickets);
    printf("Price per Ticket: £%d\n", ticketPrice);
    printf("Total Before Discounts/Extras: £%.2f\n", totalCost);
    printf("Bulk Discount: -£%.2f\n", discount);
    printf("Snacks Cost: +£%.2f\n", snacksCost);
    printf("Final Total: £%.2f\n", finalCost);

    return 0;
}