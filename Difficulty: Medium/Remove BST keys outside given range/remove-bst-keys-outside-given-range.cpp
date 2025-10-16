class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if (root->data < l) {
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        }
        if (root->data > r) {
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        }
        return root;
    }
};
