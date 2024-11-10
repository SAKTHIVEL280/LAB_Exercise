#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
typedef struct {
    char username[50];
    char password[50];
} User;
typedef struct {
    User *users[TABLE_SIZE];
} HashTable;

int hash(char *str) {
    int hash = 0;
    while (*str) {
        hash = (hash + *str) % TABLE_SIZE;
        str++;
    }
    return hash;
}
HashTable *createHashTable() {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->users[i] = NULL;
    }
    return table;
}
int checkUsernameExists(HashTable *table, char *username) {
    int index = hash(username);
    if (table->users[index] == NULL) {
        return 0; // Username does not exist
    } else {
        return strcmp(table->users[index]->username, username) == 0;
    }
}
void addUser(HashTable *table, char *username, char *password) {
    if (checkUsernameExists(table, username)) {
        printf("Username already exists.\n");
        return;
    }
    int index = hash(username);
    User *user = (User *)malloc(sizeof(User));
    strcpy(user->username, username);
    strcpy(user->password, password);
    table->users[index] = user;
    printf("User added successfully.\n");
}
int main() {
    HashTable *table = createHashTable();
    addUser(table, "user1", "pass1");
    addUser(table, "user2", "pass2");

    printf("Checking if 'user1' exists: %d\n", checkUsernameExists(table, "user1"));
    printf("Checking if 'user3' exists: %d\n", checkUsernameExists(table, "user3"));
    return 0;
}
