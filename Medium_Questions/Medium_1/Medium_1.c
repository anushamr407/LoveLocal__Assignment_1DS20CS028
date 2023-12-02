#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find the lowest common ancestor in a BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root) {
        if (root->val > p->val && root->val > q->val) {
            root = root->left;
        } else if (root->val < p->val && root->val < q->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL; // If the tree is empty or the nodes are not present
}

// Helper function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Example 1
    struct TreeNode* root1 = newNode(6);
    root1->left = newNode(2);
    root1->right = newNode(8);
    root1->left->left = newNode(0);
    root1->left->right = newNode(4);
    root1->right->left = newNode(7);
    root1->right->right = newNode(9);
    root1->left->right->left = newNode(3);
    root1->left->right->right = newNode(5);

    struct TreeNode* p1 = newNode(2);
    struct TreeNode* q1 = newNode(8);

    struct TreeNode* result1 = lowestCommonAncestor(root1, p1, q1);
    printf("Output 1: LCA = %d\n", result1->val);

    // Example 2
    struct TreeNode* root2 = newNode(6);
    root2->left = newNode(2);
    root2->right = newNode(8);
    root2->left->left = newNode(0);
    root2->left->right = newNode(4);
    root2->right->left = newNode(7);
    root2->right->right = newNode(9);
    root2->left->right->left = newNode(3);
    root2->left->right->right = newNode(5);

    struct TreeNode* p2 = newNode(2);
    struct TreeNode* q2 = newNode(4);

    struct TreeNode* result2 = lowestCommonAncestor(root2, p2, q2);
    printf("Output 2: LCA = %d\n", result2->val);

    // Example 3
    struct TreeNode* root3 = newNode(2);
    root3->left = newNode(1);

    struct TreeNode* p3 = newNode(2);
    struct TreeNode* q3 = newNode(1);

    struct TreeNode* result3 = lowestCommonAncestor(root3, p3, q3);
    printf("Output 3: LCA = %d\n", result3->val);

    // Memory cleanup
    free(root1);
    free(root2);
    free(root3);
    free(p1);
    free(q1);
    free(p2);
    free(q2);
    free(p3);
    free(q3);

    return 0;
}
