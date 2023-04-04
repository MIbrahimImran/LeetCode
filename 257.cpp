/* 257. Binary Tree Paths */

class Solution {
public:
    // Time: O(n) && Space: O(n)
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        buildPath(root, "", paths);
        return paths;
    }

    void buildPath(TreeNode* node, string currentPath, vector<string>& paths) {
        if(!node) return;

        currentPath += to_string(node->val);
        if(!node->left && !node->right) {   
            paths.push_back(currentPath); 
        }

        currentPath += "->";
        buildPath(node->left, currentPath, paths);
        buildPath(node->right, currentPath, paths);

    }
};