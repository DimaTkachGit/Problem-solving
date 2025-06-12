#include <stdio.h>
#include <ctype.h> // For tolower()

#define MAX_STUDENTS 30
#define PASS_MARK 50

// Function to sort grades and IDs using bubble sort
void sortGrades(int grades[], int studentIDs[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (grades[j] > grades[j + 1]) {
                int temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;

                int tempID = studentIDs[j];
                studentIDs[j] = studentIDs[j + 1];
                studentIDs[j + 1] = tempID;
            }
        }
    }
}

// SECTION: Using getchar() for menu input

int main() {
    int grades[MAX_STUDENTS];
    int studentIDs[MAX_STUDENTS];
    int numStudents = 0;

    printf("Enter student grades (max 30). Enter -1 to stop:\n");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        int grade;
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grade);

        if (grade == -1)
            break;

        grades[numStudents] = grade;
        studentIDs[numStudents] = 1000 + numStudents;
        numStudents++;
    }

    if (numStudents == 0) {
        printf("No grades were entered. Exiting program.\n");
        return 1;
    }

    char choice;

    do {
        printf("\nMenu:\n");
        printf("A. Display all student grades\n");
        printf("B. Calculate and display statistics (average, highest, lowest)\n");
        printf("C. Count number of students who passed and failed\n");
        printf("D. Sort and display grades in ascending order\n");
        printf("X. Exit\n");
        printf("Enter your choice: ");
        
        // Clear input buffer before using getchar()
        while ((choice = getchar()) == '\n'); // Skip newline characters

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
                    if (grades[i] > highest) highest = grades[i];
                    if (grades[i] < lowest) lowest = grades[i];
                }
                float average = (float)sum / numStudents;
                printf("\nGrade Statistics:\n");
                printf("Average Grade: %.2f\n", average);
                printf("Highest Grade: %d\n", highest);
                printf("Lowest Grade: %d\n", lowest);
                break;
            }

            case 'c': {
                int passed = 0, failed = 0;
                for (int i = 0; i < numStudents; i++) {
                    if (grades[i] >= PASS_MARK)
                        passed++;
                    else
                        failed++;
                }
                printf("\nPass/Fail Report:\n");
                printf("Passed: %d student(s)\n", passed);
                printf("Failed: %d student(s)\n", failed);
                break;
            }

            case 'd':
                sortGrades(grades, studentIDs, numStudents);
                printf("\nSorted Student Grades (Ascending):\n");
                printf("ID\tGrade\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("%d\t%d\n", studentIDs[i], grades[i]);
                }
                break;

            case 'x':
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (tolower(choice) != 'x');

    return 0;
}
