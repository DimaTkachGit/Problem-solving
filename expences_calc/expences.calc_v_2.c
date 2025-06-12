#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100

// Function to check if a string contains only digits
int isDigitsOnly(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to get valid input (digits only)
int getValidInput(char category[]) {
    char input[MAX_LEN];
    int value;

    while (1) {
        printf("Enter your weekly expense for %s (digits only): $", category);
        scanf("%s", input);

        if (isDigitsOnly(input)) {
            value = atoi(input);  // Convert to integer
            break;
        } else {
            printf("❌ Invalid input. Please enter digits only (no letters, symbols, or decimals).\n");
        }
    }

    return value;
}

int main() {
    int groceries, rent, utilities, budget, totalExpense;

    // Get validated inputs
    groceries = getValidInput("Groceries");
    rent = getValidInput("Rent");
    utilities = getValidInput("Utilities");

    // Get budget with same validation
    printf("\n--- Budget Setup ---\n");
    budget = getValidInput("Weekly Budget");

    // Calculate total
    totalExpense = groceries + rent + utilities;

    // Show summary
    printf("\n----- Weekly Expense Summary -----\n");
    printf("Groceries: $%d\n", groceries);
    printf("Rent:      $%d\n", rent);
    printf("Utilities: $%d\n", utilities);
    printf("----------------------------------\n");
    printf("Total Weekly Expense: $%d\n", totalExpense);
    printf("Weekly Budget:        $%d\n", budget);
    printf("----------------------------------\n");

    // Budget result
    if (totalExpense > budget) {
        printf("⚠️  You have exceeded your budget by $%d.\n", totalExpense - budget);
    } else if (totalExpense < budget) {
        printf("✅ You are within your budget. You saved $%d.\n", budget - totalExpense);
    } else {
        printf("ℹ️  You have exactly met your budget.\n");
    }

    return 0;
}