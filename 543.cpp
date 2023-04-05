/* 543. Diameter of Binary Tree */

struct TreeInfo {
    int height;
    int diameter;
};

class Solution {
public:
    // Time: O(n) && Space: O(d)
    int diameterOfBinaryTree(TreeNode* root) {
        return getTreeInfo(root).diameter;
    }

    TreeInfo getTreeInfo(TreeNode* node) {
        if(!node) return TreeInfo{0, 0};

        TreeInfo leftSubTree = getTreeInfo(node->left);
        TreeInfo rightSubTree = getTreeInfo(node->right);

        int longestPathThroughRoot = leftSubTree.height + rightSubTree.height;
        int currentDiameter = max(leftSubTree.diameter, rightSubTree.diameter);
        int diameter = max(longestPathThroughRoot, currentDiameter);
        int height = max(leftSubTree.height, rightSubTree.height) + 1;

        return TreeInfo{height, diameter};
    }
};