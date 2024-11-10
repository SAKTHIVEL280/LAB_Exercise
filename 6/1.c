#include <stdio.h>
#include <stdlib.h>

void swap(float *xp, float *yp) {
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(float arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)       
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main() {
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    float *prices = (float *)malloc(n * sizeof(float));
    if (prices == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter the prices of the products:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }

    bubbleSort(prices, n);

    printf("Sorted prices in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", prices[i]);
    }
    printf("\n");

    free(prices);
    return 0;
}
