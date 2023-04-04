/* 145. Binary Tree Postorder Traversal */

class Solution1 {
public:
    // Time: O(n) && Space: O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> result;
        deque<TreeNode *> stack{root};
        while(stack.size()) {
            TreeNode* currentNode = stack.back();
            stack.pop_back();
            result.push_back(currentNode->val);
            if(currentNode->left) stack.push_back(currentNode->left);
            if(currentNode->right) stack.push_back(currentNode->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution2 {
public:
    // Time: O(n) && Space: O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> resultArray; 
        deque<TreeNode *> stack{root};

        while(stack.size()) {
            auto currentNode = stack.back();
            stack.pop_back();

            resultArray.push_back(currentNode->val);
            if(currentNode->left) stack.push_back(currentNode->left);
            if(currentNode->right) stack.push_back(currentNode->right);
        }

        reverse(resultArray.begin(), resultArray.end());
        return resultArray;
    }
};