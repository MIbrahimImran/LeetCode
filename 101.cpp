/* 101. Symmetric Tree */

class Solution1 {
public:
    // Time: O(n) && Space: O(n)
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode *> queue{root->left, root->right};

        while(queue.size()) {
            TreeNode* leftNode = queue.back(); queue.pop_back();
            TreeNode* rightNode = queue.back(); queue.pop_back();

            if(!leftNode && !rightNode) continue;
            if(!leftNode || !rightNode) return false;
            if(leftNode->val != rightNode->val) return false;

            queue.push_front(leftNode->left);
            queue.push_front(rightNode->right);
            queue.push_front(leftNode->right);
            queue.push_front(rightNode->left);
        }

        return true;
    }
};

class Solution2 {
public:
    // Time: O(n) && Space: O(d)
    bool isSymmetric(TreeNode* root) {
        return isSymmetricH(root, root); 
    }

    bool isSymmetricH(TreeNode* node1, TreeNode* node2) {
        if(!node1 && !node2) return true;
        if(!node1 && node2 || node1 && !node2) return false;

        if(node1->val != node2->val) return false;
        bool outerSymetry = isSymmetricH(node1->left, node2->right);
        bool innterSymetry = isSymmetricH(node1->right, node2->left);
        return outerSymetry && innterSymetry;
    }
};