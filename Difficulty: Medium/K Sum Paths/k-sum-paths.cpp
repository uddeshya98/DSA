class Solution {
    int solve(Node* root, int currentSum, int k, unordered_map<int, int>& pathMap) {
        if (!root) return 0;
        
        currentSum += root->data;
        int count = pathMap[currentSum - k];
        
        pathMap[currentSum]++;
        
        count += solve(root->left, currentSum, k, pathMap);
        count += solve(root->right, currentSum, k, pathMap);
        
        pathMap[currentSum]--;
        
        return count;
    }
    
public:
    int countAllPaths(Node *root, int k) {
        unordered_map<int, int> pathMap;
        pathMap[0] = 1;
        return solve(root, 0, k, pathMap);
    }
};