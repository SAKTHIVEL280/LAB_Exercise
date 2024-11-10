#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
} Contact;

int findContactByName(Contact *contacts, int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of contacts: ");
    scanf("%d", &n);

    Contact *contacts = (Contact *)malloc(n * sizeof(Contact));
    if (contacts == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter contact details (Name Phone):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %s", contacts[i].name, contacts[i].phone);
    }

    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    int index = findContactByName(contacts, n, name);
    if (index != -1) {
        printf("Contact found: Name=%s, Phone=%s\n", contacts[index].name, contacts[index].phone);
    } else {
        printf("Contact not found.\n");
    }

    free(contacts);
    return 0;
}
