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

// Function to get validated digit-only input
int getValidInput(char category[], int week) {
    char input[MAX_LEN];
    int value;

    while (1) {
        printf("Enter your %s expense for Week %d (digits only): $", category, week);
        scanf("%s", input);

        if (isDigitsOnly(input)) {
            value = atoi(input); // convert to integer
            break;
        } else {
            printf("❌ Invalid input. Please enter digits only.\n");
        }
    }

    return value;
}

int main() {
    int groceriesWeek1, rentWeek1, utilitiesWeek1, totalWeek1;
    int groceriesWeek2, rentWeek2, utilitiesWeek2, totalWeek2;

    printf("----- Week 1 Expenses -----\n");
    groceriesWeek1 = getValidInput("Groceries", 1);
    rentWeek1 = getValidInput("Rent", 1);
    utilitiesWeek1 = getValidInput("Utilities", 1);

    printf("\n----- Week 2 Expenses -----\n");
    groceriesWeek2 = getValidInput("Groceries", 2);
    rentWeek2 = getValidInput("Rent", 2);
    utilitiesWeek2 = getValidInput("Utilities", 2);

    // Calculate totals
    totalWeek1 = groceriesWeek1 + rentWeek1 + utilitiesWeek1;
    totalWeek2 = groceriesWeek2 + rentWeek2 + utilitiesWeek2;

    // Print summaries
    printf("\n===== Weekly Expense Summary =====\n");

    printf("Week 1 - Groceries: $%d | Rent: $%d | Utilities: $%d | Total: $%d\n",
           groceriesWeek1, rentWeek1, utilitiesWeek1, totalWeek1);

    printf("Week 2 - Groceries: $%d | Rent: $%d | Utilities: $%d | Total: $%d\n",
           groceriesWeek2, rentWeek2, utilitiesWeek2, totalWeek2);

    printf("==================================\n");

    // Compare spending between weeks
    if (totalWeek2 > totalWeek1) {
        printf("📈 Your spending increased by $%d in Week 2.\n", totalWeek2 - totalWeek1);
    } else if (totalWeek2 < totalWeek1) {
        printf("📉 Your spending decreased by $%d in Week 2.\n", totalWeek1 - totalWeek2);
    } else {
        printf("⚖️  Your spending stayed the same in both weeks.\n");
    }

    return 0;
}