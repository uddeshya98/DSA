class Solution {
public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
     
        unordered_map<int, vector<int>> posMap;
        for (int i = 0; i < arr.size(); i++) {
            posMap[arr[i]].push_back(i);
        }

        vector<int> results;
        results.reserve(queries.size());

        for (const auto& query : queries) {
            int L = query[0];
            int R = query[1];
            int X = query[2];


            if (posMap.find(X) == posMap.end()) {
                results.push_back(0);
                continue;
            }

            const vector<int>& indices = posMap[X];

         
            auto it1 = lower_bound(indices.begin(), indices.end(), L);
        
            auto it2 = upper_bound(indices.begin(), indices.end(), R);

         
            results.push_back(distance(it1, it2));
        }

        return results;
    }
};