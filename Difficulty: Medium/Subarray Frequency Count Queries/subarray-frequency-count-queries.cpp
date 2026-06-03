class Solution {
public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < arr.size(); ++i) {
            indices[arr[i]].push_back(i);
        }
        
        vector<int> res;
        res.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], x = q[2];
            if (indices.find(x) == indices.end()) {
                res.push_back(0);
            } else {
                const auto& vec = indices[x];
                auto it1 = lower_bound(vec.begin(), vec.end(), l);
                auto it2 = upper_bound(vec.begin(), vec.end(), r);
                res.push_back(distance(it1, it2));
            }
        }
        
        return res;
    }
};