class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        int half = n / 2;
        queue<int> first;

        for(int i = 0; i < half; i++) {
            first.push(q.front());
            q.pop();
        }

        while(!first.empty()) {
            q.push(first.front());
            first.pop();

            q.push(q.front());
            q.pop();
        }
    }
};
