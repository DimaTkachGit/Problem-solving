#include <stdio.h>

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

    // Input student grades and generate IDs
    for (int i = 0; i < numStudents; i++) {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grades[i]);
        studentIDs[i] = 1000 + i;  // Generating unique student ID
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display all student grades\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nStudent Grades:\n");
                printf("ID\tGrade\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("%d\t%d\n", studentIDs[i], grades[i]);
                }
                break;
            case 2:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 2);

    return 0;
}
