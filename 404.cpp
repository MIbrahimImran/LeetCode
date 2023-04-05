/* 404. Sum of Left Leaves */

class Solution {
public:
    // Time: O(n) && Space: O(d)
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        inOrderTraversal(root, false, sum);
        return sum;
    }

    void inOrderTraversal(TreeNode* node, bool isLeftNode, int &sum) {
        if(!node) return;

        if(isLeftNode && !node->left && !node->right) {
            sum += node->val;
        }

        inOrderTraversal(node->left, true, sum);
        inOrderTraversal(node->right, false, sum);
    }
};