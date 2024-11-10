#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **xp, char **yp) {
    char *temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(char *arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)       
        for (j = 0; j < n-i-1; j++)  
            if (strcmp(arr[j], arr[j+1]) > 0)
                swap(&arr[j], &arr[j+1]);
}
int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);
    char **titles = (char **)malloc(n * sizeof(char *));
    if (titles == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }
    printf("Enter the titles of the books:\n");
    for (int i = 0; i < n; i++) {
        titles[i] = (char *)malloc(100 * sizeof(char));
        if (titles[i] == NULL) {
            printf("Memory not allocated.\n");
            return 1;
        }
        scanf(" %[^\n]", titles[i]);
    }
    bubbleSort(titles, n);

    printf("Sorted book titles in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", titles[i]);
        free(titles[i]);
    }
    free(titles);
    return 0;
}
