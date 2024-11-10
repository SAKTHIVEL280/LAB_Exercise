#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char username[50];
    char details[100];
} User;

int findUserByUsername(User *users, int n, char *username) {
    for (int i = 0; i < n; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    printf("Enter number of users: ");
    scanf("%d", &n);
    User *users = (User *)malloc(n * sizeof(User));
    if (users == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter user details (Username Details):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %s", users[i].username, users[i].details);
    }
    char username[50];
    printf("Enter username to search: ");
    scanf("%s", username);
    int index = findUserByUsername(users, n, username);
    if (index != -1) {
        printf("User found: Username=%s, Details=%s\n", users[index].username, users[index].details);
    } else {
        printf("User not found.\n");
    }
    free(users);
    return 0;
}
