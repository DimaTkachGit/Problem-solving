#include <stdio.h>
#include <stdlib.h>

// Define the Student structure
struct Student {
    int id;
    char name[50];
    char grade[5];
};

// Function to add a student to the file
void addStudent() {
    struct Student s;
    FILE *fp;

    // Open file in append mode
    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Get student information from user
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    getchar(); // clear newline from buffer

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);

    printf("Enter Student Grade: ");
    scanf("%s", s.grade);

    // Write to file
    fprintf(fp, "%d,%s,%s\n", s.id, s.name, s.grade);
    fclose(fp);

    printf("Student record added successfully.\n");
}

// Function to display all student records from the file
void displayStudents() {
    struct Student s;
    FILE *fp;

    // Open file in read mode
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("ID\tName\t\tGrade\n");
    printf("--------------------------------\n");

    // Read and display each line
    while (fscanf(fp, "%d,%49[^,],%4s\n", &s.id, s.name, s.grade) == 3) {
        printf("%d\t%-15s\t%s\n", s.id, s.name, s.grade);
    }

    fclose(fp);
}

// Main function with simple menu
int main() {
    int choice;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
