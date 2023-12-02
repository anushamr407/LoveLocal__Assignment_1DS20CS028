#include <stdio.h>
#include <stdlib.h>

int* FindNumber(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;

    if (nums == NULL || numsSize == 0) {
        return NULL;
    }

    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

    // Phase 1: Find the numbers
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Phase 2: Count occurrences of Numbers
    count1 = count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    // Check if number occur more than [ n/3 ] times
    if (count1 > numsSize / 3 && count2 > numsSize / 3) {
        *returnSize = 2;
        int* result = (int*)malloc(2 * sizeof(int));
        result[0] = candidate1;
        result[1] = candidate2;
        return result;
    } else if (count1 > numsSize / 3) {
        *returnSize = 1;
        int* result = (int*)malloc(sizeof(int));
        result[0] = candidate1;
        return result;
    } else if (count2 > numsSize / 3) {
        *returnSize = 1;
        int* result = (int*)malloc(sizeof(int));
        result[0] = candidate2;
        return result;
    }

    return NULL;
}

int main() {
	
    //Array to test
    int arr[] = {3,2,3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int Size;

    int* result = FindNumber(arr, arrSize, &Size);

    printf("Output: [");
    for (int i = 0; i < Size; i++) {
        printf("%d", result[i]);
        if (i < Size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);

    return 0;
}
