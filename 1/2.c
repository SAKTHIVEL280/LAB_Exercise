#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100
typedef struct {
    char items[MAX_ITEMS][50];
    int size;
} ShoppingList;
void addItem(ShoppingList *list, char *item) {
    if (list->size < MAX_ITEMS) {
        strcpy(list->items[list->size], item);
        list->size++;
    } else {
        printf("Shopping list is full.\n");
    }
}
void removeItem(ShoppingList *list, char *item) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->items[i], item) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                strcpy(list->items[j], list->items[j + 1]);
            }
            list->size--;
            return;
        }
    }
    printf("Item not found.\n");
}
void displayItems(ShoppingList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("Item: %s\n", list->items[i]);
    }
}
int main() {
    ShoppingList myList;
    myList.size = 0;
    addItem(&myList, "Milk");
    addItem(&myList, "Eggs");
    printf("Shopping List:\n");
    displayItems(&myList);
    removeItem(&myList, "Milk");
    printf("Shopping List after removal:\n");
    displayItems(&myList);
    return 0;
}
