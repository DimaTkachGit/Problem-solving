#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if the input is a valid number
int isValidNumber(const char *str) {
    int dotCount = 0;
    int i = 0;

    // Optional leading minus for negative values
    if (str[0] == '-') i++;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0; // more than one dot is invalid
        } else if (!isdigit(str[i])) {
            return 0; // not a digit or a dot
        }
    }

    return (i > 0); // valid if string is not empty
}

int main() {
    char input[100];
    double kilometers = 0.0, miles;

    printf("Enter distance in kilometers: ");

    while (1) {
        scanf("%s", input);

        if (isValidNumber(input)) {
            kilometers = atof(input); // convert valid string to double
            break;
        } else {
            printf("Invalid input. Please enter a numeric value: ");
        }
    }

    miles = kilometers * 0.621371;
    printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);

    return 0;
}