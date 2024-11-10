#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100
typedef struct {
    char name[50];
    char phone[15];
} Contact;
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int size;
} ContactList;
void addContact(ContactList *list, char *name, char *phone) {
    if (list->size < MAX_CONTACTS) {
        strcpy(list->contacts[list->size].name, name);
        strcpy(list->contacts[list->size].phone, phone);
        list->size++;
    } else {
        printf("Contact list is full.\n");
    }
}
void deleteContact(ContactList *list, char *name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                list->contacts[j] = list->contacts[j + 1];
            }
            list->size--;
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayContacts(ContactList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s, Phone: %s\n", list->contacts[i].name, list->contacts[i].phone);
    }
}
int main() {
    ContactList myContacts;
    myContacts.size = 0;
    addContact(&myContacts, "Alice", "1234567890");
    addContact(&myContacts, "Bob", "9876543210");
    printf("Contacts:\n");
    displayContacts(&myContacts);
    deleteContact(&myContacts, "Alice");
    printf("Contacts after deletion:\n");
    displayContacts(&myContacts);

    return 0;
}
