#include <stdio.h>
#include <stdlib.h>

int** construct2DArray(int* original, int m, int n) {
    int length = m * n;
    if (length != sizeof(original) / sizeof(original[0])) {
        return NULL;
    }
    int** arr = (int**)malloc(m * sizeof(int*));
    int index = 0;
    for (int i = 0; i < m; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            arr[i][j] = original[index++];
        }
    }
    return arr;
}

void print2DArray(int** arr, int m, int n) {
    printf("The 2D Array is after conversion:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void free2DArray(int** arr, int m) {
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int original[] = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    int** arr = construct2DArray(original, m, n);
    if (arr != NULL) {
        print2DArray(arr, m, n);
        free2DArray(arr, m);
    } else {
        printf("Failed to construct 2D array.\n");
    }
    return 0;
}
