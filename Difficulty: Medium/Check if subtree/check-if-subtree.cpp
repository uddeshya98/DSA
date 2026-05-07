class Solution {
public:
    bool isIdentical(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->data == b->data && 
               isIdentical(a->left, b->left) && 
               isIdentical(a->right, b->right);
    }
    
    bool isSubTree(Node* T, Node* S) {
        if (!S) return true;
        if (!T) return false;
        if (isIdentical(T, S)) return true;
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};