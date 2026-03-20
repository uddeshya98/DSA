class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        while (curr != NULL) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        
        curr = root;
        while (curr != NULL) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        
        return {pre, suc};
    }
};