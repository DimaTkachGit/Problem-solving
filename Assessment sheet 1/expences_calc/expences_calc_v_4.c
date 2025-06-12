#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100
#define MAX_CATEGORIES 50

// Function to check if a string is digits only
int isDigitsOnly(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Get validated number input
int getValidNumberInput(char prompt[]) {
    char input[MAX_LEN];
    int value;

    while (1) {
        printf("%s", prompt);
        scanf("%s", input);

        if (isDigitsOnly(input)) {
            value = atoi(input);
            break;
        } else {
            printf("❌ Invalid input. Please enter digits only.\n");
        }
    }

    return value;
}

int main() {
    int numCategories;
    char categories[MAX_CATEGORIES][MAX_LEN];
    int week1[MAX_CATEGORIES], week2[MAX_CATEGORIES];
    int totalWeek1 = 0, totalWeek2 = 0;

    printf("Enter the number of expense categories: ");
    numCategories = getValidNumberInput("");

    // Get names of the categories
    for (int i = 0; i < numCategories; i++) {
        printf("Enter name for category #%d: ", i + 1);
        scanf("%s", categories[i]);
    }

    // Get expenses for Week 1
    printf("\n--- Enter Week 1 Expenses ---\n");
    for (int i = 0; i < numCategories; i++) {
        char prompt[150];
        sprintf(prompt, "Enter expense for %s (Week 1): $", categories[i]);
        week1[i] = getValidNumberInput(prompt);
        totalWeek1 += week1[i];
    }

    // Get expenses for Week 2
    printf("\n--- Enter Week 2 Expenses ---\n");
    for (int i = 0; i < numCategories; i++) {
        char prompt[150];
        sprintf(prompt, "Enter expense for %s (Week 2): $", categories[i]);
        week2[i] = getValidNumberInput(prompt);
        totalWeek2 += week2[i];
    }

    // Show detailed breakdown
    printf("\n===== Expense Breakdown =====\n");
    printf("%-15s | Week 1 ($) | Week 2 ($) | Change\n", "Category");
    printf("----------------------------------------------\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%-15s | %-10d | %-10d | ", categories[i], week1[i], week2[i]);

        if (week2[i] > week1[i]) {
            printf("⬆️ +%d\n", week2[i] - week1[i]);
        } else if (week2[i] < week1[i]) {
            printf("⬇️ -%d\n", week1[i] - week2[i]);
        } else {
            printf("– No change\n");
        }
    }

    // Show total comparison
    printf("\nTotal Week 1 Expense: $%d\n", totalWeek1);
    printf("Total Week 2 Expense: $%d\n", totalWeek2);

    if (totalWeek2 > totalWeek1) {
        printf("📈 Overall spending increased by $%d.\n", totalWeek2 - totalWeek1);
    } else if (totalWeek2 < totalWeek1) {
        printf("📉 Overall spending decreased by $%d.\n", totalWeek1 - totalWeek2);
    } else {
        printf("⚖️  Overall spending stayed the same.\n");
    }

    return 0;
}