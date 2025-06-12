#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Global file name variable
char fileName[] = "students.txt";

// Define Student structure
struct Student {
    int id;
    char name[50];
    char grade[5];
};

// Function to check if student exists
int studentExists(int id) {
    FILE *fp = fopen(fileName, "r");
    struct Student s;
    if (fp == NULL) return 0;

    while (fscanf(fp, "%d,%49[^,],%4s\n", &s.id, s.name, s.grade) == 3) {
        if (s.id == id) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// Add student and return 1 if success, 0 if duplicate
int addStudent(int id, char *name, char *grade) {
    if (studentExists(id)) return 0;

    FILE *fp = fopen(fileName, "a");
    if (fp == NULL) return 0;

    fprintf(fp, "%d,%s,%s\n", id, name, grade);
    fclose(fp);
    return 1;
}

// Load students into array and return count
int loadStudents(struct Student students[]) {
    FILE *fp = fopen(fileName, "r");
    int count = 0;
    if (fp == NULL) return 0;

    while (fscanf(fp, "%d,%49[^,],%4s\n", &students[count].id, students[count].name, students[count].grade) == 3) {
        count++;
    }

    fclose(fp);
    return count;
}

// Display students in formatted table
void displayStudents(struct Student students[], int count) {
    printf("\n================ Student Records ================\n");
    printf("| %-5s | %-20s | %-6s |\n", "ID", "Name", "Grade");
    printf("|--------|----------------------|--------|\n");

    for (int i = 0; i < count; i++) {
        printf("| %-5d | %-20s | %-6s |\n",
               students[i].id,
               students[i].name,
               students[i].grade);
    }

    printf("=================================================\n");
}

// Search student by ID
int searchStudent(int id) {
    struct Student students[MAX_STUDENTS];
    int count = loadStudents(students);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found:\nID: %d\nName: %s\nGrade: %s\n", students[i].id, students[i].name, students[i].grade);
            return i;
        }
    }
    return -1;
}

// Update student info by ID
int updateStudent(int id, char *newName, char *newGrade) {
    struct Student students[MAX_STUDENTS];
    int count = loadStudents(students);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            strcpy(students[i].name, newName);
            strcpy(students[i].grade, newGrade);
            found = 1;
            break;
        }
    }

    if (!found) return 0;

    FILE *fp = fopen(fileName, "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%s\n", students[i].id, students[i].name, students[i].grade);
    }

    fclose(fp);
    return 1;
}

// Delete a student by ID
int deleteStudent(int id) {
    struct Student students[MAX_STUDENTS];
    int count = loadStudents(students);
    int found = 0;

    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) return 0;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = 1; // skip this student
            continue;
        }
        fprintf(fp, "%d,%s,%s\n", students[i].id, students[i].name, students[i].grade);
    }

    fclose(fp);
    return found;
}

// Main Function
int main() {
    int choice, id, result;
    char name[50], grade[5];
    struct Student students[MAX_STUDENTS];
    int count;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student by ID\n");
        printf("5. Delete Student by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clean input buffer

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter Grade: ");
                scanf("%s", grade);
                result = addStudent(id, name, grade);
                if (result)
                    printf("Student added successfully.\n");
                else
                    printf("Student with ID %d already exists.\n", id);
                break;

            case 2:
                count = loadStudents(students);
                displayStudents(students, count);
                break;

            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                result = searchStudent(id);
                if (result == -1)
                    printf("Student not found.\n");
                break;

            case 4:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter New Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter New Grade: ");
                scanf("%s", grade);
                result = updateStudent(id, name, grade);
                if (result)
                    printf("Student updated successfully.\n");
                else
                    printf("Student with ID %d not found.\n", id);
                break;

            case 5:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                result = deleteStudent(id);
                if (result)
                    printf("Student deleted successfully.\n");
                else
                    printf("Student with ID %d not found.\n", id);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
