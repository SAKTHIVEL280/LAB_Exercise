#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book {
    char title[100];
    struct Book *prev;
    struct Book *next;
} Book;
typedef struct {
    Book *head;
    Book *tail;
} Library;
void addBook(Library *library, char *title) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    newBook->prev = NULL;
    newBook->next = NULL;
    if (library->tail == NULL) {
        library->head = newBook;
        library->tail = newBook;
    } else {
        library->tail->next = newBook;
        newBook->prev = library->tail;
        library->tail = newBook;
    }
}
void removeBook(Library *library, char *title) {
    Book *current = library->head;
    while (current != NULL && strcmp(current->title, title) != 0) {
        current = current->next;
    }
    if (current != NULL) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            library->head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        } else {
            library->tail = current->prev;
        }
        free(current);
    } else {
        printf("Book not found.\n");
    }
}
void displayBooksForward(Library *library) {
    Book *current = library->head;
    while (current != NULL) {
        printf("Book: %s\n", current->title);
        current = current->next;
    }
}
void displayBooksBackward(Library *library) {
    Book *current = library->tail;
    while (current != NULL) {
        printf("Book: %s\n", current->title);
        current = current->prev;
    }
}
int main() {
    Library myLibrary;
    myLibrary.head = NULL;
    myLibrary.tail = NULL;
    addBook(&myLibrary, "The Great Gatsby");
    addBook(&myLibrary, "1984");
    printf("Books in forward order:\n");
    displayBooksForward(&myLibrary);
    printf("Books in reverse order:\n");
    displayBooksBackward(&myLibrary);
    removeBook(&myLibrary, "1984");
    printf("Books after removal:\n");
    displayBooksForward(&myLibrary);
    return 0;
}
