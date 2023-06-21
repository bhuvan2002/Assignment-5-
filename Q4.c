#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* values;
    int size;
} Array;

Array findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    Array result;

    int* s1 = (int*)malloc(nums1Size * sizeof(int));
    int s1Size = 0;

    int* s2 = (int*)malloc(nums2Size * sizeof(int));
    int s2Size = 0;

    for (int i = 0; i < nums1Size; i++) {
        int num = nums1[i];
        int isDuplicate = 0;
        for (int j = 0; j < s1Size; j++) {
            if (s1[j] == num) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            s1[s1Size++] = num;
        }
    }

    for (int i = 0; i < nums2Size; i++) {
        int num = nums2[i];
        int isDuplicate = 0;
        for (int j = 0; j < s2Size; j++) {
            if (s2[j] == num) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            s2[s2Size++] = num;
        }
    }

    int* a1 = (int*)malloc(s1Size * sizeof(int));
    int a1Size = 0;

    int* a2 = (int*)malloc(s2Size * sizeof(int));
    int a2Size = 0;

    for (int i = 0; i < s1Size; i++) {
        int num = s1[i];
        int isMissing = 1;
        for (int j = 0; j < s2Size; j++) {
            if (s2[j] == num) {
                isMissing = 0;
                break;
            }
        }
        if (isMissing) {
            a1[a1Size++] = num;
        }
    }

    for (int i = 0; i < s2Size; i++) {
        int num = s2[i];
        int isMissing = 1;
        for (int j = 0; j < s1Size; j++) {
            if (s1[j] == num) {
                isMissing = 0;
                break;
            }
        }
        if (isMissing) {
            a2[a2Size++] = num;
        }
    }

    result.values = a1;
    result.size = a1Size;

    free(s1);
    free(s2);

    return result;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {2, 4, 6};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    Array result = findDifference(nums1, nums1Size, nums2, nums2Size);

    printf("Array 1: ");
    printArray(result.values, result.size);

    printf("Array 2: ");
    printArray(result.values, result.size);

    free(result.values);

    return 0;
}
