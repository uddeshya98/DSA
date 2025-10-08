/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    std::unordered_map<int, int> postMap;

    Node* buildTreeUtil(std::vector<int>& pre, std::vector<int>& post, int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        Node* root = new Node(pre[preStart]);

        if (preStart == preEnd) {
            return root;
        }

        int leftRootVal = pre[preStart + 1];
        int postIdx = postMap[leftRootVal];
        int leftSubtreeSize = postIdx - postStart + 1;

        root->left = buildTreeUtil(pre, post,
                                   preStart + 1, preStart + leftSubtreeSize,
                                   postStart, postIdx);

        root->right = buildTreeUtil(pre, post,
                                    preStart + leftSubtreeSize + 1, preEnd,
                                    postIdx + 1, postEnd - 1);

        return root;
    }

    Node *constructTree(std::vector<int> &pre, std::vector<int> &post) {
        int n = pre.size();
        
        for (int i = 0; i < n; ++i) {
            postMap[post[i]] = i;
        }

        return buildTreeUtil(pre, post, 0, n - 1, 0, n - 1);
    }
};