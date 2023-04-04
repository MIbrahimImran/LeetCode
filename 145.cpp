/* 144. Binary Tree Preorder Traversal */

class Solution1 {
public:
    // Time: O(n) && Space: O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> result;
        deque<TreeNode* > stack{root};

        while(stack.size()) {
            TreeNode *currentNode = stack.back();
            stack.pop_back();

            result.push_back(currentNode->val);
            if(currentNode->right) stack.push_back(currentNode->right);
            if(currentNode->left) stack.push_back(currentNode->left);
        }

        return result;
    }
};

class Solution {
public:
    // Time: O(n) && Space: O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> array;
        inOrderTraversal(root, array);
        return array;
    }

    void inOrderTraversal(TreeNode* tree, vector<int>& array) {
        if(!tree) return;
        array.push_back(tree->val);
        inOrderTraversal(tree->left, array);
        inOrderTraversal(tree->right, array);
    }
};