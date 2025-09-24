class SpecialQueue {
    queue<int> q;
    deque<int> minDeque, maxDeque;

public:
    void enqueue(int x) {
        q.push(x);
        while (!minDeque.empty() && minDeque.back() > x) minDeque.pop_back();
        minDeque.push_back(x);
        while (!maxDeque.empty() && maxDeque.back() < x) maxDeque.pop_back();
        maxDeque.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;
        int front = q.front();
        q.pop();
        if (!minDeque.empty() && minDeque.front() == front) minDeque.pop_front();
        if (!maxDeque.empty() && maxDeque.front() == front) maxDeque.pop_front();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minDeque.front();
    }

    int getMax() {
        return maxDeque.front();
    }
};