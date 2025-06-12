#include <stdio.h>

int main() {
    char movieType, ticketCategory;
    int ticketPrice = 0;
    int numberOfTickets;
    int totalCost;

    // Prompt for movie type
    printf("Select Movie Type:\n");
    printf("A - Action\nC - Comedy\nD - Drama\n");
    printf("Enter your choice: ");
    scanf(" %c", &movieType);

    // Prompt for ticket category
    printf("Select Ticket Category:\n");
    printf("R - Regular\nP - Premium\n");
    printf("Enter your choice: ");
    scanf(" %c", &ticketCategory);

    // Prompt for number of tickets
    printf("Enter the number of tickets: ");
    scanf("%d", &numberOfTickets);

    // Determine ticket price using switch
    switch (movieType) {
        case 'A':
        case 'a':
            switch (ticketCategory) {
                case 'R':
                case 'r': ticketPrice = 10; break;
                case 'P':
                case 'p': ticketPrice = 15; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        case 'C':
        case 'c':
            switch (ticketCategory) {
                case 'R':
                case 'r': ticketPrice = 8; break;
                case 'P':
                case 'p': ticketPrice = 12; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        case 'D':
        case 'd':
            switch (ticketCategory) {
                case 'R':
                case 'r': ticketPrice = 7; break;
                case 'P':
                case 'p': ticketPrice = 10; break;
                default: printf("Invalid ticket category.\n"); return 1;
            }
            break;
        default:
            printf("Invalid movie type.\n");
            return 1;
    }

    // Calculate total cost
    totalCost = ticketPrice * numberOfTickets;

    // Display all user inputs and result
    printf("\n===== Ticket Summary =====\n");

    printf("Movie Type: ");
    switch (movieType) {
        case 'A': case 'a': printf("Action\n"); break;
        case 'C': case 'c': printf("Comedy\n"); break;
        case 'D': case 'd': printf("Drama\n"); break;
    }

    printf("Ticket Category: ");
    switch (ticketCategory) {
        case 'R': case 'r': printf("Regular\n"); break;
        case 'P': case 'p': printf("Premium\n"); break;
    }

    printf("Number of Tickets: %d\n", numberOfTickets);
    printf("Price per Ticket: £%d\n", ticketPrice);
    printf("Total Cost: £%d\n", totalCost);

    return 0;
}