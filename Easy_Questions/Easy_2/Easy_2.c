#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to convert a sorted array to a height-balanced BST
struct TreeNode* sortedArrayToBST(int* nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    // Find the middle index of the current subarray
    int mid = start + (end - start) / 2;

    // Create a new node with the middle value as the root
    struct TreeNode* root = newNode(nums[mid]);

    // Recursively build the left and right subtrees
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

// Function to print the inorder traversal of a BST (for verification)
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    // Example 1
    int nums1[] = {-10, -3, 0, 5, 9};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    struct TreeNode* root1 = sortedArrayToBST(nums1, 0, size1 - 1);

    printf("Example 1: ");
    inorderTraversal(root1);
    printf("\n");

    // Example 2
    int nums2[] = {1, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    struct TreeNode* root2 = sortedArrayToBST(nums2, 0, size2 - 1);

    printf("Example 2: ");
    inorderTraversal(root2);
    printf("\n");

    // Memory cleanup
    free(root1);
    free(root2);

    return 0;
}
