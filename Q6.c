#include <stdio.h>
#include <stdlib.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    int resCount = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int curr = abs(nums[i]);
        if (nums[curr - 1] < 0)
            res[resCount++] = curr;
        else
            nums[curr - 1] *= -1;
    }
    
    *returnSize = resCount;
    return res;
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* duplicates = findDuplicates(nums, numsSize, &returnSize);
    
    printf("The duplicates number in a given array is ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", duplicates[i]);
    }
    
    free(duplicates);
    
    return 0;
}
