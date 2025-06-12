#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isValidNumber(const char *str) {
    int dotCount = 0;
    int i = 0;

    if (str[0] == '-') i++;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0;
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }

    return (i > 0);
}

int main() {
    char input[100];
    double value, result;
    char continueChoice;
    int conversions = 0;
    int conversionType;

    printf("=== Unit Conversion Tool ===\n");

    do {
        // Menu for conversion type
        printf("\nChoose conversion type:\n");
        printf("1. Length (Kilometers to Miles)\n");
        printf("2. Weight (Kilograms to Pounds)\n");
        printf("3. Time (Hours to Minutes)\n");
        printf("Enter your choice (1-3): ");

        while (scanf("%d", &conversionType) != 1 || conversionType < 1 || conversionType > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3: ");
            while (getchar() != '\n');
        }

        while (getchar() != '\n'); // Clear buffer

        // Input for value
        while (1) {
            printf("Enter the value to convert: ");
            scanf("%s", input);

            if (isValidNumber(input)) {
                value = atof(input);
                break;
            } else {
                printf("Invalid input. Please enter a numeric value.\n");
            }
        }

        // Perform conversion
        switch (conversionType) {
            case 1:
                result = value * 0.621371;
                printf("%.2f kilometers is equal to %.2f miles.\n", value, result);
                break;
            case 2:
                result = value * 2.20462;
                printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
                break;
            case 3:
                result = value * 60;
                printf("%.2f hours is equal to %.2f minutes.\n", value, result);
                break;
        }

        conversions++;

        // Ask to repeat
        printf("Do you want to perform another conversion? (y/n): ");
        scanf(" %c", &continueChoice);
        continueChoice = tolower(continueChoice);

    } while (continueChoice == 'y');

    printf("\nYou performed %d conversion(s). Thank you for using the converter!\n", conversions);

    return 0;
}