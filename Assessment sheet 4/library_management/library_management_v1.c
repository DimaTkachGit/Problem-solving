#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 5
#define MAX_LENGTH 100

int main() {
    // Use pointers to arrays of strings
    char *bookTitles[MAX_BOOKS];
    char *bookAuthors[MAX_BOOKS];
    char *bookGenres[MAX_BOOKS];

    int bookCount = 0;
    char choice;
    char exitChoice;

    do {
        printf("\n=== Library Management System (With Pointers) ===\n");
        printf("Menu:\n");
        printf("a. Add a new book\n");
        printf("b. View all books\n");
        printf("c. Search for a book\n");
        printf("q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'a' || choice == 'A') {
            if (bookCount < MAX_BOOKS) {
                char temp[MAX_LENGTH];
                getchar(); // clear newline

                printf("Enter Book Title: ");
                fgets(temp, MAX_LENGTH, stdin);
                bookTitles[bookCount] = malloc(strlen(temp) + 1);
                strcpy(bookTitles[bookCount], temp);

                printf("Enter Author Name: ");
                fgets(temp, MAX_LENGTH, stdin);
                bookAuthors[bookCount] = malloc(strlen(temp) + 1);
                strcpy(bookAuthors[bookCount], temp);

                printf("Enter Book Genre: ");
                fgets(temp, MAX_LENGTH, stdin);
                bookGenres[bookCount] = malloc(strlen(temp) + 1);
                strcpy(bookGenres[bookCount], temp);

                printf("Book added successfully!\n");
                bookCount++;
            } else {
                printf("Book limit reached. Cannot add more than %d books.\n", MAX_BOOKS);
            }

        } else if (choice == 'b' || choice == 'B') {
            if (bookCount == 0) {
                printf("No books in the library yet.\n");
            } else {
                printf("\n--- All Books ---\n");
                for (int i = 0; i < bookCount; i++) {
                    printf("Book %d:\n", i + 1);
                    printf("  Title : %s", bookTitles[i]);
                    printf("  Author: %s", bookAuthors[i]);
                    printf("  Genre : %s\n", bookGenres[i]);
                }
            }

        } else if (choice == 'c' || choice == 'C') {
            if (bookCount == 0) {
                printf("No books available to search.\n");
                continue;
            }

            char searchTitle[MAX_LENGTH];
            int found = 0;
            getchar(); // clear newline
            printf("Enter the title of the book to search: ");
            fgets(searchTitle, MAX_LENGTH, stdin);

            for (int i = 0; i < bookCount; i++) {
                if (strcasecmp(bookTitles[i], searchTitle) == 0) {
                    printf("\nBook found:\n");
                    printf("  Title : %s", bookTitles[i]);
                    printf("  Author: %s", bookAuthors[i]);
                    printf("  Genre : %s", bookGenres[i]);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Book not found.\n");
            }

        } else if (choice == 'q' || choice == 'Q') {
            printf("Are you sure you want to quit? (y/n): ");
            scanf(" %c", &exitChoice);
            if (tolower(exitChoice) == 'y') {
                // Free allocated memory before quitting
                for (int i = 0; i < bookCount; i++) {
                    free(bookTitles[i]);
                    free(bookAuthors[i]);
                    free(bookGenres[i]);
                }
                printf("Exiting Library Management System. Goodbye!\n");
                break;
            }

        } else {
            printf("Invalid option. Please try again.\n");
        }

    } while (1);

    return 0;
}
