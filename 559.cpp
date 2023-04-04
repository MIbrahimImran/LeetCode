/* 559. Maximum Depth of N-ary Tree */

class Solution {
public:
    // Time: O(n) && Space: O(n)
    int maxDepth(Node* root) {
        if(!root) return 0;
        
        deque<Node*> queue{root};
        int depth = 0;
        while(queue.size()) {
            int queueSize = queue.size();
            while(queueSize--) {
                Node* currentNode = queue.back();
                for(Node* child : currentNode->children) {
                    queue.push_front(child);
                }
                queue.pop_back();
            }
            depth++;
        }

        return depth;
    }
};

class Solution {
public:
    // Time: O(n) && Space: O(n)
    int maxDepth(Node* node) {
        if(!node) return 0;
        
        int maxHeight = 0;
        for(auto child : node->children) {
           maxHeight = max(maxHeight, maxDepth(child));
        }

        return maxHeight + 1;
    }
};