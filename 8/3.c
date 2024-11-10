#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100

typedef struct {
    char title[100];
    char content[500];
} Article;
typedef struct {
    Article *articles[TABLE_SIZE];
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
        table->articles[i] = NULL;
    }
    return table;
}
Article *createArticle(char *title, char *content) {
    Article *article = (Article *)malloc(sizeof(Article));
    strcpy(article->title, title);
    strcpy(article->content, content);
    return article;
}
void addArticle(HashTable *table, char *title, char *content) {
    int index = hash(title);
    table->articles[index] = createArticle(title, content);
    printf("Article added successfully.\n");
}
Article *getArticle(HashTable *table, char *title) {
    int index = hash(title);
    if (table->articles[index] == NULL || strcmp(table->articles[index]->title, title) != 0) {
        return NULL;
    }
    return table->articles[index];
}

int main() {
    HashTable *table = createHashTable();
    addArticle(table, "Article1", "Content of article 1");
    addArticle(table, "Article2", "Content of article 2");

    Article *article = getArticle(table, "Article1");
    if (article != NULL) {
        printf("Article found: Title=%s, Content=%s\n", article->title, article->content);
    } else {
        printf("Article not found.\n");
    }
    article = getArticle(table, "Article3");
    if (article != NULL) {
        printf("Article found: Title=%s, Content=%s\n", article->title, article->content);
    } else {
        printf("Article not found.\n");
    }
    return 0;
}
