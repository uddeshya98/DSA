class Solution {
public:
    vector<int> commonElements(vector<int> &A, vector<int> &B, vector<int> &C) {

        int n1 = A.size(), n2 = B.size(), n3 = C.size();
        int i = 0, j = 0, k = 0;
        vector<int> ans;

        while (i < n1 && j < n2 && k < n3) {

           
            if (A[i] == B[j] && B[j] == C[k]) {
                ans.push_back(A[i]);

                int val = A[i];
                
                while (i < n1 && A[i] == val) i++;
                while (j < n2 && B[j] == val) j++;
                while (k < n3 && C[k] == val) k++;
            }

            else if (A[i] < B[j]) {
                i++;
            }
            else if (B[j] < C[k]) {
                j++;
            }
            else {
                k++;
            }
        }

        if(ans.empty()) return {-1};
        return ans;
    }
};
