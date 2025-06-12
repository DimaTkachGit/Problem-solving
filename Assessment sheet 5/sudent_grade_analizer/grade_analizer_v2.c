#include <stdio.h>
#include <ctype.h> // For tolower()

#define MAX_STUDENTS 30

int main() {
    int numStudents;
    int grades[MAX_STUDENTS];
    int studentIDs[MAX_STUDENTS];

    printf("Enter the number of students (max 30): ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS || numStudents <= 0) {
        printf("Invalid number of students. Program will exit.\n");
        return 1;
    }

    // Input grades and assign student IDs
    for (int i = 0; i < numStudents; i++) {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grades[i]);
        studentIDs[i] = 1000 + i;
    }

    char choice;

    do {
        printf("\nMenu:\n");
        printf("A. Display all student grades\n");
        printf("B. Calculate and display statistics (average, highest, lowest)\n");
        printf("X. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (tolower(choice)) {
            case 'a':
                printf("\nStudent Grades:\n");
                printf("ID\tGrade\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("%d\t%d\n", studentIDs[i], grades[i]);
                }
                break;

            case 'b': {
                int sum = 0, highest = grades[0], lowest = grades[0];
                for (int i = 0; i < numStudents; i++) {
                    sum += grades[i];
                    if (grades[i] > highest)
                        highest = grades[i];
                    if (grades[i] < lowest)
                        lowest = grades[i];
                }
                float average = (float)sum / numStudents;
                printf("\nGrade Statistics:\n");
                printf("Average Grade: %.2f\n", average);
                printf("Highest Grade: %d\n", highest);
                printf("Lowest Grade: %d\n", lowest);
                break;
            }

            case 'x':
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (tolower(choice) != 'x');

    return 0;
}
