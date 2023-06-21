#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int count = 0;
    int arr2Length = arr2Size;
    for (int i = 0; i < arr1Size; i++) {
        int localCount = 0;
        for (int j = 0; j < arr2Length; j++) {
            if (abs(arr1[i] - arr2[j]) <= d)
                break;
            else
                localCount++;
        }
        if (arr2Length == localCount)
            count++;
    }
    return count;
}

int main() {
    int arr1[] = {4, 5, 8};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {10, 9, 1, 8};
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);

    int d = 2;

    int result = findTheDistanceValue(arr1, arr1Size, arr2, arr2Size, d);

    printf("Count: %d\n", result);

    return 0;
}
