/* 965. Univalued Binary Tree */

class Solution {
public:
    // Time: O(n) && Space: O(d)
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return isUnivalTreeH(root, root->val);
    }

    bool isUnivalTreeH(TreeNode* node, int value) {
        if(!node) return true;
        if(node->val != value) return false;
        bool leftSubTree = isUnivalTreeH(node->left, value);
        bool rightSubTree = isUnivalTreeH(node->right, value);
        return leftSubTree && rightSubTree;
    }
};