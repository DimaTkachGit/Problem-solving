#include <stdio.h>

int main() {
    // Declare and assign values to the expense categories
    float groceries = 150.75;
    float rent = 850.00;
    float utilities = 120.25;

    // Calculate the total weekly expense
    float totalExpense = groceries + rent + utilities;

    // Display the output
    printf("----- Weekly Expense Tracker -----\n");
    printf("Groceries: $%.2f\n", groceries);
    printf("Rent:      $%.2f\n", rent);
    printf("Utilities: $%.2f\n", utilities);
    printf("----------------------------------\n");
    printf("Total Weekly Expense: $%.2f\n", totalExpense);

    return 0;
}