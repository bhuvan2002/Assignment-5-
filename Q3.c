#include <stdio.h>
#include <stdlib.h>

void sortSquares(int arr[], int n) {
   
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * arr[i];
    }


    qsort(arr, n, sizeof(int), compareIntegers);
}

int compareIntegers(const void* a, const void* b) {
    int intA = *((int*)a);
    int intB = *((int*)b);
    if (intA < intB) {
        return -1;
    } else if (intA > intB) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int arr[] = {-4, -1, 0, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sortSquares(arr, n);

    printf("After sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
