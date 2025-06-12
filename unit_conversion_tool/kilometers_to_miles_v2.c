#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if input is a valid number
int isValidNumber(const char *str) {
    int dotCount = 0;
    int i = 0;

    // Optional minus sign
    if (str[0] == '-') i++;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0;
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }

    return (i > 0); // At least one digit
}

int main() {
    char input[100];
    double kilometers = 0.0, miles;
    char choice;
    int conversions = 0;

    printf("=== Kilometers to Miles Converter ===\n");

    while (1) {
        // Input validation loop
        while (1) {
            printf("\nEnter distance in kilometers: ");
            scanf("%s", input);

            if (isValidNumber(input)) {
                kilometers = atof(input);
                break;
            } else {
                printf("Invalid input. Please enter a numeric value.\n");
            }
        }

        // Perform conversion
        miles = kilometers * 0.621371;
        printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);
        conversions++;

        // Ask to continue
        printf("Do you want to convert another distance? (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice);

        if (choice != 'y') {
            break;
        }
    }

    // Final output
    printf("\nYou performed %d conversion(s). Thank you for using the converter!\n", conversions);

    return 0;
}