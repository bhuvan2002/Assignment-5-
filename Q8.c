#include <stdio.h>
#include <stdlib.h>

int* findOriginalArray(int* changed, int changedSize, int* returnSize) {
    if (changedSize % 2 == 1) {
        *returnSize = 0;
        return NULL;
    }
    
    int* original = (int*)malloc((changedSize / 2) * sizeof(int));
    int originalSize = 0;
    int doubleCheck = 1;
    
    qsort(changed, changedSize, sizeof(int), compare);
    
    int i = 0;
    while (i < changedSize) {
        int doubledNum = changed[i] * 2;
        int pos = binarySearch(changed, i + 1, changedSize - 1, doubledNum);
        
        if (pos == -1) {
            doubleCheck = 0;
            break;
        } else {
            original[originalSize++] = changed[i];
            removeElement(changed, changedSize, pos);
            i++;
        }
    }
    
    if (!doubleCheck) {
        free(original);
        original = NULL;
        originalSize = 0;
    }
    
    *returnSize = originalSize;
    return original;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

void removeElement(int* arr, int size, int index) {
    for (int i = index; i < size - 1; i++)
        arr[i] = arr[i + 1];
}

int main() {
    int changed[] = {1, 3, 4, 2, 6, 8};
    int changedSize = sizeof(changed) / sizeof(changed[0]);
    int returnSize;
    
    int* original = findOriginalArray(changed, changedSize, &returnSize);
    
    printf("The original array is: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", original[i]);
    
    free(original);
    
    return 0;
}
