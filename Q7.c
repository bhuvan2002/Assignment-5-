#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int st = 0;
    int en = numsSize - 1;
    
    while (st <= en) {
        if (nums[st] <= nums[en])
            break;
        
        int mid = st + (en - st) / 2;
        
        if (nums[st] <= nums[mid]) {
            st = mid + 1;
        } else {
            en = mid;
        }
    }
    
    return nums[st];
}

int main() {
    int nums[] = {3, 4, 5, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int min = findMin(nums, numsSize);
    
    printf("%d\n", min);
    
    return 0;
}
