class Solution {
  public:
    struct Node {
        int data, index;
        Node* left;
        Node* right;

        Node(int d, int i) {
            data = d;
            index = i;
            left = right = NULL;
        }

        Node(Node* l, Node* r) {
            data = l->data + r->data;
            index = min(l->index, r->index);
            left = l;
            right = r;
        }
    };

    struct Compare {
        bool operator()(Node* a, Node* b) {
            if (a->data != b->data)
                return a->data > b->data;
            return a->index > b->index;
        }
    };

    void preorder(Node* root, vector<string>& ans, string curr) {
        if (!root) return;

        if (!root->left && !root->right) {
            if (curr == "") curr = "0";
            ans.push_back(curr);
            return;
        }

        preorder(root->left, ans, curr + "0");
        preorder(root->right, ans, curr + "1");
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = s.length();

        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (int i = 0; i < n; i++) {
            pq.push(new Node(f[i], i));
        }

        if (n == 1) {
            return {"0"};
        }

        while (pq.size() >= 2) {
            Node* l = pq.top(); pq.pop();
            Node* r = pq.top(); pq.pop();

            Node* newNode = new Node(l, r);
            pq.push(newNode);
        }

        Node* root = pq.top();

        vector<string> ans;
        preorder(root, ans, "");

        return ans;
    }
};