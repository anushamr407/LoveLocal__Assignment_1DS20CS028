
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a deque node
typedef struct {
    int value;
    int index;
} DequeNode;

// Structure to represent a deque
typedef struct {
    DequeNode* array;
    int front;
    int rear;
    int capacity;
} Deque;

// Function to create a deque
Deque* createDeque(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->array = (DequeNode*)malloc(sizeof(DequeNode) * capacity);
    deque->front = -1;
    deque->rear = -1;
    deque->capacity = capacity;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return deque->front == -1;
}

// Function to push an element to the front of the deque
void pushFront(Deque* deque, int value, int index) {
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = deque->capacity - 1;
    } else {
        deque->front--;
    }

    deque->array[deque->front].value = value;
    deque->array[deque->front].index = index;
}

// Function to push an element to the rear of the deque
void pushRear(Deque* deque, int value, int index) {
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == deque->capacity - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->array[deque->rear].value = value;
    deque->array[deque->rear].index = index;
}

// Function to pop the front element from the deque
void popFront(Deque* deque) {
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == deque->capacity - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
}

// Function to pop the rear element from the deque
void popRear(Deque* deque) {
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = deque->capacity - 1;
    } else {
        deque->rear--;
    }
}

// Function to get the front element value of the deque
int frontValue(Deque* deque) {
    return deque->array[deque->front].value;
}

// Function to create an array to store the maximum elements in sliding windows
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Initialize the deque
    Deque* deque = createDeque(numsSize);
    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int resultIndex = 0;

    // Process the first k elements separately
    for (int i = 0; i < k; i++) {
        while (!isEmpty(deque) && nums[i] >= frontValue(deque)) {
            popFront(deque);
        }
        pushRear(deque, nums[i], i);
    }

    // Process the remaining elements
    for (int i = k; i < numsSize; i++) {
        result[resultIndex++] = frontValue(deque);

        while (!isEmpty(deque) && frontValue(deque) <= nums[i]) {
            popFront(deque);
        }

        while (!isEmpty(deque) && deque->array[deque->front].index <= i - k) {
            popFront(deque);
        }

        pushRear(deque, nums[i], i);
    }

    // Add the maximum element for the last window
    result[resultIndex++] = frontValue(deque);

    // Clean up and return the result
    free(deque->array);
    free(deque);
    *returnSize = resultIndex;
    return result;
}

int main() {
    int nums1[] = {1};
    int k1 = 1;

    int nums2[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k2 = 3;

    int returnSize1, returnSize2;
    int *result1 = maxSlidingWindow(nums1, sizeof(nums1) / sizeof(nums1[0]), k1, &returnSize1);
    int *result2 = maxSlidingWindow(nums2, sizeof(nums2) / sizeof(nums2[0]), k2, &returnSize2);

    printf("Input: [1], k = 1\nOutput: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");

    printf("Input: [1, 3, -1, -3, 5, 3, 6, 7], k = 3\nOutput: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Don't forget to free the allocated memory
    free(result1);
    free(result2);

    return 0;
}
