/* 653. Two Sum IV - Input is a BST */

class Solution1 {
public:
    bool findTarget(TreeNode* root, int k) {
        return searchTree(root, root, k);
    }

private:
    // This function will traverse the entire tree and, for each node, call the searchPair function.
    bool searchTree(TreeNode* current, TreeNode* root, int k) {
        if (!current) {
            return false;
        }
        
        // If we find a pair that adds up to the target value, return true.
        if (searchPair(current, root, k - current->val)) {
            return true;
        }

        // Continue searching in the left and right subtrees.
        return searchTree(current->left, root, k) || searchTree(current->right, root, k);
    }

    // This function searches for a pair that adds up to the target value using binary search.
    bool searchPair(TreeNode* current, TreeNode* node, int target) {
        if (!node) {
            return false;
        }
        
        // If the target value is found and the current node is not the root node, return true.
        if (current != node && node->val == target) {
            return true;
        }

        // If the target value is greater than the current node's value, search in the right subtree.
        // Otherwise, search in the left subtree.
        if (node->val < target) {
            return searchPair(current, node->right, target);
        } else {
            return searchPair(current, node->left, target);
        }
    }
};

class Solution2 {
public:
    // Time: O(n) && Space: O(n)
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> difference;
        return twoSum(root, k, difference);
    }

    bool twoSum(TreeNode* node, int target, unordered_set<int>& difference) {
        if(!node) return false;

        int currentDiff = target - node->val;
        if(difference.find(currentDiff) != difference.end()) {
            return true;
        } else {
            difference.insert(node->val);
        }

        bool leftSubTree = twoSum(node->left, target, difference);
        bool rightSubTree = twoSum(node->right, target, difference);

        return leftSubTree || rightSubTree;
    }
};