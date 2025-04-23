#include <stdio.h>

// nums dizisinden tekrar edenleri siler (sıralı dizi için geçerlidir)
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int j = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}