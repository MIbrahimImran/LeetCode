/* 783. Minimum Distance Between BST Nodes */

class Solution {
public:
    // Time: O(n) && Space: O(d)
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        inorderTraversal(root, prev, minDiff);
        return minDiff;
    }

    void inorderTraversal(TreeNode* node, TreeNode* &prev, int &minDiff) {
        if (!node) return;
        inorderTraversal(node->left, prev, minDiff);
        if (prev) minDiff = min(minDiff, node->val - prev->val);
        prev = node;
        inorderTraversal(node->right, prev, minDiff);
    }
};
```