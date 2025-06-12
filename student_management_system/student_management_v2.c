#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define Student structure
struct Student {
    int id;
    char name[50];
    char grade[5];
};

// Function to check if a student with given ID exists in file
int studentExists(int id) {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;

    if (fp == NULL) {
        return 0; // File doesn't exist yet, so no duplicates
    }

    while (fscanf(fp, "%d,%49[^,],%4s\n", &s.id, s.name, s.grade) == 3) {
        if (s.id == id) {
            fclose(fp);
            return 1; // Found duplicate
        }
    }

    fclose(fp);
    return 0; // No duplicate found
}

// Function to add a student (with parameters)
void addStudent(int id, char *name, char *grade) {
    if (studentExists(id)) {
        printf("Student with ID %d already exists. Cannot add duplicate.\n", id);
        return;
    }

    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%d,%s,%s\n", id, name, grade);
    fclose(fp);
    printf("Student added successfully.\n");
}

// Function to load students from file into array
int loadStudents(struct Student students[]) {
    FILE *fp = fopen("students.txt", "r");
    int count = 0;

    if (fp == NULL) {
        return 0; // No file means no students
    }

    while (fscanf(fp, "%d,%49[^,],%4s\n", &students[count].id, students[count].name, students[count].grade) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}

// Function to display students from array
void displayStudents(struct Student students[], int count) {
    printf("\nStudent Records:\n");
    printf("ID\tName\t\tGrade\n");
    printf("--------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%s\n", students[i].id, students[i].name, students[i].grade);
    }
}

// Function to search student by ID
void searchStudent(int id) {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");
    int found = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    while (fscanf(fp, "%d,%49[^,],%4s\n", &s.id, s.name, s.grade) == 3) {
        if (s.id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\nName: %s\nGrade: %s\n", s.id, s.name, s.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(fp);
}

// Main function with parameter usage
int main() {
    int choice;
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int id;
    char name[50];
    char grade[5];

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                getchar(); // Clear newline
                printf("Enter Student Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter Student Grade: ");
                scanf("%s", grade);
                addStudent(id, name, grade);
                break;

            case 2:
                count = loadStudents(students);
                displayStudents(students, count);
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchStudent(id);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
