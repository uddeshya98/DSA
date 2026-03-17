class Solution {
public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        queue<Node*> q;
        Node* targetNode = nullptr;
        
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->data == target) targetNode = curr;
            
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        unordered_map<Node*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;
            
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                if (curr->left && !visited[curr->left]) {
                    flag = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                if (curr->right && !visited[curr->right]) {
                    flag = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                if (parentMap[curr] && !visited[parentMap[curr]]) {
                    flag = true;
                    visited[parentMap[curr]] = true;
                    q.push(parentMap[curr]);
                }
            }
            if (flag) time++;
        }
        
        return time;
    }
};