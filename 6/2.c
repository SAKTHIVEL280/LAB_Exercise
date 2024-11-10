#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *xp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)       
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main() {
    int n;
    printf("Enter number of participants: ");
    scanf("%d", &n);

    int *ages = (int *)malloc(n * sizeof(int));
    if (ages == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter the ages of the participants:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", ages[i]);
    }

    bubbleSort(ages, n);

    printf("Sorted ages in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ages[i]);
    }
    printf("\n");

    free(ages);
    return 0;
}
