struct Info {
    int minNode;
    int maxNode;
    int maxSize;
};

class Solution {
private:
    Info solve(Node* root) {
        if (!root) {
            return {1000000000, -1000000000, 0};
        }
        
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        if (left.maxNode < root->data && root->data < right.minNode) {
            return {std::min(root->data, left.minNode), std::max(root->data, right.maxNode), left.maxSize + right.maxSize + 1};
        }
        
        return {-1000000000, 1000000000, std::max(left.maxSize, right.maxSize)};
    }
    
public:
    int largestBst(Node *root) {
        return solve(root).maxSize;
    }
};