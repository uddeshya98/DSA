class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> primeToIndices;
        for (int j = 0; j < n; j++) {
            int val = nums[j];
            for (int p = 2; (long long)p * p <= val; p++) {
                if (val % p == 0) {
                    primeToIndices[p].push_back(j);
                    while (val % p == 0) val /= p;
                }
            }
            if (val > 1) primeToIndices[val].push_back(j);
        }

        vector<bool> visited(n, false);
        unordered_set<int> usedPrimes;

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                int cur = q.front(); q.pop();

                for (int nx : {cur - 1, cur + 1}) {
                    if (nx < 0 || nx >= n || visited[nx]) continue;
                    if (nx == n - 1) return steps;
                    visited[nx] = true;
                    q.push(nx);
                }

                if (isPrime(nums[cur]) && !usedPrimes.count(nums[cur])) {
                    int p = nums[cur];
                    usedPrimes.insert(p);
                    if (primeToIndices.count(p)) {
                        for (int j : primeToIndices[p]) {
                            if (visited[j]) continue;
                            if (j == n - 1) return steps;
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return -1;
    }
};