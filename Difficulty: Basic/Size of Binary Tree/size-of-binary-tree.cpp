/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int getSize(Node* node) {
        if(node == NULL)
            return 0;

        return 1 + getSize(node->left) + getSize(node->right);
    }
};