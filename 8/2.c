#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
typedef struct {
    char productID[50];
    char productName[100];
} Product;
typedef struct {
    Product *products[TABLE_SIZE];
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
        table->products[i] = NULL;
    }
    return table;
}

Product *createProduct(char *productID, char *productName) {
    Product *product = (Product *)malloc(sizeof(Product));
    strcpy(product->productID, productID);
    strcpy(product->productName, productName);
    return product;
}

void addProduct(HashTable *table, char *productID, char *productName) {
    int index = hash(productID);
    table->products[index] = createProduct(productID, productName);
    printf("Product added successfully.\n");
}
Product *getProduct(HashTable *table, char *productID) {
    int index = hash(productID);
    if (table->products[index] == NULL || strcmp(table->products[index]->productID, productID) != 0) {
        return NULL;
    }
    return table->products[index];
}
int main() {
    HashTable *table = createHashTable();
    addProduct(table, "P123", "Laptop");
    addProduct(table, "P124", "Smartphone");
    Product *product = getProduct(table, "P123");
    if (product != NULL) {
        printf("Product found: ID=%s, Name=%s\n", product->productID, product->productName);
    } else {
        printf("Product not found.\n");
    }
    product = getProduct(table, "P125");
    if (product != NULL) {
        printf("Product found: ID=%s, Name=%s\n", product->productID, product->productName);
    } else {
        printf("Product not found.\n");
    }
    return 0;
}
